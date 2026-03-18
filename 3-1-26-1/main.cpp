#include "Student.h"
#include <iostream>

int main() {
    // 기본 생성자로 객체 생성
    Student s1;
    std::cout << "=== 기본 생성자 ===" << std::endl;
    s1.printInfo();

    std::cout << std::endl;

    // 매개변수 생성자로 객체 생성
    Student s2("홍길동", 20, 3.8);
    std::cout << "=== 매개변수 생성자 ===" << std::endl;
    s2.printInfo();

    std::cout << std::endl;

    // setter로 값 변경
    s1.setName("김철수");
    s1.setAge(22);
    s1.setGpa(4.0);
    std::cout << "=== setter로 값 변경 후 ===" << std::endl;
    s1.printInfo();

    std::cout << std::endl;

    // getter로 개별 값 접근
    std::cout << "=== getter로 개별 값 접근 ===" << std::endl;
    std::cout << "이름: " << s2.getName() << std::endl;
    std::cout << "나이: " << s2.getAge() << std::endl;
    std::cout << "학점: " << s2.getGpa() << std::endl;

    return 0;
}
