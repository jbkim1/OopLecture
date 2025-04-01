// 실습 문제 1
#include <iostream>

class Example1 {
private:
    int value;

public:
    void setValue(int v) {
        value = v;
    }

    int doubleValue() {
        return value * 2;
    }
};

int main() {
    Example1 ex;
    ex.setValue(10);
    std::cout << "두 배 값: " << ex.doubleValue() << std::endl;
    return 0;
}

//// 실습 문제 2
//#include <iostream>
//
//class Example2 {
//public:
//    int count;
//
//    Example2() {
//        count = 0;
//    }
//
//    void callIncrement() {
//        increment();
//    }
//
//private:
//    void increment() {
//        count++;
//    }
//};
//
//int main() {
//    Example2 ex;
//    std::cout << "초기 count: " << ex.count << std::endl;
//    ex.callIncrement();
//    std::cout << "1 증가 후 count: " << ex.count << std::endl;
//    return 0;
//}
//
//// 실습 문제 3
//#include <iostream>
//#include <string>
//
//class Example3 {
//private:
//    std::string name;
//
//public:
//    void setName(std::string n) {
//        name = n;
//    }
//
//    std::string getName() {
//        return name;
//    }
//};
//
//int main() {
//    Example3 ex;
//    ex.setName("Alice");
//    std::cout << "이름: " << ex.getName() << std::endl;
//    return 0;
//}
//
//// 실습 문제 4
//#include <iostream>
//
//class Example4 {
//private:
//    int a;
//    int b;
//
//public:
//    void setNumbers(int x, int y) {
//        a = x;
//        b = y;
//    }
//
//    int getLarger() {
//        return (a > b) ? a : b;
//    }
//};
//
//int main() {
//    Example4 ex;
//    ex.setNumbers(12, 7);
//    std::cout << "큰 값: " << ex.getLarger() << std::endl;
//    return 0;
//}
//
//// 실습 문제 5
//#include <iostream>
//#include <string>
//
//class Example5 {
//private:
//    std::string message;
//
//public:
//    void setMessage(std::string m) {
//        message = m;
//    }
//
//    void printMessage() {
//        std::cout << message << std::endl;
//    }
//};
//
//int main() {
//    Example5 ex;
//    ex.setMessage("Hello, C++!");
//    ex.printMessage();
//    return 0;
//}
