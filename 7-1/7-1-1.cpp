#include <iostream>

// ───── 부모 클래스 ─────
class Account {
protected:
    double balance;

public:
    explicit Account(double initial) : balance(initial) {}

    void deposit(double amount) {
        balance += amount;
    }
    double getBalance() const {
        return balance;
    }
};

// ───── 자식 클래스 ─────
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initial, double rate)
        : Account(initial), interestRate(rate) {}

    void addInterest() {
        balance += balance * interestRate;   // protected 멤버 직접 사용
    }
};

// ───── 주어진 main ─────
int main() {
    SavingsAccount sa(1000.0, 0.05);  // 초기 잔액 1000, 이율 5%
    sa.deposit(500.0);                // 잔액 1500
    sa.addInterest();                 // 5% 이자 → 1575
    std::cout << sa.getBalance() << '\n';
    return 0;
}
