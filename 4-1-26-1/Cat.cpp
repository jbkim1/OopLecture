#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal(), isIndoor(false) {}

Cat::Cat(const std::string& name, int age, bool isIndoor)
    : Animal(name, age), isIndoor(isIndoor) {}

bool Cat::getIsIndoor() const {
    return isIndoor;
}

void Cat::printInfo() const {
    std::cout << "[고양이] ";
    Animal::printInfo();
    if (isIndoor) {
        std::cout << "실내 고양이" << std::endl;
    } else {
        std::cout << "실외 고양이" << std::endl;
    }
}
