#pragma once
#include "Animal.h"
#include <string>

class Cat : public Animal {
private:
    bool isIndoor;

public:
    Cat();
    Cat(const std::string& name, int age, bool isIndoor);

    bool getIsIndoor() const;
    void printInfo() const;
};
