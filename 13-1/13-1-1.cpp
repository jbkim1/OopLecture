#include <iostream>
#include <string>
#include <iomanip>

// ---------- Animal 계층 ----------
class Animal
{
protected:
    std::string name_;

public:
    explicit Animal(const std::string& name) : name_{ name } {}
    virtual ~Animal() = default;                    // 가상 소멸자
    virtual void printInfo(int index) const = 0;    // 파생에서 구현
};

class Lion : public Animal
{
    int age_;
public:
    Lion(const std::string& name, int age)
        : Animal{ name }, age_{ age } {}
    void printInfo(int index) const override
    {
        std::cout << '[' << index << "] "
            << std::left << std::setw(9) << "Lion"
            << ": " << name_ << " (" << age_ << "세)\n";
    }
};

class Penguin : public Animal
{
    int age_;
public:
    Penguin(const std::string& name, int age)
        : Animal{ name }, age_{ age } {}
    void printInfo(int index) const override
    {
        std::cout << '[' << index << "] "
            << std::left << std::setw(9) << "Penguin"
            << ": " << name_ << " (" << age_ << "세)\n";
    }
};

class Giraffe : public Animal
{
    double neckLen_;
public:
    Giraffe(const std::string& name, double neckLen)
        : Animal{ name }, neckLen_{ neckLen } {}
    void printInfo(int index) const override
    {
        std::cout << '[' << index << "] "
            << std::left << std::setw(9) << "Giraffe"
            << ": " << name_ << " (목 " << neckLen_ << "m)\n";
    }
};

// ---------- ZooManager ----------
class ZooManager
{
    Animal* animals_[10]{};
    int      count_{ 0 };

    static int animalCount_;              // 전체 동물 수

public:
    ZooManager() = default;
    ~ZooManager()
    {
        for (int i = 0; i < count_; ++i)
            delete animals_[i];
    }

    void addAnimal(Animal* a)
    {
        if (count_ >= 10) return;         // 초과 시 무시
        animals_[count_++] = a;
        ++animalCount_;
    }

    void showAll() const
    {
        for (int i = 0; i < count_; ++i)
            animals_[i]->printInfo(i + 1);
    }

    static int getAnimalCount() { return animalCount_; }
};

int ZooManager::animalCount_ = 0;

int main()
{
    ZooManager zoo;

    zoo.addAnimal(new Lion("Simba", 5));          // 나이 5
    zoo.addAnimal(new Penguin("Pingo", 3));       // 나이 3
    zoo.addAnimal(new Giraffe("Longneck", 6.2));  // 목 길이 6.2 m

    zoo.showAll();
    std::cout << "총 동물 수: " << ZooManager::getAnimalCount() << '\n';
    return 0;
}
