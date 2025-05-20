#pragma once
#include "Item.h"

class Inventory {
private:
    static const int MAX_ITEMS = 10;
    Item* items[MAX_ITEMS];
    int itemCount;
public:
    Inventory();
    ~Inventory();
    void addItem(int index, Item* item); // Add item at index
    void removeItem(int index); // Remove item at index
    void listItems() const; // List all items
}; 