#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Good.h"

struct Item {
    int id;
    Good* good;
    int amount;
    Item(int id, Good* good, int amount);
    ~Item();
};

class Store {
    private:
    std::string _name;
    std::vector<Item*> _items;
    int _income;
    void (*_messageHandler)(std::string message);
    public:
    Store(std::string name, void (*messsageHandler)(std::string message) = nullptr);
    ~Store();

    std::string getName();
    void setName(std::string name);
    int viewIncome();

    void addItem(Good* good, int amount = int());
    void removeItem(int id);
    void supplyItem(int id, int amount);
    void buyItem(int id, int amount = 1);
    std::string viewAssortment();
    template <class T>
    std::string viewCategoryAssortment() {
        std::string result;
        for (auto it = _items.begin(); it != _items.end(); it++) {
            if (dynamic_cast<T*>((*it)->good) != nullptr) {
                result += "[" + std::to_string((*it)->id) + "] " + (*it)->good->getInfo() + ". Left: " + std::to_string((*it)->amount) + '\n';
            }
        }
        if (result.empty()) {
            result = "No items found";
        }
        result[result.size() - 1] = ' ';
        return result;
    }
};
