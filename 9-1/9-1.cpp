#include <iostream>

class Parent
{
public:
    Parent()
    {
        std::cout << "Parent ������ ȣ��" << std::endl;
    }
    ~Parent()
    {
        std::cout << "Parent �Ҹ��� ȣ��" << std::endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        std::cout << "Child ������ ȣ��" << std::endl;
    }
    ~Child()
    {
        std::cout << "Child �Ҹ��� ȣ��" << std::endl;
    }
};

int main()
{
    Child c;
    return 0;
}
