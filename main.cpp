#include <iostream>
#include <fstream>
#include <string>
#include "Headers/Shop.h"
#include "Headers/Good.h"

void messageHandler(std::string message) {
    std::ofstream reader("Resources\\log.txt", std::ios::app);
    reader << message << std::endl;
    reader.close();
}

int main() {
    std::ofstream clearer("Resources\\log.txt");
    clearer.close();
    Store store("Parawa", messageHandler);
    std::cout << store.getName() << std::endl;
    store.setName("Citilink");
    store.addItem(new Computer("IBM1", 25000, Computer::desktop, "Intel Core i3", "nVidia GeForce", 8192), 5);
    store.addItem(new Computer("IBM2", 52000, Computer::desktop, "Intel Core i7", "nVidia GeForce", 16384), 10);
    store.addItem(new Display("Samsung", 5600, Display::monitor, "23.5'", "1920x1080"), 20);
    store.supplyItem(0, 5);
    store.removeItem(2);
    std::cout << store.viewAssortment();
}