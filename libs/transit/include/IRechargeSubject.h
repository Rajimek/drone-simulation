#ifndef IRECHARGESUBJECT_H
#define IRECHARGESUBJECT_H

#include <iostream>
#include <string>
#include <vector>

#include "IRechargeObserver.h"

/**
 * @class IRechargeSubject
 * @brief Interface for the recharge subject's class

 */
class IRechargeSubject {
 public:
  /**
   * @brief Virtual destructor for IRechargeSubject.
   */
  virtual ~IRechargeSubject() {}

  /**
   * @brief Virtual method to attach an observer to subject
   * @param[in] observer type IRechargeObserver
   */
  virtual void Attach(IRechargeObserver *observer) = 0;
  /**
   * @brief Virtual method to remove an observer to subject
   * @param[in] observer type IRechargeObserver
   */
  virtual void Detach(IRechargeObserver *observer) = 0;

  /**
   * @brief Virtual method for notifying subscribers.
   */
  virtual void Notify() = 0;
};

#endif
