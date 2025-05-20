#include "Shield.h"
#include <iostream>

Shield::Shield(int count) : Item("Shield", count) {}
void Shield::printInfo() const {
    std::cout << "[Shield] x" << count << std::endl;
} 