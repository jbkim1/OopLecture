#include <iostream>

void SampleFunc1(int* src);
int* SampleFunc2();

int main()
{
	// 동적할당(c++ 문법), malloc() <- c버전.
	// new int의 결과는 주소(할당된 메모리의 주소)
	// 정적할당 | 동적할당 <- 메모리 할당 방식의 2가지 종류.
	// int a | int* a = new int;
	// float b | float* b = new float;
	// int c[10] | int* c = new int[10];
	// 함수(영역) 종료시 유지X(메모리 소멸, 자동 소멸) | 함수(영역) 종료시 유지O(메모리 소멸X, 수동 소멸)
	// 
	// 영역 == scope
	// 영역 안에서 할당된 정적변수(메모리)는 유지되지 않는다.
	// 문법({ })은 모두 영역을 열고 닫는 문법.

	int* a = new int;
	*a = 10;
	std::cout << "a: " << a << std::endl;
	std::cout << "*a: " << *a << std::endl;

	std::cout << "=====================" << std::endl;
	SampleFunc1(a);
	std::cout << "함수 실행 후 *a: " << *a << std::endl;

	std::cout << "=====================" << std::endl;
	int* b = SampleFunc2();
	std::cout << "함수에서 생성된 b의 값: " << *b << std::endl;

	*b = 40;
	std::cout << "함수에서 생성된 b의 값 변경: " << *b << std::endl;

	// 동적 할당된 메모리를 수동으로 해제하는 방법.
	// delete를 수행하기 전까지는 동적할당된 메모리는 소명되지 않음.
	// 반드시 해주어야 하는 문법(동적할당 방식을 쓴다면)
	delete a;
	delete b;

	int* arr = new int[10];
	delete[] arr;
	// delete arr; // 0번만 삭제, 1~9번까지는 유지.
}

void SampleFunc1(int* a)
{
	*a = 20;
	std::cout << "a 변경 -> " << *a << std::endl;
}

int* SampleFunc2()
{
	int* b = new int;
	*b = 30;
	std::cout << "함수에서 b 생성: " << *b << std::endl;

	return b;
}