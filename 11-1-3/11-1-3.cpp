#include <iostream>

// ────────── Vehicle 계층 정의 ──────────
class Vehicle
{
public:
    Vehicle() { std::cout << "Vehicle 생성\n"; }
    virtual ~Vehicle() { std::cout << "Vehicle 소멸\n"; }

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
        std::cout << "Car 생성 (fuel: " << fuel << ")\n";
    }
    ~Car() override { std::cout << "Car 소멸\n"; }

    void Move(int distance) override
    {
        fuel -= distance;
        if (fuel < 0) fuel = 0;
        std::cout << "Car 이동: " << distance << "km   연료 잔량 " << fuel << '\n';
    }
    void ShowInfo() override
    {
        std::cout << "Car 정보: 연료 " << fuel << '\n';
    }
};

class ElectricCar : public Car
{
protected:
    int battery;
public:
    ElectricCar(int b) : Car(0), battery(b)
    {
        std::cout << "ElectricCar 생성 (battery: " << battery << ")\n";
    }
    ~ElectricCar() override { std::cout << "ElectricCar 소멸\n"; }

    void Move(int distance) override
    {
        battery -= distance;
        if (battery < 0) battery = 0;
        std::cout << "ElectricCar 이동: " << distance << "km   배터리 잔량 " << battery << '\n';
    }
    void ShowInfo() override
    {
        std::cout << "ElectricCar 정보: 배터리 " << battery << '\n';
    }
};

class AutonomousCar : public ElectricCar
{
public:
    AutonomousCar(int b) : ElectricCar(b)
    {
        std::cout << "AutonomousCar 생성 (battery: " << battery << ")\n";
    }
    ~AutonomousCar() override { std::cout << "AutonomousCar 소멸\n"; }

    void Move(int distance) override
    {
        battery -= distance;
        if (battery < 0) battery = 0;
        std::cout << "AutonomousCar 자율주행 이동: " << distance
            << "km   배터리 잔량 " << battery << '\n';
    }
    void ShowInfo() override
    {
        std::cout << "AutonomousCar 정보: 자율주행 모드, 배터리 " << battery << '\n';
    }
};

// ────────── main ──────────
int main()
{
    Vehicle* garage[3];
    garage[0] = new Car(50);
    garage[1] = new ElectricCar(80);
    garage[2] = new AutonomousCar(100);

    std::cout << "===== 이동 및 정보 출력 =====\n";
    for (int i = 0; i < 3; ++i)
    {
        garage[i]->Move(10);
        garage[i]->ShowInfo();
    }

    std::cout << "===== 메모리 해제 =====\n";
    for (int i = 0; i < 3; ++i)
    {
        delete garage[i];
    }
    return 0;
}
