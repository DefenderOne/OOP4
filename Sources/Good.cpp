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

Software::Software(std::string name, int price, SoftwareType sType, DistributionWay dWay, int licenseDuration)
: Good(name, price) {
    this->sType = sType;
    this->dWay = dWay;
    this->licenseDuration = licenseDuration;
}

std::string Software::getDistributionWay() {
    std::string result;
    switch (dWay)
    {
    case Software::disk:
        result = "Disk";
        break;
    case Software::licenseKey:
        result = "License Key";
        break;;
    }
    return result;
}

std::string Software::getSoftwareType() {
    std::string result;
    switch (sType)
    {
    case Software::antivirus:
        result = "Antivirus";
        break;
    case Software::office:
        result = "Office Package";
        break;
    case Software::entertainment:
        result = "Entertainment";
        break;
    case Software::creation:
        result = "Creativity";
        break;
    }
    return result;
}

int Software::getDuration() {
    return licenseDuration;
}

std::string Software::getInfo() {
    return "Software: " + _name + "(" + getSoftwareType() + "). Price: " + std::to_string(_price)
    + ". Distribution: " + getDistributionWay() + ". License Duration: " + std::to_string(licenseDuration) + " days";
}

#pragma endregion

#pragma region Printer Model Description

Printer::Printer(std::string name, int price, PrinterType pType, Color color, int speed) 
: Good(name, price) {
    this->pType = pType;
    this->color = color;
    this->speed = speed;
}

std::string Printer::getPrinterType() {
    std::string result;
    switch (pType)
    {
    case Printer::inkjet:
        result = "Inkjet";
        break;
    case Printer::laser:
        result = "Laser";
        break;
    case Printer::matrix:
        result = "Matrix";
        break;
    }
    return result;
}

std::string Printer::getColor() {
    std::string result;
    switch (color)
    {
    case Printer::blackwhite:
        result = "Black and White";
        break;
    case Printer::allcolors:
        result = "All colors";
        break;
    }
    return result;
}

int Printer::getSpeed() {
    return speed;
}

std::string Printer::getInfo() {
    return "Printer: " + _name + "(" + getPrinterType() + "). Price: " + std::to_string(_price) 
    + ". Supported colors: " + getColor() + ". Printing speed: " + std::to_string(speed) + " pages/minute";
}

#pragma endregion

#pragma region Information Storage

Storage::Storage(std::string name, int price, StorageType sType, int memSize, int readSpeed, int writeSpeed)
: Good(name, price) {
    this->sType = sType;
    this->memSize = memSize;
    this->readSpeed = readSpeed;
    this->writeSpeed = writeSpeed;
}

std::string Storage::getStorageType() {
    std::string result;
    switch (sType)
    {
    case Storage::flash:
        result = "Flash Drive";
        break;
    case Storage::hdd:
        result = "HDD";
        break;
    case Storage::sdd:
        result = "SSD";
        break;
    }
    return result;
}

int Storage::getMemorySize() {
    return memSize;
}

int Storage::getReadSpeed() {
    return readSpeed;
}

int Storage::getWriteSpeed() {
    return writeSpeed;
}

std::string Storage::getInfo() {
    return "Storage Device: " + _name + "(" + getStorageType() + "). Price: " + std::to_string(_price) 
    + ". Memory: " + std::to_string(memSize) + " MB. Write: " + std::to_string(writeSpeed) 
    + "mb/s; Read: " + std::to_string(readSpeed) + " mb/s";
}

#pragma endregion