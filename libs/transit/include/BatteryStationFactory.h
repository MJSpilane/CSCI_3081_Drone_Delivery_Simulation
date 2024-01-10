#ifndef BATTERY_STATION_FACTORY_H_
#define BATTERY_STATION_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "BatteryStation.h"

/**
 *@brief Battery station Factory to produce BatteryStation class.
 **/
class BatteryStationFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for BatteryStationFactory class.
   **/
  virtual ~BatteryStationFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
