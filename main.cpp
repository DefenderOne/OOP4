#include <iostream>
#include <string>
#include "Headers/Shop.h"
#include "Headers/Good.h"

int main() {
    Store store("Parawa");
    std::cout << store.getName() << std::endl;
    store.setName("Citilink");
    store.addItem(new Computer("IBM1", 25000, Computer::desktop, "Intel Core i3", "nVidia GeForce", 8192));
    store.addItem(new Computer("IBM2", 52000, Computer::desktop, "Intel Core i7", "nVidia GeForce", 16384));
    store.addItem(new Display("Samsung", 5600, Display::monitor, "23.5'", "1920x1080"));
    std::cout << store.viewCategoryAssortment<Computer>() << std::endl;
    std::cout << store.viewCategoryAssortment<Display>();
}