#include "BatteryStationFactory.h"

IEntity* BatteryStationFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("battery") == 0) {
    std::cout << "Battery Station Created" << std::endl;
    return new BatteryStation(entity);
  }
  return nullptr;
}
