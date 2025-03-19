#include <iostream>

void SampleFunc1(int a);
void SampleFunc2(int* a);
int* SampleFunc3();

int main()
{
	int a = 10;
	int* b = &a; // a변수의 주소 -> b변수(이 떄 변수는 포인터이어야 한다)

	std::cout << "b: " << b << std::endl;
	std::cout << "*b: " << *b << std::endl;

	std::cout << "=====================" << std::endl;
	SampleFunc1(a);
	std::cout << "함수 실행 후 a: " << a << std::endl;

	std::cout << "=====================" << std::endl;
	SampleFunc2(b);
	std::cout << "함수 실행 후 a: " << a << std::endl;

	int* d = SampleFunc3();
	std::cout << "리턴 d: " << *d << std::endl;
}

void SampleFunc1(int a)
{
	a = 20;
	std::cout << "a 변경 -> " << a << std::endl;
}

void SampleFunc2(int* a)
{
	*a = 20;
	std::cout << "a 변경 -> " << *a << std::endl;
}

int* SampleFunc3()
{
	int c = 100; // 지역변수 -> 함수가 종료되면 사라짐.
	int* d = &c;

	return d;
}