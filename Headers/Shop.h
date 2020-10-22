#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Good.h"

struct Item {
    int id;
    Good* good;
    Item(int id, Good* good);
    ~Item();
};

class Store {
    private:
    std::string _name;
    std::vector<Item*> _items;
    int _income;
    public:
    Store(std::string name);
    ~Store();

    std::string getName();
    void setName(std::string name);

    void addItem(Good* good);
    void removeItem(int id);
    std::string viewAssortment();
};
