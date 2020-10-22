#include <iostream>
#include <string>
#include "Headers/Shop.h"
#include "Headers/Good.h"

int main() {
    Store store("Parawa");
    std::cout << store.getName() << std::endl;
    store.setName("Citilink");
    store.addItem(new Computer("IBM", 25000, Computer::desktop, "Intel Core i3", "nVidia GeForce", 8192));
    store.addItem(new Display("Samsung", 5600, Display::monitor, "23.5'", "1920x1080"));
    std::cout << store.viewAssortment() << std::endl;
    store.removeItem(1);
    std::cout << store.viewAssortment() << std::endl;
}