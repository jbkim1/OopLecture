#include <iostream>

// �������������������� Vehicle ���� ���� ��������������������
class Vehicle
{
public:
    Vehicle() { std::cout << "Vehicle ����\n"; }
    virtual ~Vehicle() { std::cout << "Vehicle �Ҹ�\n"; }

    virtual void Move(int distance) = 0;
    virtual void ShowInfo() = 0;
};

class Car : public Vehicle
{
protected:
    int fuel;
public:
    Car(int f) : fuel(f)
    {
        std::cout << "Car ���� (fuel: " << fuel << ")\n";
    }
    ~Car() override { std::cout << "Car �Ҹ�\n"; }

    void Move(int distance) override
    {
        fuel -= distance;
        if (fuel < 0) fuel = 0;
        std::cout << "Car �̵�: " << distance << "km   ���� �ܷ� " << fuel << '\n';
    }
    void ShowInfo() override
    {
        std::cout << "Car ����: ���� " << fuel << '\n';
    }
};

class ElectricCar : public Car
{
protected:
    int battery;
public:
    ElectricCar(int b) : Car(0), battery(b)
    {
        std::cout << "ElectricCar ���� (battery: " << battery << ")\n";
    }
    ~ElectricCar() override { std::cout << "ElectricCar �Ҹ�\n"; }

    void Move(int distance) override
    {
        battery -= distance;
        if (battery < 0) battery = 0;
        std::cout << "ElectricCar �̵�: " << distance << "km   ���͸� �ܷ� " << battery << '\n';
    }
    void ShowInfo() override
    {
        std::cout << "ElectricCar ����: ���͸� " << battery << '\n';
    }
};

class AutonomousCar : public ElectricCar
{
public:
    AutonomousCar(int b) : ElectricCar(b)
    {
        std::cout << "AutonomousCar ���� (battery: " << battery << ")\n";
    }
    ~AutonomousCar() override { std::cout << "AutonomousCar �Ҹ�\n"; }

    void Move(int distance) override
    {
        battery -= distance;
        if (battery < 0) battery = 0;
        std::cout << "AutonomousCar �������� �̵�: " << distance
            << "km   ���͸� �ܷ� " << battery << '\n';
    }
    void ShowInfo() override
    {
        std::cout << "AutonomousCar ����: �������� ���, ���͸� " << battery << '\n';
    }
};

// �������������������� main ��������������������
int main()
{
    Vehicle* garage[3];
    garage[0] = new Car(50);
    garage[1] = new ElectricCar(80);
    garage[2] = new AutonomousCar(100);

    std::cout << "===== �̵� �� ���� ��� =====\n";
    for (int i = 0; i < 3; ++i)
    {
        garage[i]->Move(10);
        garage[i]->ShowInfo();
    }

    std::cout << "===== �޸� ���� =====\n";
    for (int i = 0; i < 3; ++i)
    {
        delete garage[i];
    }
    return 0;
}
