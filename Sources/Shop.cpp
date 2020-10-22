#include <iostream>
#include <string>
#include <vector>
#include "../Headers/Shop.h"

#pragma region Shop Item Model

ShopItem::ShopItem(int id, GoodModel* good) : _id(id) {
    _good = good;
}

ShopItem::~ShopItem() {
    delete _good;
}

std::string ShopItem::getInfo() {
    return _good->getInfo();
}

#pragma endregion

#pragma region Shop Model

Shop::Shop(std::string name) {
    _name = name;
}

std::string Shop::getName() {
    return _name;
}

void Shop::addItem(GoodModel* good) {
    int id;
    if (!_assortment.empty()) {
        id = (*_assortment.end())._id + 1;
        
    }
    else {
        id = 0;
    }
    ShopItem addedItem(id, good);
    _assortment.push_back(addedItem);
}

std::string Shop::viewAssortment() {
    std::string result;
    for (auto it = _assortment.begin(); it != _assortment.end(); it++) {
        result += (*it).getInfo() + '\n';
    }
    return result;
}

#pragma endregion