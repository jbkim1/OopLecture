#include <iostream>

// ���������� �θ� Ŭ���� ����������
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

// ���������� �ڽ� Ŭ���� ����������
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initial, double rate)
        : Account(initial), interestRate(rate) {}

    void addInterest() {
        balance += balance * interestRate;   // protected ��� ���� ���
    }
};

// ���������� �־��� main ����������
int main() {
    SavingsAccount sa(1000.0, 0.05);  // �ʱ� �ܾ� 1000, ���� 5%
    sa.deposit(500.0);                // �ܾ� 1500
    sa.addInterest();                 // 5% ���� �� 1575
    std::cout << sa.getBalance() << '\n';
    return 0;
}
