#ifndef IRECHARGEOBSERVER_H
#define IRECHARGEOBSERVER_H

#include <deque>
#include <iostream>
#include <string>
#include <vector>

#include "Drone.h"
#include "math/vector3.h"

/**
 * @brief Strategy interface for recharge observer
 */
class IRechargeObserver {
 public:
  /**
   * @brief Destructor for IREchargeObserver
   **/
  virtual ~IRechargeObserver() {}

  /**
   * @brief To update the recharge drone information and add it to the program
   * @param emptyDrone Type Drone containing a pointer to a Drone that needs
   *charging
   **/
  virtual void Update(Drone* emptyDrone) = 0;
};

#endif
