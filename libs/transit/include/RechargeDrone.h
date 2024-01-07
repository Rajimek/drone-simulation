#ifndef RECHARGE_DRONE_H_
#define RECHARGE_DRONE_H_

#include "ChargingPad.h"
#include "IEntity.h"
#include "IStrategy.h"

/**
 * @class RechargeDrone
 * @brief Represents a RechargeDrone in the simulation
 *
 * RechargeDrone moves using euler integration based on a specified
 * velocity and direction.
 */
class RechargeDrone : public IEntity {
 public:
  /**
   * @brief RechargeDrones are created with a name
   * @param obj JSON object containing the RechargeDrone's information
   */
  RechargeDrone(JsonObject& obj);

  /**
   * @brief Destructor for RechargeDrone
   */
  ~RechargeDrone();

  /**
   * @brief Updates the RechargeDrone's position
   * @param dt Delta time
   */
  void update(double dt);

 private:
  IStrategy* toFinalDestination = nullptr;
  bool recharging = false;
  IEntity* emptyDrone;
  bool headingToRechargeStation = false;
};

#endif
