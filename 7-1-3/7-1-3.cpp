#include <iostream>

// ───── 부모 클래스 ─────
class Vehicle {
protected:
    double fuel;   // 리터 단위

public:
    explicit Vehicle(double initialFuel) : fuel(initialFuel) {}

    void refuel(double amount) { fuel += amount; }
    double getFuel() const { return fuel; }
};

// ───── 자식 클래스 ─────
class Car : public Vehicle {
private:
    int passengers;

public:
    Car(double initialFuel, int numPassengers)
        : Vehicle(initialFuel), passengers(numPassengers) {}

    void drive(double consumptionPerKm, double km) {
        fuel -= consumptionPerKm * km;
        if (fuel < 0.0) fuel = 0.0;  // 음수 방지(선택적 안전장치)
    }
};

// ───── 주어진 main ─────
int main() {
    Car car(40.0, 4);          // 초기 연료 40 L, 승객 4명
    car.refuel(10.0);          // +10 L → 50 L
    car.drive(0.2, 100);       // 20 L 소비 → 30 L
    std::cout << car.getFuel() << '\n';
    return 0;
}
