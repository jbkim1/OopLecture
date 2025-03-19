#include <iostream>

void SampleFunc(int src);
void SampleFunc(int* src);

int main()
{
	int a = 10;
	int* b = &a;

	std::cout << "b: " << b << std::endl;
	std::cout << "*b: " << *b << std::endl;

	std::cout << "=====================" << std::endl;
	SampleFunc(a);
	std::cout << "함수 실행 후 a: " << a << std::endl;

	std::cout << "=====================" << std::endl;
	SampleFunc(&a);
	std::cout << "함수 실행 후 a: " << a << std::endl;
}

void SampleFunc(int a)
{
	a = 20;
	std::cout << "a 변경 -> " << a << std::endl;
}

void SampleFunc(int* a)
{
	*a = 20;
	std::cout << "a 변경 -> " << *a << std::endl;
}