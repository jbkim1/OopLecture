#include <iostream>
#include <string>

/* ���������� Device ���������� */
class Device {
protected:
    std::string model;
    int         year;
private:
    int         price;
protected:                // �Ļ� Ŭ�������� ������ �б� ���� ��ȣ �Լ�
    int GetPrice() const { return price; }
public:
    Device(const std::string& m, int y, int p)
        : model(m), year(y), price(p) {}

    void PrintBasicSpec() const {
        std::cout << "[Device]     "
            << model << " / " << year << std::endl;
    }
};

/* ���������� PortableDevice ���������� */
class PortableDevice : public Device {
private:
    int batteryLife;          // �ð�(h)
public:
    PortableDevice(const std::string& m, int y, int p, int battery = 10)
        : Device(m, y, p), batteryLife(battery) {}

    void PrintPortableSpec() const {
        std::cout << "[Portable]   "
            << model << " / " << year << " / "
            << GetPrice() << "$ / "
            << batteryLife << "h" << std::endl;
    }
};

/* ���������� Smartphone ���������� */
class Smartphone : public PortableDevice {
private:
    std::string osName;
public:
    Smartphone(const std::string& m, int y, int p,
        const std::string& os = "Android", int battery = 10)
        : PortableDevice(m, y, p, battery), osName(os) {}

    void PrintSmartphoneSpec() const {
        std::cout << "[Smartphone] "
            << model << " / " << year << " / "
            << GetPrice() << "$" << std::endl;
    }
};

/* ���������� main ���������� */
int main()
{
    Smartphone phone("Galaxy X", 2025, 999);

    PortableDevice* pd = new Smartphone("Tab Z", 2025, 799);
    Device* dv = new Smartphone("Watch A", 2025, 399);

    phone.PrintSmartphoneSpec();  // ��
    pd->PrintPortableSpec();      // ��
    // pd->PrintSmartphoneSpec(); // ���ּ� ���� �� ���� Ȯ��
    dv->PrintBasicSpec();         // ��

    delete pd;
    delete dv;
    return 0;
}
