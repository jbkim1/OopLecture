#pragma once
#include <string>

class Animal {
private:
    std::string name;
    int age;

public:
    Animal();
    Animal(const std::string& name, int age);

    std::string getName() const;
    int getAge() const;

    void printInfo() const;
};
