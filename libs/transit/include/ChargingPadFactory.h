#ifndef CHARGING_PAD_FACTORY_H_
#define CHARING_PAD_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "ChargingPad.h"

/**
 *@brief ChargingPad Factory ot produce Charging Pads
 **/
class ChargingPadFactory : public IEntityFactory {
 public:
  /**
  * @brief Destructor for ChargingPadFactory
  **/
  virtual ~ChargingPadFactory() {}

  /**
  * @brief Creates ChargingPad using the given JSON object, if possible.
  * @param entity - JsonObject to be used to create the new ChargingPad.
  * @return ChargingPad that was created if it was created successfully, or a
  *         nullpointer if creation failed.
  **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
