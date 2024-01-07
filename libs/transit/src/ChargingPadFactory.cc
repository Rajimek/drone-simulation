#include "ChargingPadFactory.h"

IEntity* ChargingPadFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("chargingpad") == 0) {
    std::cout << "Charging Pad Created" << std::endl;
    return new ChargingPad(entity);
  }
  return nullptr;
}
