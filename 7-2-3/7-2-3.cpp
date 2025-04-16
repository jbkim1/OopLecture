#include <iostream>
#include <string>

/* ───── Vehicle ───── */
class Vehicle {
protected:
    std::string model;
    int         maxSpeed;   // km/h
public:
    Vehicle(const std::string& m, int speed)
        : model(m), maxSpeed(speed) {}

    void ShowVehicle() const {
        std::cout << "[Vehicle] " << model
            << " / " << maxSpeed << "km/h" << std::endl;
    }
};

/* ───── Car ───── */
class Car : public Vehicle {
protected:
    int doorCount;
public:
    Car(const std::string& m, int speed, int doors = 4)
        : Vehicle(m, speed), doorCount(doors) {}

    void ShowCar() const {
        std::cout << "[Car] " << model
            << " / " << maxSpeed << "km/h"
            << " / " << doorCount << " doors" << std::endl;
    }
};

/* ───── SportsCar ───── */
class SportsCar : public Car {
private:
    double zeroToHundred;   // 0→100 km/h 가속(초)
public:
    SportsCar(const std::string& m, int speed,
        double accel = 3.8, int doors = 2)
        : Car(m, speed, doors), zeroToHundred(accel) {}

    void ShowSportsCar() const {
        std::cout << "[SportsCar] " << model
            << " / " << maxSpeed << "km/h"
            << " / 0‑100: " << zeroToHundred << "s" << std::endl;
    }
};

/* ───── main ───── */
int main()
{
    Vehicle* vPtr = new SportsCar("Coupe R", 320);
    SportsCar* sPtr = new SportsCar("Roadster S", 350);

    vPtr->ShowVehicle();        // ①
    // vPtr->ShowSportsCar();   // ★주석 해제 후 오류 확인

    sPtr->ShowVehicle();        // ②
    sPtr->ShowSportsCar();      // ③

    delete vPtr;
    delete sPtr;
    return 0;
}
