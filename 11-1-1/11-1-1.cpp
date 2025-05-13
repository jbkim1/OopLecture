#include <iostream>

// ────────── Device 계층 정의 ──────────
class Device
{
public:
    Device() { std::cout << "Device 생성\n"; }
    virtual ~Device() { std::cout << "Device 소멸\n"; }

    virtual void ShowInfo()
    {
        std::cout << "일반 기기입니다.\n";
    }
};

class Phone : public Device
{
public:
    Phone() { std::cout << "Phone  생성\n"; }
    ~Phone() override { std::cout << "Phone  소멸\n"; }

    void ShowInfo() override
    {
        std::cout << "전화기입니다.\n";
    }
};

class SmartPhone : public Phone
{
public:
    SmartPhone() { std::cout << "SmartPhone 생성\n"; }
    ~SmartPhone() override { std::cout << "SmartPhone 소멸\n"; }

    void ShowInfo() override
    {
        std::cout << "스마트폰입니다.\n";
    }
};

// ────────── main ──────────
int main()
{
    Device* devices[3];
    devices[0] = new Device();
    devices[1] = new Phone();
    devices[2] = new SmartPhone();

    std::cout << "===== 정보 출력 =====\n";
    for (int i = 0; i < 3; ++i)
    {
        devices[i]->ShowInfo();
    }

    std::cout << "===== 메모리 해제 =====\n";
    for (int i = 0; i < 3; ++i)
    {
        delete devices[i];
    }
    return 0;
}
