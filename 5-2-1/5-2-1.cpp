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
        std::cout << "가로: " << width
            << ", 세로: " << height
            << ", 면적: " << width * height
            << std::endl;
    }
};

int main() {
    Rectangle rect;
    rect.setSize(3, 5);
    rect.printInfo();  // 출력 예시: "가로: 3, 세로: 5, 면적: 15"
    return 0;
}
