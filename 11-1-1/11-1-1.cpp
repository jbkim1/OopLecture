#include <iostream>

// �������������������� Device ���� ���� ��������������������
class Device
{
public:
    Device() { std::cout << "Device ����\n"; }
    virtual ~Device() { std::cout << "Device �Ҹ�\n"; }

    virtual void ShowInfo()
    {
        std::cout << "�Ϲ� ����Դϴ�.\n";
    }
};

class Phone : public Device
{
public:
    Phone() { std::cout << "Phone  ����\n"; }
    ~Phone() override { std::cout << "Phone  �Ҹ�\n"; }

    void ShowInfo() override
    {
        std::cout << "��ȭ���Դϴ�.\n";
    }
};

class SmartPhone : public Phone
{
public:
    SmartPhone() { std::cout << "SmartPhone ����\n"; }
    ~SmartPhone() override { std::cout << "SmartPhone �Ҹ�\n"; }

    void ShowInfo() override
    {
        std::cout << "����Ʈ���Դϴ�.\n";
    }
};

// �������������������� main ��������������������
int main()
{
    Device* devices[3];
    devices[0] = new Device();
    devices[1] = new Phone();
    devices[2] = new SmartPhone();

    std::cout << "===== ���� ��� =====\n";
    for (int i = 0; i < 3; ++i)
    {
        devices[i]->ShowInfo();
    }

    std::cout << "===== �޸� ���� =====\n";
    for (int i = 0; i < 3; ++i)
    {
        delete devices[i];
    }
    return 0;
}
