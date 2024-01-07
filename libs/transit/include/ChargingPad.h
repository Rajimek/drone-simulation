#ifndef CHARING_PAD_H_
#define CHARING_PAD_H_

#include "IEntity.h"
#include "IStrategy.h"

/**
 * @class ChargingPad
 * @brief Represents the recharge drone's charging station
 */
class ChargingPad : public IEntity {
 public:
  /**
   * @brief ChargingPad constructor
   * @param obj JSON object containing the charging pads information
   */
  ChargingPad(JsonObject& obj) : IEntity(obj) {}

  /**
   * @brief ChargingPad deconstructor
   */
  ~ChargingPad() {
    if (movement) delete movement;
  }

  /**
   * @brief Updates ChargingPads location
   * @param dt Delta time
   */
  void update(double dt) {}

 private:
  IStrategy* movement = nullptr;
};

#endif
