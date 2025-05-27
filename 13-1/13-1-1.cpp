#include <iostream>
#include <string>
#include <iomanip>

// ---------- Animal ���� ----------
class Animal
{
protected:
    std::string name_;

public:
    explicit Animal(const std::string& name) : name_{ name } {}
    virtual ~Animal() = default;                    // ���� �Ҹ���
    virtual void printInfo(int index) const = 0;    // �Ļ����� ����
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
            << ": " << name_ << " (" << age_ << "��)\n";
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
            << ": " << name_ << " (" << age_ << "��)\n";
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
            << ": " << name_ << " (�� " << neckLen_ << "m)\n";
    }
};

// ---------- ZooManager ----------
class ZooManager
{
    Animal* animals_[10]{};
    int      count_{ 0 };

    static int animalCount_;              // ��ü ���� ��

public:
    ZooManager() = default;
    ~ZooManager()
    {
        for (int i = 0; i < count_; ++i)
            delete animals_[i];
    }

    void addAnimal(Animal* a)
    {
        if (count_ >= 10) return;         // �ʰ� �� ����
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

    zoo.addAnimal(new Lion("Simba", 5));          // ���� 5
    zoo.addAnimal(new Penguin("Pingo", 3));       // ���� 3
    zoo.addAnimal(new Giraffe("Longneck", 6.2));  // �� ���� 6.2 m

    zoo.showAll();
    std::cout << "�� ���� ��: " << ZooManager::getAnimalCount() << '\n';
    return 0;
}
