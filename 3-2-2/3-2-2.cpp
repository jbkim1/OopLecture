#include <iostream>

void SampleFunc(int* src);
int* SampleFunc();

int main()
{
	int* a = new int;
	*a = 10;

	std::cout << "a: " << a << std::endl;
	std::cout << "*a: " << *a << std::endl;

	std::cout << "=====================" << std::endl;
	SampleFunc(a);
	std::cout << "함수 실행 후 *a: " << *a << std::endl;

	std::cout << "=====================" << std::endl;
	int* b = SampleFunc();
	std::cout << "함수에서 생성된 b의 값: " << *b << std::endl;

	*b = 40;
	std::cout << "함수에서 생성된 b의 값 변경: " << *b << std::endl;

	delete a;
	delete b;
}

void SampleFunc(int* a)
{
	*a = 20;
	std::cout << "a 변경 -> " << *a << std::endl;
}

int* SampleFunc()
{
	int* b = new int;
	*b = 30;
	std::cout << "함수에서 b 생성: " << *b << std::endl;

	return b;
}