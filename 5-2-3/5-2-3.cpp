#include <iostream>
#include <cmath>

class Point {
private:
    int x;
    int y;

public:
    void set(int a, int b) {
        x = a;
        y = b;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    double distanceTo(Point other) {
        int dx = x - other.getX();
        int dy = y - other.getY();
        return std::sqrt(dx * dx + dy * dy);
    }
};

int main() {
    Point* p1 = new Point();
    Point* p2 = new Point();

    p1->set(0, 0);
    p2->set(3, 4);

    std::cout << "두 점 사이의 거리: " << p1->distanceTo(*p2) << std::endl;

    delete p1;
    delete p2;
    return 0;
}
