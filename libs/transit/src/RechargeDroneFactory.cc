#include "RechargeDroneFactory.h"

IEntity* RechargeDroneFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  std::cout << "testing" << std::endl;
  if (type.compare("rechargedrone") == 0) {
    std::cout << "Recharge-Drone Created" << std::endl;
    return new RechargeDrone(entity);
  }
  return nullptr;
}
