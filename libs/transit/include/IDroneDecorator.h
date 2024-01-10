#ifndef I_DRONE_DECORATOR_H_
#define I_DRONE_DECORATOR_H_

#include "IEntity.h"
#include "Drone.h"

/**
 * @brief this class inherits from the IEntity class and is intended to decorate a Drone object
*/
class IDroneDecorator : public IEntity {
 protected:
    Drone* drone = nullptr;

 public:
    /**
     * @brief Constructs a new IDroneDecorator object
     * 
     * @param[in] drone the drone entity to decorator onto
     */
    IDroneDecorator(IEntity* drone);

    /**
     * @brief Drone Decorator destructor
     */
    ~IDroneDecorator();

    /**
     * @brief Links a model to the entity
     * @param model model to be linked to the entity
     */
    void linkModel(SimulationModel* model);

    /**
     * @brief gets the position of the decorator and the Drone it decorates
    */
    Vector3 getPosition() const;

    /**
     * @brief gets the direction of the decorator and the Drone it decorates
    */
    Vector3 getDirection() const;

    /**
     * @brief gets the details of the decorator and the Drone it decorates
    */
    const JsonObject& getDetails() const;

    /**
     * @brief gets the color of the decorator and the Drone it decorates
    */
    std::string getColor() const;

    /**
     * @brief gets the color of the decorator and the Drone it decorates
    */
    std::string getName() const;

    /**
     * @brief gets the speed of the decorator and the Drone it decorates
    */
    double getSpeed() const;

    /**
     * @brief Sets the position of the entity.
     * @param pos_ The desired position of the entity.
     */
    void setPosition(Vector3 pos_);

    /**
     *@brief Set the direction of the entity.
     *@param dir_ The new direction of the entity.
     */
    void setDirection(Vector3 dir_);

    /**
     * @brief Sets the color of the entity
     * @param col_ The new color of the entity
     */
    void setColor(std::string col_);

    /**
     * @brief Pure virtual function, updates the drone's position
     * 
     * @param dt delta time of the simulation
    */
    virtual void update(double dt) = 0;
};

#endif
