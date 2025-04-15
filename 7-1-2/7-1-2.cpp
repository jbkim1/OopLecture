#include <iostream>

// ───── 부모 클래스 ─────
class Product {
protected:
    double price;

public:
    explicit Product(double p) : price(p) {}

    void setPrice(double p) { price = p; }
    double getPrice() const { return price; }
};

// ───── 자식 클래스 ─────
class DiscountedProduct : public Product {
private:
    double discountRate;

public:
    DiscountedProduct(double p, double rate)
        : Product(p), discountRate(rate) {}

    void applyDiscount() {
        price -= price * discountRate;   // protected 멤버 직접 사용
    }
};

// ───── 주어진 main ─────
int main() {
    DiscountedProduct dp(20000.0, 0.15); // 가격 20 000, 할인율 15 %
    dp.applyDiscount();                  // 17 000
    std::cout << dp.getPrice() << '\n';
    return 0;
}
