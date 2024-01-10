#include "BatteryDecorator.h"

#include "SimulationModel.h"
#include <cfloat>
#include "BeelineStrategy.h"

BatteryDecorator::BatteryDecorator(IEntity* drone) : IDroneDecorator(drone) {
    dc = DataCollection::getInstance();
}

void BatteryDecorator::update(double dt) {
    // if we are moving to a charging station, do not decrement charge
    // drone has a battery reserve for getting to a charging station
    // when its charge runs out
    if (toStation) {
        toStation->move(drone, dt);
        dc->updateTime(drone->getName(), dt);
        // if we've made it to the station
        if (toStation->isCompleted()) {
            // and we've taken 15 dt to charge, continue on
            if (timeToCharge <= 0) {
                timeToCharge = 15;
                charge = 25000;
                delete toStation;
                toStation = nullptr;
                PathStrategy* toPackage =
                    reinterpret_cast<PathStrategy*>(drone->getToPackage());
                if (toPackage) {
                    Vector3 currPos = drone->getPosition();
                    std::vector<float> startPoint =
                        {static_cast<float>(currPos[0]),
                        static_cast<float>(currPos[1]),
                        static_cast<float>(currPos[2])};
                    drone->changeStartPoint(startPoint);
                }
            } else {
                // otherwise, wait to charge
                timeToCharge -= dt;
            }
        }
    } else if (charge <= 10) {
        // if we are out of battery, set to station strategy
        setToStation();
    } else {
        // otherwise, normal movement, determine how much charge
        // was used by distance travelled
        Vector3 originalPos = drone->getPosition();
        drone->update(dt);
        Vector3 newPos = drone->getPosition();
        double distanceTraveled = originalPos.dist(newPos);
        charge -= distanceTraveled;
    }
}

void BatteryDecorator::setToStation() {
    // set to station strategy
    Drone* droneDrone = reinterpret_cast<Drone*>(drone);
    Vector3 dronePosition = drone->getPosition();
    BatteryStation* station = findClosestBatteryStation();
    if (station) {
        Vector3 batteryPostion = station->getPosition();
        toStation = new BeelineStrategy(dronePosition, batteryPostion);
    }
}

BatteryStation* BatteryDecorator::findClosestBatteryStation() {
    double closestDist = DBL_MAX;

    std::vector<BatteryStation*> stations = model->getBatteryStations();

    BatteryStation* closest = nullptr;
    Vector3 dronePos = drone->getPosition();
    // get the station closest to the drone's position
    for (BatteryStation* station : stations) {
        Vector3 stationPos = station->getPosition();
        double distanceToStation = dronePos.dist(stationPos);
        if (distanceToStation < closestDist) {
            closest = station;
            closestDist = distanceToStation;
        }
    }
    return closest;
}
