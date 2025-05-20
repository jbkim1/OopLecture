#include "Potion.h"
#include <iostream>

Potion::Potion(int count) : Item("Potion", count) {}
void Potion::printInfo() const {
    std::cout << "[Potion] x" << count << std::endl;
} 