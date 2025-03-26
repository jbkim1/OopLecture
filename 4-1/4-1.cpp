#include <iostream>

void print(std::string msg);
void print(char msg);
void print(int msg);

int main() {
    print("Hello");  // 문자열 출력
    print('A');      // 문자 출력
    print(123);      // 정수 출력
}

void print(std::string msg)
{
    std::cout << msg << std::endl;
}

void print(char msg)
{
	std::cout << msg << std::endl;
}

void print(int msg)
{
	std::cout << msg << std::endl;
}
