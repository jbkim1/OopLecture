#include <iostream>

void print(std::string msg);
void print(char msg);
void print(int msg);

int main() {
    print("Hello");  // ���ڿ� ���
    print('A');      // ���� ���
    print(123);      // ���� ���
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
