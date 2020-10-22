#include <iostream>
#include <string>

class GoodModel {
    protected:
    std::string _name;
    double _price;

    public:
    GoodModel(std::string name, double price = double());

    std::string getName();
    double getPrice();
    virtual std::string getInfo() = 0;
};

class ClothingModel : public GoodModel {
    private:
    int _size;
    std::string _gender;

    public:
    ClothingModel(std::string name, double price, int size, std::string gender);
    bool isFit(int size, std::string gender);
    std::string getGender();
    int getSize();
    std::string getInfo() override;
};

class DeviceModel : public GoodModel {
    private:
    bool _isAutonomous;
    int _energyConsumption;

    public:
    DeviceModel(std::string name, double price, int energyConsumption, bool isAutonomous);
    std::string getPowerInfo();
    bool isAutonomous();
    int getEnergyConsumption();
    std::string getInfo() override;
};