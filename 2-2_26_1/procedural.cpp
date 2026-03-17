#include <iostream>
using namespace std;

// 최댓값을 찾는 함수
int findMax(int numbers[], int size) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

// 최솟값을 찾는 함수
int findMin(int numbers[], int size) {
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

// 입력을 받는 함수
void inputNumbers(int numbers[], int size) {
    cout << size << "개의 정수를 입력하세요: ";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
}

// 결과를 출력하는 함수
void printResult(int max, int min) {
    cout << "최댓값: " << max << endl;
    cout << "최솟값: " << min << endl;
}

int main() {
    const int SIZE = 10;
    int numbers[SIZE];

    inputNumbers(numbers, SIZE);

    int max = findMax(numbers, SIZE);
    int min = findMin(numbers, SIZE);

    printResult(max, min);

    return 0;
}
