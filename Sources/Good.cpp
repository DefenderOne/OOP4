#include <iostream>
#include <string>
#include "../Headers/Good.h"

#pragma region Base Good Model

GoodModel::GoodModel(std::string name, double price) {
    _name = name;
    _price = price;
}

std::string GoodModel::getName() {
    return _name;
}

double GoodModel::getPrice() {
    return _price;
}

#pragma endregion


#pragma region Clothing Good Model

ClothingModel::ClothingModel(std::string name, double price, int size, std::string gender)
: GoodModel(name, price) {
    _size = size;
    _gender = gender;
}

bool ClothingModel::isFit(int size, std::string gender) {
    return _size == size && _gender == gender;
}

std::string ClothingModel::getGender() {
    return _gender;
}

int ClothingModel::getSize() {
    return _size;
}

std::string ClothingModel::getInfo() {
    return "Clothes: " + _name + ". Price: " + std::to_string(_price) + ". Size: " + std::to_string(_size) + ". Gender: " + _gender;
}

#pragma endregion


#pragma region Device Model

DeviceModel::DeviceModel(std::string name, double price, int energyConsumption, bool isAutonomous)
: GoodModel(name, price) {
    _energyConsumption = energyConsumption;
    _isAutonomous = isAutonomous;
}

int DeviceModel::getEnergyConsumption() {
    return _energyConsumption;
}

bool DeviceModel::isAutonomous() {
    return _isAutonomous;
}

std::string DeviceModel::getPowerInfo() {
    return "Energy Consumption: " + std::to_string(_energyConsumption) + " and " + (_isAutonomous ? "" : "non") + "autonomous";
}

std::string DeviceModel::getInfo() {
    return "Device: " + _name + ". Price: " + std::to_string(_price) + 
    ". Energy Consumption: " + std::to_string(_energyConsumption) +
    ". Autonomous: " + (_isAutonomous ? "yes" : "no");
}

#pragma endregion