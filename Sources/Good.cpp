#include "../Headers/Good.h"


#pragma region Base Good Model Description

Good::Good(std::string name, int price) {
    _name = name;
    _price = price;
}

std::string Good::getName() {
    return _name;
}

int Good::getPrice() {
    return _price;
}

#pragma endregion

#pragma region Computer Model Description 

Computer::Computer(std::string name, int price, ComputerType type, std::string cpuName, std::string gpuName, int memSize) 
: Good(name, price) {
    cType = type;
    _cpuName = cpuName;
    _gpuName = gpuName;
    _memSize = memSize;
}

int Computer::getMemSize() {
    return _memSize;
}

std::string Computer::getCpuName() {
    return _cpuName;
}

std::string Computer::getGpuName() {
    return _gpuName;
}

std::string Computer::getType() {
    return (cType == desktop ? "Desktop" : "Laptop");
}

std::string Computer::getInfo() {
    return "Computer: " + _name + "(" + (cType == desktop ? "Desktop" : "Laptop") + "). Price: " + std::to_string(_price) +
    ". CPU: " + _cpuName + ". GPU: " + _gpuName + ". Memory Size: " + std::to_string(_memSize);
}

#pragma endregion

#pragma region Display Model Description

Display::Display(std::string name, int price, DisplayType type, std::string size, std::string resolution)
: Good(name, price) {
    _dType = type;
    _size = size;
    _resolution = resolution;
}

std::string Display::getType() {
    return (_dType == monitor ? "Monitor" : "Television");
}

std::string Display::getSize() {
    return _size;
}

std::string Display::getResolution() {
    return _resolution;
}

std::string Display::getInfo() {
    return "Display: " + _name + "(" + getType() + "). Price: " + std::to_string(_price) + ". Size: " + _size + ". Resolution: " + _resolution;
}

#pragma endregion

#pragma region Software Model Description

#pragma endregion

#pragma region Printer Model Description

#pragma endregion

#pragma region Information Storage

#pragma endregion