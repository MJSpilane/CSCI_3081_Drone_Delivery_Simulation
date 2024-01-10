#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "IDroneDecorator.h"
#include "BatteryStation.h"
#include "IStrategy.h"
#include "DataCollection.h"

/**
 * @brief this class inherits from the IDroneDecorator class and represents a battery decorator to add battery functionality to drone entities.
*/
class BatteryDecorator : public IDroneDecorator {
 private:
    IStrategy* toStation = nullptr;
    DataCollection* dc = nullptr;
    double charge = 15000;
    double timeToCharge = 15;

 public:
    /**
     * @brief Construct a new Battery Decorator object
     * 
     * @param[in] drone the drone object to decorate onto
     */
    BatteryDecorator(IEntity* drone);

    /**
     * @brief Updates the drone's positition
     * 
     * @param dt delta time of the simulation
    */
    void update(double dt);

    /**
     * @brief Check if the drone needs a charge to be able to complete the current delivery
    */
    void setToStation();

   /**
     * @brief Find the closest battery station to the drone
     * 
     * @return BatteryStation* that points to the closest battery station to the drone
    */
    BatteryStation* findClosestBatteryStation();
};

#endif
