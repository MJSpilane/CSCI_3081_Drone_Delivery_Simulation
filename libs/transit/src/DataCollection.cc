#include "DataCollection.h"

DataCollection* DataCollection::instance = nullptr;

DataCollection::DataCollection() : csvData("data.csv") {}

DataCollection::~DataCollection() {}

DataCollection* DataCollection::getInstance() {
    if (instance == nullptr) {
        instance = new DataCollection();
    }
    return instance;
}

void DataCollection::addEntity(std::string droneName) {
    times[droneName] = 0;
}

void DataCollection::updateTime(std::string droneName, double dt) {
    times[droneName] = times[droneName] + dt;
}

void DataCollection::stopTime(std::string droneName, std::string strategyName) {
    double timeElapsed = times[droneName];
    std::string data = droneName +
    "," + strategyName + "," + std::to_string(timeElapsed);

    std::ofstream csvFile(csvData, std::ios::app);

    if (csvFile.is_open()) {
        csvFile << data << std::endl;
        csvFile.close();
    } else {
        std::cerr << "Failed to open csv file for DataCollection" << std::endl;
    }

    times[droneName] = 0;
}
