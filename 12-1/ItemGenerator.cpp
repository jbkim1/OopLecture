#include "ItemGenerator.h"
#include "Sword.h"
#include "Shield.h"
#include "Potion.h"

Item* ItemGenerator::createSword(int count) {
    return new Sword(count);
}

Item* ItemGenerator::createShield(int count) {
    return new Shield(count);
}

Item* ItemGenerator::createPotion(int count) {
    return new Potion(count);
} 