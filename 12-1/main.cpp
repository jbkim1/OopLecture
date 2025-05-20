#include <iostream>
#include <string>
#include "Inventory.h"
#include "ItemGenerator.h"

int main() {
    // Create inventory object
    Inventory* inventory = new Inventory();

    // Create item objects
    Item* sword = ItemGenerator::createSword(1);
    Item* shield = ItemGenerator::createShield(1);
    Item* potion = ItemGenerator::createPotion(5);

    // Add items to each index of the inventory
    inventory->addItem(0, sword);    // Sword at index 0
    inventory->addItem(1, shield);   // Shield at index 1
    inventory->addItem(2, potion);   // Potion at index 2

    // List items in inventory
    std::cout << "Current inventory items:" << std::endl;
    inventory->listItems();

    // Remove item at index 0 (Sword)
    inventory->removeItem(0);
    std::cout << "\nAfter removing item at index 0 (Sword):" << std::endl;
    inventory->listItems();

    // Delete inventory (all items will be deleted)
    delete inventory;

    return 0;
} 