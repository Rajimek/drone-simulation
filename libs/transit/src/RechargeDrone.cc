#define _USE_MATH_DEFINES
#include "RechargeDrone.h"

#include <cmath>
#include <limits>

#include "BatteryDecorator.h"
#include "BeelineStrategy.h"
#include "Package.h"
#include "SimulationModel.h"

RechargeDrone::RechargeDrone(JsonObject& obj) : IEntity(obj) {
  // Bounds
  // -1400 < x < 1500
  // 240  < y < 600
  // -800  < z < 800
  int x_pos = rand() % 2900 - 1400;
  int y_pos = rand() % 360 + 240;
  int z_pos = rand() % 1600 - 800;
  toFinalDestination =
      new BeelineStrategy(this->getPosition(), Vector3(x_pos, y_pos, z_pos));

  recharging = false;
}

RechargeDrone::~RechargeDrone() {
  if (toFinalDestination) delete toFinalDestination;
  if (emptyDrone) delete emptyDrone;
}

void RechargeDrone::update(double dt) {
  // check if there are any new rechargeobserver notifications
  if (headingToRechargeStation) {
    if (!toFinalDestination->isCompleted()) {
      toFinalDestination->move(this, dt);
    } else {
      int x_pos = rand() % 2900 - 1400;
      int y_pos = rand() % 360 + 240;
      int z_pos = rand() % 1600 - 800;
      toFinalDestination = new BeelineStrategy(this->getPosition(),
                                               Vector3(x_pos, y_pos, z_pos));
      headingToRechargeStation = false;
    }
  } else {
    if (!recharging) {
      if (model->rechargeObserver->GetLength() > 0) {
        Drone* drone = model->rechargeObserver->GetDroneFromSubject();
        std::cout << "RechargeDrone recharging: " << drone->getName()
                  << std::endl;
        recharging = true;
        toFinalDestination =
            new BeelineStrategy(this->getPosition(), drone->getPosition());
        emptyDrone = drone;
      }

      // randomly fly around until a rechargeobserver notification is received
      if (!toFinalDestination->isCompleted()) {
        toFinalDestination->move(this, dt);
      } else {
        int x_pos = rand() % 2900 - 1400;
        int y_pos = rand() % 360 + 240;
        int z_pos = rand() % 1600 - 800;
        toFinalDestination = new BeelineStrategy(this->getPosition(),
                                                 Vector3(x_pos, y_pos, z_pos));
      }
    } else {
      // do work until empty drone is full
      if (!toFinalDestination->isCompleted()) {
        toFinalDestination->move(this, dt);
      } else {
        // set the battery to full
        BatteryDecorator* batteryDrone =
            dynamic_cast<BatteryDecorator*>(this->emptyDrone);
        batteryDrone->refillBattery();
        emptyDrone = nullptr;
        recharging = false;
        toFinalDestination = new BeelineStrategy(
            this->getPosition(), model->chargingPad->getPosition());
        headingToRechargeStation = true;
      }
    }
  }
}
