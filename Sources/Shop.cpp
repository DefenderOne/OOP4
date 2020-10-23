#include <iostream>
#include <vector>
#include "../Headers/Shop.h"

Item::Item(int id, Good* good) : id(id), good(good) {}

Item::~Item() {
    delete good;
}

Store::Store(std::string name) {
    _name = name;
}

Store::~Store() {
    for (auto it = _items.begin(); it != _items.end(); it++) {
        Item* deletedItem = *it;
        *it = nullptr;
        delete deletedItem;
    }
    _items.clear();
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
}

void Store::addItem(Good* good) {
    int id = !_items.empty() ? _items.back()->id + 1 : 0;
    Item* item = new Item(id, good);
    _items.push_back(item);
}

std::string Store::viewAssortment() {
    std::string result;
    for (auto it = _items.begin(); it != _items.end(); it++) {
        result += (*it)->good->getInfo() + '\n';
    }
    result[result.size() - 1] = ' ';
    return result;
}

void Store::removeItem(int id) {
    std::vector<Item*>::iterator deleted;
    for (auto it = _items.begin(); it != _items.end(); it++) {
        if ((*it)->id == id) {
            deleted = it;
            break;
        }
    }
    Item* deletedItem = *deleted;
    _items.erase(deleted);
    delete deletedItem;
}
