#pragma once
#include "Item.h"

class ItemGenerator {
public:
    static Item* createSword(int count);
    static Item* createShield(int count);
    static Item* createPotion(int count);
}; 