#pragma once
#include <string>

class Student {
private:
    std::string name;
    int age;
    double gpa;

public:
    Student();
    Student(const std::string& name, int age, double gpa);

    std::string getName() const;
    int getAge() const;
    double getGpa() const;

    void setName(const std::string& name);
    void setAge(int age);
    void setGpa(double gpa);

    void printInfo() const;
};
