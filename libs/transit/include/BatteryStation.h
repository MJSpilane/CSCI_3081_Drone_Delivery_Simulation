#ifndef BATTERY_STATION_H_
#define BATTERY_STATION_H_

#include "IEntity.h"

/**
 * @class BatteryStation
 * @brief Represents a location in the simulation where 
 * drones must go to charge their battery
 */
class BatteryStation : public IEntity {
 public:
  /**
   * @brief Battery stations are created with a name
   * @param obj JSON object containing the battery station's information
   */
  BatteryStation(JsonObject& obj);

  ~BatteryStation();

  /**
   * @brief Updates the Battery Station
   * 
   * @param dt difference in time since last update
  */
  void update(double dt);
};

#endif
