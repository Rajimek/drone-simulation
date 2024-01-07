#ifndef HUMAN_H_
#define HUMAN_H_

#include "IEntity.h"
#include "IStrategy.h"

class Human : public IEntity {
 public:
  /**
   * @brief Drones are created with a name
   * @param obj JSON object containing the drone's information
   */
  Human(JsonObject& obj);

  /**
   * @brief Deconstructor for the Human class
   */
  ~Human();

  /**
   * @brief Updates location of the Human 
   * @param dt Delta Time
   */
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
