#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal(), breed("unknown") {}

Dog::Dog(const std::string& name, int age, const std::string& breed)
    : Animal(name, age), breed(breed) {}

std::string Dog::getBreed() const {
    return breed;
}

void Dog::printInfo() const {
    std::cout << "[강아지] ";
    Animal::printInfo();
    std::cout << "품종: " << breed << std::endl;
}
