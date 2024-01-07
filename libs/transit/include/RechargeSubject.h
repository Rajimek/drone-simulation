#ifndef RechargeSubject_H
#define RechargeSubject_H

#include <deque>
#include <iostream>
#include <list>
#include <string>

#include "IRechargeSubject.h"
#include "math/vector3.h"

/**
 * @class RechargeSubject
 * @brief Represents the recharge subject's notificiation system.
 */
class RechargeSubject : public IRechargeSubject {
 public:
  /**
   * @brief Destructor for the Recharge Subject
   */
  virtual ~RechargeSubject() {}

  /**
   * @brief Attaches a new subscriber to the list
   * @param observer type IRechargeObserve
   */
  void Attach(IRechargeObserver *observer) override {
    list_observer_.push_back(observer);
  }

  /**
   * @brief Removes subscriber from the list
   * @param observer type IRechargeObserve
   */
  void Detach(IRechargeObserver *observer) override {
    list_observer_.remove(observer);
  }

  /**
   * @brief Notifies all subjects in the list that is subscribed to the
   * notification
   */
  void Notify() override {
    std::list<IRechargeObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) {
      (*iterator)->Update(emptyDrone);
      ++iterator;
    }
  }

  /**
   * @brief Notifies subscribers of the position of the subject
   * @param position 3d Vector location
   */
  void CreateMessage(Vector3 position) {
    this->position_ = position;
    Notify();
  }

  /**
   * @brief Notifies subscribers of drone
   * @param drone emptyDrone to be sent out to subscriber
   */
  void CreateMessage(Drone *drone) {
    this->emptyDrone = drone;
    Notify();
  }

  /**
   * @brief Prints out number of subscribers in the observer list
   */
  void HowManyObserver() {
    std::cout << "There are " << list_observer_.size()
              << " observers in the list.\n";
  }

 private:
  std::list<IRechargeObserver *> list_observer_;
  Vector3 position_;
  Drone *emptyDrone;
};

#endif
