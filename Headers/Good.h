#pragma once
#include <iostream>
#include <string>

class Good {
    protected:
    std::string _name;
    int _price;

    public:
    Good(std::string name, int price);
    std::string getName();
    int getPrice();
    virtual std::string getInfo() = 0;
};

#pragma region Computer Model Description 

class Computer : public Good {
    public:
    enum ComputerType {
        desktop,
        laptop
    };
    private:
    ComputerType cType;
    int _memSize;
    std::string _cpuName;
    std::string _gpuName;
    public:
    Computer(std::string name, int price, ComputerType type, std::string cpuName, std::string gpuName, int memSize);
    int getMemSize();
    std::string getCpuName();
    std::string getGpuName();
    std::string getType();
    std::string getInfo() override;
};

#pragma endregion

#pragma region Display Model Description

class Display : public Good {
    public:
    enum DisplayType {
        television,
        monitor
    };
    private:
    DisplayType _dType;
    std::string _size;
    std::string _resolution;
    public:
    Display(std::string name, int price, DisplayType dType, std::string size, std::string resolution);
    std::string getType();
    std::string getSize();
    std::string getResolution();
    std::string getInfo() override;
};

#pragma endregion

#pragma region Software Model Description

class Software : public Good {
    public:
    enum SoftwareType {
        antivirus,
        office,
        entertainment,
        creation
    };
    enum DistributionWay {
        licenseKey,
        disk
    };
    private:
    DistributionWay dWay;
    SoftwareType sType;
    int licenseDuration;

    public:
    Software(std::string name, int price, SoftwareType sType, DistributionWay dWay, int licenseDuration);
    std::string getDistributionWay();
    std::string getSoftwareType();
    int getDuration();
    std::string getInfo() override;
};

#pragma endregion

#pragma region Printer Model Description

class Printer : public Good {
    public:
    enum PrinterType {
        inkjet,
        laser,
        matrix
    };
    enum Color {
        blackwhite,
        allcolors
    };
    private:
    PrinterType pType;
    Color color;
    int speed;
    public:
    Printer(std::string name, int price, PrinterType pType, Color color, int speed);
    std::string getPrinterType();
    std::string getColor();
    int getSpeed();
    std::string getInfo() override;
};

#pragma endregion

// Undone

#pragma region Information Storage

class Storage : public Good {
    public:
    enum StorageType {
        flash,
        hdd,
        sdd
    };
    private:
    StorageType sType;
    int memSize;
    int readSpeed;
    int writeSpeed;
    public:
    Storage(std::string name, int price, StorageType sType, int memSize, int readSpeed, int writeSpeed);
    std::string getStorageType();
    int getMemorySize();
    int getReadSpeed();
    int getWriteSpeed();
    std::string getInfo() override;
};

#pragma endregion