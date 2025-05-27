#include <iostream>
#include <string>
#include <iomanip>

// ---------- Drink °èÃþ ----------
class Drink
{
protected:
    int         id_;
    std::string name_;

    static int nextId_;
public:
    Drink(const std::string& name) : id_{ nextId_++ }, name_{ name } {}
    virtual ~Drink() = default;
    virtual void print() const = 0;
    int getId() const { return id_; }
};
int Drink::nextId_ = 2001;

class Coffee : public Drink
{
    int shot_;
public:
    Coffee(const std::string& name, int shot)
        : Drink{ name }, shot_{ shot } {}
    void print() const override
    {
        std::cout << "ÁÖ¹® " << id_ << ": "
            << std::left << std::setw(6) << "Coffee"
            << "- " << name_ << " (¼¦ " << shot_ << ")\n";
    }
};

class Tea : public Drink
{
    std::string leafType_;
public:
    Tea(const std::string& name, const std::string& leafType)
        : Drink{ name }, leafType_{ leafType } {}
    void print() const override
    {
        std::cout << "ÁÖ¹® " << id_ << ": "
            << std::left << std::setw(6) << "Tea"
            << "- " << name_ << " (" << leafType_ << " ÀÙ)\n";
    }
};

// ---------- Cafe ----------
class Cafe
{
    Drink* orders_[5]{};
    int    count_{ 0 };

    static int orderCount_;
public:
    Cafe() = default;
    ~Cafe()
    {
        for (int i = 0; i < count_; ++i)
            delete orders_[i];
    }

    void addOrder(Drink* d)
    {
        if (count_ >= 5) return;
        orders_[count_++] = d;
        ++orderCount_;
    }

    void showOrders() const
    {
        for (int i = 0; i < count_; ++i)
            orders_[i]->print();
    }

    static int getOrderCount() { return orderCount_; }
};
int Cafe::orderCount_ = 0;

int main()
{
    Cafe cafe;
    cafe.addOrder(new Coffee("Americano", 2));
    cafe.addOrder(new Tea("Earl Grey", "EarlGrey"));

    cafe.showOrders();
    std::cout << "ÃÑ ÁÖ¹® ¼ö: " << Cafe::getOrderCount() << '\n';
    return 0;
}
