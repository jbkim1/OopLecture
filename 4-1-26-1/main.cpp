#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>

int main() {
    // 기본 클래스 객체
    Animal a1("동물", 5);
    std::cout << "=== Animal ===" << std::endl;
    a1.printInfo();

    std::cout << std::endl;

    // 파생 클래스 Dog
    Dog d1("바둑이", 3, "진돗개");
    std::cout << "=== Dog ===" << std::endl;
    d1.printInfo();

    // 부모 클래스의 멤버 함수 사용
    std::cout << "이름(getter): " << d1.getName() << std::endl;
    std::cout << "나이(getter): " << d1.getAge() << std::endl;

    std::cout << std::endl;

    // 파생 클래스 Cat
    Cat c1("나비", 2, true);
    std::cout << "=== Cat ===" << std::endl;
    c1.printInfo();

    std::cout << std::endl;

    // 기본 생성자로 생성
    Dog d2;
    std::cout << "=== Dog 기본 생성자 ===" << std::endl;
    d2.printInfo();

    return 0;
}
