#include <iostream>

#include "../include/menu.hpp"
int main() {
    int option;
    do {
        Menu::displayMenu();
        cin >> option;
        Menu::clearInputBuffer();
        Menu::option(option);
    } while (option != 9);

    return 0;
}