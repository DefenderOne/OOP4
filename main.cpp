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
    store.addItem(new Display("Samsung", 5600, Display::monitor, "23.5'", "1920x1080"), 20);
    store.removeItem(1);
    store.addItem(new Printer("Panton", 7500, Printer::laser, Printer::blackwhite, 22), 17);
    store.addItem(new Software("Avast", 7800, Software::antivirus, Software::licenseKey, 365));
    store.addItem(new Storage("Kingston", 750, Storage::flash, 8192, 100, 200), 50);
    std::cout << store.viewAssortment() << std::endl;
    store.removeItem(1);
    store.buyItem(0, 3);
    store.buyItem(0, 100);
    std::cout << store.viewIncome() << std::endl;
    system("pause");
}