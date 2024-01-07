#define _USE_MATH_DEFINES
#include "Drone.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "BfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "SpinDecorator.h"

#include "Package.h"
#include "SimulationModel.h"

Drone::Drone(JsonObject& obj) : IEntity(obj) {
  available = true;
}

Drone::~Drone() {
  if (toPackage) delete toPackage;
  if (toFinalDestination) delete toFinalDestination;
}

void Drone::getNextDelivery() {
  if (model && model->scheduledDeliveries.size() > 0) {
    package = model->scheduledDeliveries.front();
    model->scheduledDeliveries.pop_front();

    if (package) {
      available = false;
      pickedUp = false;

      Vector3 packagePosition = package->getPosition();
      Vector3 finalDestination = package->getDestination();

      toPackage = new BeelineStrategy(position, packagePosition);

      std::string strat = package->getStrategyName();
      if (strat == "astar") {
        toFinalDestination =
          new JumpDecorator(
            new AstarStrategy(
              packagePosition,
              finalDestination,
              model->getGraph()));
      } else if (strat == "dfs") {
        toFinalDestination =
          new SpinDecorator(
            new JumpDecorator(
              new DfsStrategy(
                packagePosition,
                finalDestination,
                model->getGraph())));
      } else if (strat == "bfs") {
        toFinalDestination =
          new SpinDecorator(
            new SpinDecorator(
              new BfsStrategy(
                packagePosition,
                finalDestination,
                model->getGraph())));
      } else if (strat == "dijkstra") {
        toFinalDestination =
          new JumpDecorator(
            new SpinDecorator(
              new DijkstraStrategy(
                packagePosition,
                finalDestination,
                model->getGraph())));
      } else {
        toFinalDestination = new BeelineStrategy(
          packagePosition,
          finalDestination);
      }
    }
  }
}

void Drone::update(double dt) {
  std::cout << "Drone update" << std::endl;

  if (available)
    getNextDelivery();

  if (toPackage) {
    if (!pickedUpNotified) {
      JsonObject message;
      message["command"] = "notification";
      message["value"] = "moving";
      message["id"] = this->getId();
      message["name"] = this->getName();
      model->notificationSubject->CreateMessage(message);

      pickedUpNotified = true;
    }

    toPackage->move(this, dt);

    if (toPackage->isCompleted()) {
      delete toPackage;
      toPackage = nullptr;
      pickedUp = true;

      JsonObject message;
      message["command"] = "notification";
      message["value"] = "en route";
      message["id"] = package->getId();
      message["name"] = package->getName();
      model->notificationSubject->CreateMessage(message);
    }
  } else if (toFinalDestination) {
    toFinalDestination->move(this, dt);

    if (package && pickedUp) {
      package->setPosition(position);
      package->setDirection(direction);
    }

    if (toFinalDestination->isCompleted()) {
      JsonObject message;
      message["command"] = "notification";
      message["value"] = "delivered";
      message["id"] = package->getId();
      message["name"] = package->getName();
      model->notificationSubject->CreateMessage(message);

      delete toFinalDestination;
      toFinalDestination = nullptr;
      package->handOff();
      package = nullptr;
      available = true;
      pickedUp = false;
      pickedUpNotified = false;
    }
  }
}
