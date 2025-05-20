#include "Inventory.h"
#include <iostream>

Inventory::Inventory() : itemCount(0) {
    for (int i = 0; i < MAX_ITEMS; ++i) items[i] = nullptr;
}

Inventory::~Inventory() {
    for (int i = 0; i < itemCount; ++i) {
        delete items[i];
        items[i] = nullptr;
    }
    itemCount = 0;
}

void Inventory::addItem(int index, Item* item) {
    if (index < 0 || index >= MAX_ITEMS) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    if (items[index] != nullptr) {
        delete items[index];
        items[index] = nullptr;
    } else {
        ++itemCount;
    }
    items[index] = item;
}

void Inventory::removeItem(int index) {
    if (index < 0 || index >= itemCount || items[index] == nullptr) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    delete items[index];
    items[index] = nullptr;
    --itemCount;
}

void Inventory::listItems() const {
    bool empty = true;
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (items[i] != nullptr) {
            empty = false;
            std::cout << i << ": ";
            items[i]->printInfo();
        }
    }
    if (empty) {
        std::cout << "Inventory is empty." << std::endl;
    }
} 