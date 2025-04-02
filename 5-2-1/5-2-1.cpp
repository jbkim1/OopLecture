#include <iostream>

class Rectangle {
private:
    int width;
    int height;

public:
    void setSize(int w, int h) {
        width = w;
        height = h;
    }

    void printInfo() {
        std::cout << "����: " << width
            << ", ����: " << height
            << ", ����: " << width * height
            << std::endl;
    }
};

int main() {
    Rectangle rect;
    rect.setSize(3, 5);
    rect.printInfo();  // ��� ����: "����: 3, ����: 5, ����: 15"
    return 0;
}
