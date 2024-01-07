#ifndef RECHARGEOBSERVER_H_
#define RECHARGEOBSERVER_H_

#include <deque>
#include <iostream>
#include <string>
#include <vector>

#include "Drone.h"
#include "IRechargeObserver.h"
#include "RechargeSubject.h"
#include "math/vector3.h"

/**
 * @class RechargeOBserver
 * @brief Notification system for recharge drone
 */
class RechargeObserver : public IRechargeObserver {
 public:
  /**
   * @brief Constructor
   * @param subject RechargeSubject contaiing subjects information
   */
  RechargeObserver(RechargeSubject* subject) : subject_(subject) {
    this->subject_->Attach(this);
    std::cout << "Hi, I'm a new RechargeObserver.\n";
  }

  /**
   * @brief Destructor for RechargeObserver
   **/
  virtual ~RechargeObserver() {
    std::cout << "Goodbye, I was the RechargeObserver \"" << this->number_
              << "\".\n";
  }

  /**
   * @brief Adds an emptyDrone to emptyDrones queue and prints out the
   * notification
   * @param emptyDrone new emptyDrone to add to list
   */
  void Update(Drone* emptyDrone) override {
    // message_from_subject_ = message_from_subject;
    this->emptyDrones.push_back(emptyDrone);
    PrintInfo();
  }

  /**
   * @brief Removes RechargeSubject from list and prints out notificaiton
   */
  void RemoveMeFromTheList() {
    subject_->Detach(this);
    std::cout << "RechargeObserver \"" << number_
              << "\" removed from the list.\n";
  }

  /**
   * @brief Prints out notification of an emptyDrone
   */
  void PrintInfo() {
    std::cout << "RechargeObserver \"" << this->number_
              << "\": a new message is available --> "
              << this->emptyDrones.back()->getName() << "\n";
  }

  /**
   * @brief Returns the first emptyDrone in the queue
   */
  Drone* GetDroneFromSubject() {
    Drone* drone = emptyDrones.front();
    emptyDrones.pop_front();
    return drone;
  }

  /**
   * @brief Gets the number of emptyDrones in the queue
   **/
  int GetLength() { return emptyDrones.size(); }

 private:
  std::deque<Drone*> emptyDrones;
  RechargeSubject* subject_;
  int number_;
};

#endif
