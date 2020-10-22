#include <iostream>
#include <string>
#include <vector>
#include "Good.h"

class ShopItem {
    private:
    GoodModel* _good;

    public:
    const int _id;
    ShopItem(int id, GoodModel* good);
    ~ShopItem();
    std::string getInfo();
};

class Shop {
    private:
    std::string _name;
    std::vector<ShopItem> _assortment;

    public:
    Shop(std::string name);
    std::string getName();
    void addItem(GoodModel* good);
    std::string viewAssortment();
};