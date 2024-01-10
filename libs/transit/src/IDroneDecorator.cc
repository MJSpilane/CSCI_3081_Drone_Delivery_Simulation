#include "IDroneDecorator.h"

IDroneDecorator::IDroneDecorator(IEntity* drone) {
    this->drone = reinterpret_cast<Drone*>(drone);
}

IDroneDecorator::~IDroneDecorator() {
    if (drone) delete drone;
}

void IDroneDecorator::linkModel(SimulationModel* model) {
    this->model = model;
    drone->linkModel(model);
}

Vector3 IDroneDecorator::getPosition() const {
    return drone->getPosition();
}

Vector3 IDroneDecorator::getDirection() const {
    return drone->getDirection();
}

const JsonObject& IDroneDecorator::getDetails() const {
    return drone->getDetails();
}

std::string IDroneDecorator::getColor() const {
    return drone->getColor();
}

std::string IDroneDecorator::getName() const {
    return drone->getName();
}

double IDroneDecorator::getSpeed() const {
    return drone->getSpeed();
}

void IDroneDecorator::setPosition(Vector3 pos_) {
    drone->setPosition(pos_);
}

void IDroneDecorator::setDirection(Vector3 dir_) {
    drone->setDirection(dir_);
}

void IDroneDecorator::setColor(std::string col_) {
    drone->setColor(col_);
}
