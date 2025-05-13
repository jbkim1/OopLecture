#include <iostream>

// �������������������� Shape ���� ���� ��������������������
class Shape
{
public:
    Shape() { std::cout << "Shape ����\n"; }
    virtual ~Shape() { std::cout << "Shape �Ҹ�\n"; }

    virtual void ShowInfo()
    {
        std::cout << "�����Դϴ�.\n";
    }
    virtual double Area() { return 0.0; }
};

class Rectangle : public Shape
{
protected:
    double w;
    double h;
public:
    Rectangle(double w_, double h_) : w(w_), h(h_) { std::cout << "Rectangle ����\n"; }
    ~Rectangle() override { std::cout << "Rectangle �Ҹ�\n"; }

    void ShowInfo() override
    {
        std::cout << "�簢���Դϴ�.\n";
    }
    double Area() override
    {
        return w * h;
    }
};

class Box : public Rectangle
{
private:
    double d;
public:
    Box(double w_, double h_, double d_) : Rectangle(w_, h_), d(d_)
    {
        std::cout << "Box ����\n";
    }
    ~Box() override { std::cout << "Box �Ҹ�\n"; }

    void ShowInfo() override
    {
        std::cout << "������ü�Դϴ�.\n";
    }
    double Area() override
    {
        return 2.0 * (w * h + w * d + h * d);
    }
};

// �������������������� main ��������������������
int main()
{
    Shape* shapes[3];
    shapes[0] = new Shape();
    shapes[1] = new Rectangle(3.0, 4.0);
    shapes[2] = new Box(3.0, 4.0, 5.0);

    std::cout << "===== ���� ��� =====\n";
    for (int i = 0; i < 3; ++i)
    {
        shapes[i]->ShowInfo();
        std::cout << "Area: " << shapes[i]->Area() << '\n';
    }

    std::cout << "===== �޸� ���� =====\n";
    for (int i = 0; i < 3; ++i)
    {
        delete shapes[i];
    }
    return 0;
}
