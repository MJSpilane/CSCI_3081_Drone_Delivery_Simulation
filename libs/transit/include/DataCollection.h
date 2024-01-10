#ifndef DATACOLLECTION_H_
#define DATACOLLECTION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

/**
 * @brief Singleton class that will collect data from
 * tests to see effiecency of package deliveries based
 * off number of battery stations and stategies
 **/
class DataCollection {
 private:
  /**
   * @brief singleton instance
   */
  static DataCollection* instance;

  /**
   * @brief csv storing all data
   */
  std::string csvData;

  /**
   * @brief data structure to keep track of all entity times
  */
  std::unordered_map<std::string, double> times;

  /**
   * @brief DataCollection constructor
   **/
  DataCollection();

  /**
   * @brief DataCollection destructor
   **/
  ~DataCollection();

 public:
  /**
   * @brief gets instance of singleton or creates it if it does not exist yet
   * @return static DataCollection* that points to singleton instance
   **/
  static DataCollection* getInstance();

  /**
   * @brief adds drone entity to map to keep track of delivery times
   * @param droneName represents the name of the drone
  */
  void addEntity(std::string droneName);

  /**
   * @brief starts the timing of a delivery when the delivery is recieved
   * @param droneName name of the drone we are updating
   * @param dt double representing time to be updated
  */
  void updateTime(std::string droneName, double dt);

  /**
   * @brief starts the timing of a delivery when the delivery is recieved
   * @param droneName name of the drone we are updating
   * @param strategyName name of strategy currently being used
  */
  void stopTime(std::string droneName, std::string strategyName);
};

#endif
