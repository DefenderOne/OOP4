#include <iostream>
#include <vector>
#include "../Headers/Shop.h"

Item::Item(int id, Good* good, int amount) {
    this->id = id;
    this->good = good;
    this->amount = amount;
}

Item::~Item() {
    delete good;
}

Store::Store(std::string name, void (*messsageHandler)(std::string message)) {
    _name = name;
    _messageHandler = messsageHandler;
    _messageHandler("Store created with name " + _name);
}

Store::~Store() {
    for (auto it = _items.begin(); it != _items.end(); it++) {
        Item* deletedItem = *it;
        *it = nullptr;
        delete deletedItem;
    }
    _items.clear();
    _messageHandler("Store " + _name + " deleted");
}

std::string Store::getName() {
    return _name;
}

void Store::setName(std::string name) {
    if (!name.empty()) {
        _name = name;
    }
    else {
        _name = "Unknown";
    }
    _income = 0;
    _messageHandler("Name changed to " + _name);
}

int Store::viewIncome() {
    _messageHandler("Store income was requested and is " + std::to_string(_income));
    return _income;
}

void Store::addItem(Good* good, int amount) {
    int id = !_items.empty() ? _items.back()->id + 1 : 0;
    Item* item = new Item(id, good, amount);
    _items.push_back(item);
    _messageHandler("Added new item: " + item->good->getName() + " with ID " + std::to_string(item->id));
}

void Store::supplyItem(int id, int amount) {
    if (amount > 0) {
        for (auto it = _items.begin(); it != _items.end(); it++) {
            if ((*it)->id == id) {
                (*it)->amount += amount;
                _messageHandler("Item [" + std::to_string((*it)->id) + "] " + (*it)->good->getName() 
                + " supplied by " + std::to_string(amount));
            }
        }
    }
    
}

void Store::buyItem(int id, int amount) {
    for (auto it = _items.begin(); it != _items.end(); it++) {
        if ((*it)->id == id && (*it)->amount >= amount) {
            _income += (*it)->good->getPrice() * amount;
            (*it)->amount -= amount;
            _messageHandler(std::to_string(amount) + " item(s) [" + std::to_string((*it)->id) + "] " + (*it)->good->getName() 
                + " bought on " + std::to_string((*it)->good->getPrice() * amount));
        }
    }
}

std::string Store::viewAssortment() {
    std::string result;
    for (auto it = _items.begin(); it != _items.end(); it++) {
        result += "[" + std::to_string((*it)->id) + "] " + (*it)->good->getInfo() + ". Left: " + std::to_string((*it)->amount) + '\n';
    }
    result[result.size() - 1] = ' ';
    return result;
}

void Store::removeItem(int id) {
    std::vector<Item*>::iterator deleted;
    for (auto it = _items.begin(); it != _items.end(); it++) {
        if ((*it)->id == id) {
            _messageHandler("Item [" + std::to_string((*it)->id) + "] " + (*it)->good->getName() + " removed");
            Item* deletedItem = *it;
            *it = nullptr;
            delete deletedItem;
            _items.erase(it);
            break;
        }
    }
}
