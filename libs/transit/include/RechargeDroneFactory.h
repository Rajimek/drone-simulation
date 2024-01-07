#ifndef RECHARGE_DRONE_FACTORY_H_
#define RECHARGE_DRONE_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "RechargeDrone.h"

/**
 *@brief Recharge Drone Factory to produce Recharge Drone Class
 **/
class RechargeDroneFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for RechargeDroneFactory class.
   **/
  virtual ~RechargeDroneFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
