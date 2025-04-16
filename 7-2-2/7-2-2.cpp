#include <iostream>
#include <string>

/* ───── Employee ───── */
class Employee {
protected:
    std::string name;
private:
    int         salary;
protected:                // 파생 클래스용 접근 함수
    int GetSalary() const { return salary; }
public:
    Employee(const std::string& n, int s)
        : name(n), salary(s) {}

    void ShowEmployeeInfo() const {
        std::cout << "[Employee] " << name
            << " / " << GetSalary() << "$" << std::endl;
    }
};

/* ───── Manager ───── */
class Manager : public Employee {
protected:
    int teamSize;
    int CalcBonus() const {               // protected
        return GetSalary() * 15 / 100;    // 15 % 보너스
    }
public:
    Manager(const std::string& n, int s, int team = 5)
        : Employee(n, s), teamSize(team) {}

    void ShowManagerInfo() const {
        std::cout << "[Manager ] " << name
            << " / " << GetSalary() << "$"
            << " / Bonus: " << CalcBonus() << "$" << std::endl;
    }
};

/* ───── Director ───── */
class Director : public Manager {
private:
    std::string companyCar;
public:
    Director(const std::string& n, int s,
        int team = 10, const std::string& car = "Sedan")
        : Manager(n, s, team), companyCar(car) {}

    void ShowDirectorInfo() const {
        std::cout << "[Director] " << name
            << " / " << GetSalary() << "$"
            << " / Bonus: " << CalcBonus()
            << "$ / Car: " << companyCar << std::endl;
    }
};

/* ───── main ───── */
int main()
{
    Director ceo("Alice", 150000);
    Manager* mgr = new Director("Bob", 120000);
    Employee* emp = new Director("Carol", 90000);

    ceo.ShowDirectorInfo();  // ①
    mgr->ShowManagerInfo();  // ②
    // mgr->ShowDirectorInfo(); // ★주석 해제 후 오류 확인
    emp->ShowEmployeeInfo(); // ③

    delete mgr;
    delete emp;
    return 0;
}
