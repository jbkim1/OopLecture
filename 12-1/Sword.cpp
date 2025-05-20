#include "Sword.h"
#include <iostream>

Sword::Sword(int count) : Item("Sword", count) {}
void Sword::printInfo() const {
    std::cout << "[Sword] x" << count << std::endl;
} 