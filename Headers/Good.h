#include <string>

// Abstract class for all types of goods
class GoodModel {
    protected:
    std::string _name;
    int _price;
    double _weight;

    public:
    GoodModel(std::string name, int price, double weight = double());

    bool SetPrice(int value);
    bool SetName(std::string name);

    bool GetPrice();
    bool GetName();

    virtual std::string GetInfo() = 0;
};

// Food model derived from good model
class FoodModel : public GoodModel {
    private:
    int _calories;
    int _fatLevel;
    int _carbohydrateLevel;
    int _proteinLevel;
    public:
    FoodModel(std::string name, int price, double weight, int calories, int fatLevel, int carbohydrateLevel, int proteinLevel);
    std::string GetNutritionInfo();
    std::string GetInfo() override;
};


class DeviceModel : public GoodModel {
    private:
    bool _isAutonomous;
    int _energyConsumption;
    std::string _usage;
    
    public:
    DeviceModel(std::string name, int price, double weight, bool isAutonomous, int energyConsumption, std::string usage);
    std::string GetPowerUnitInfo();
    std::string GetInfo() override;
};

// Chemistry model derived from good model
class ChemistryModel : public GoodModel {

};

class ServiceModel : public GoodModel {

};

class BuildingMaterialModel : public GoodModel {

};
