#ifndef BATERRY_DECORATOR_H_
#define BATERRY_DECORATOR_H_

#include "Drone.h"
#include "Package.h"
#include "SimulationModel.h"

/**
 * @class BatteryDecorator
 * @brief Wraps Battery Level of Drone
 */
class BatteryDecorator : public Drone {
 public:
  /**
   * @brief Constructor defaulting with battery level = 100
   * @param details type JsonObject representing Drone info
   */
  BatteryDecorator(JsonObject& details) : Drone(details) {
    this->battery = 100;
  }

  /**
   * @brief Destructor for BatteryDecorator
   **/
  ~BatteryDecorator() {}

        /**
        * @brief Drain battery level over time, update drone position and set 
        * notifications
        * @param dt type double representing delta time
        **/
        void update(double dt) {
            if (battery <= 0) {
                batteryEmpty = true;
                battery = 0;
                // call recharge observer
                if (!emptyNotified) {
                    emptyNotified = true;
                    model->rechargeSubject->CreateMessage(this);

                    // Create JsonObject for Drone empty notification
                    JsonObject message;
                    message["command"] = "notification";
                    message["value"] = "empty";
                    message["id"] = this->getId();
                    message["name"] = this->getName();
                    model->notificationSubject->CreateMessage(message);
                }
                return;
            } else {
                battery -= 0.05;
                std::cout << "Battery: " << battery << std::endl;
            }
            if (available)
                getNextDelivery();

            if (toPackage) {
                if (!pickedUpNotified) {
                    // Create JsonObject for Drone moving
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

                    // Create JsonObject for Drone picked up package
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
                    // Create JsonObject for Drone delivered package
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
    /**
    * @brief Recharge drone battery by setting level to 100
    **/
    void refillBattery() {
        battery = 100;
        batteryEmpty = false;
        emptyNotified = false;

        // Create JsonObject for Drone empty notification
        JsonObject message;
        message["command"] = "notification";
        message["value"] = "recharged";
        message["id"] = this->getId();
        message["name"] = this->getName();
        model->notificationSubject->CreateMessage(message);
    }

 private:
  double battery = 0;
  bool batteryEmpty = false;
  bool emptyNotified = false;
};

#endif
