#include "Animal.h"
#include <iostream>

Animal::Animal() : name("unknown"), age(0) {}

Animal::Animal(const std::string& name, int age)
    : name(name), age(age) {}

std::string Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

void Animal::printInfo() const {
    std::cout << "이름: " << name << ", 나이: " << age << "살" << std::endl;
}
