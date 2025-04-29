#include <iostream>

class Parent
{
public:
    Parent()
    {
        std::cout << "Parent 생성자 호출" << std::endl;
    }
    ~Parent()
    {
        std::cout << "Parent 소멸자 호출" << std::endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        std::cout << "Child 생성자 호출" << std::endl;
    }
    ~Child()
    {
        std::cout << "Child 소멸자 호출" << std::endl;
    }
};

int main()
{
    Child c;
    return 0;
}
