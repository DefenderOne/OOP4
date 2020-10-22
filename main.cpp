#include <iostream>
#include "Headers/Shop.h"

int main() {
    Shop store("Bazinga");
    std::cout << store.getName() << std::endl;
    store.addItem(new ClothingModel("Jacket", 500, 52, "M"));
    std::cout << store.viewAssortment() << std::endl;
    //store.addItem(new DeviceModel("Drill", 2500, 50, false));
    //std::cout << store.viewAssortment() << std::endl;
    system("pause");
}