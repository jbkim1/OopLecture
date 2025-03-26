#include <iostream>

// 실습 1
int square(int x) {
    return x * x;
}

double square(double x) {
    return x * x;
}

int main() {
    std::cout << square(5) << std::endl;
    std::cout << square(2.5) << std::endl;
    return 0;
}

//// 실습 2
//#include <iostream>
//
//int multiply(int a, int b) {
//    return a * b;
//}
//
//int multiply(int a, int b, int c) {
//    return a * b * c;
//}
//
//int main() {
//    std::cout << multiply(2, 3) << std::endl;
//    std::cout << multiply(2, 3, 4) << std::endl;
//    return 0;
//}
//
//// 실습 3
//#include <iostream>
//
//void printValue(int value) {
//    std::cout << "int: " << value << std::endl;
//}
//
//void printValue(char value) {
//    std::cout << "char: " << value << std::endl;
//}
//
//int main() {
//    printValue(42);
//    printValue('A');
//    return 0;
//}
//
//
//// 실습 4
//#include <iostream>
//
//void display(int x, char c) {
//    std::cout << "int: " << x << ", char: " << c << std::endl;
//}
//
//void display(float f, bool b) {
//    std::cout << "float: " << f << ", bool: " << std::boolalpha << b << std::endl;
//}
//
//int main() {
//    display(7, 'Z');
//    display(3.14f, false);
//    return 0;
//}
//
//// 실습 5
//#include <iostream>
//#include <string>
//
//void logData(int id, float value) {
//    std::cout << "[INT, FLOAT] id: " << id << ", value: " << value << std::endl;
//}
//
//void logData(char code, std::string msg, bool flag) {
//    std::cout << "[CHAR, STRING, BOOL] code: " << code
//        << ", msg: " << msg
//        << ", flag: " << std::boolalpha << flag << std::endl;
//}
//
//int main() {
//    logData(1001, 98.6f);
//    logData('E', "Engine Overheat", true);
//    return 0;
//}
