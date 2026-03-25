#pragma once
#include "Animal.h"
#include <string>

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog();
    Dog(const std::string& name, int age, const std::string& breed);

    std::string getBreed() const;
    void printInfo() const;
};
