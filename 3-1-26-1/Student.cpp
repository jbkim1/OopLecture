#include "Student.h"
#include <iostream>

Student::Student() : name("unknown"), age(0), gpa(0.0) {}

Student::Student(const std::string& name, int age, double gpa)
    : name(name), age(age), gpa(gpa) {}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

double Student::getGpa() const {
    return gpa;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setGpa(double gpa) {
    this->gpa = gpa;
}

void Student::printInfo() const {
    std::cout << "이름: " << name << std::endl;
    std::cout << "나이: " << age << std::endl;
    std::cout << "학점: " << gpa << std::endl;
}
