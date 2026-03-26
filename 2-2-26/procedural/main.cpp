// ============================================================
// 절차지향(Procedural) 버전
// - 기능을 함수 단위로 분리하여 순서대로 호출
// - 데이터(배열)는 매개변수로 전달
// ============================================================

#include <iostream>

const int SIZE = 10;

// 배열에 정수 입력받기
void inputNumbers(int numbers[], int size) {
    std::cout << size << "개의 정수를 입력하세요: ";
    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }
}

// 배열에서 최댓값 반환
int findMax(int numbers[], int size) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

// 배열에서 최솟값 반환
int findMin(int numbers[], int size) {
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

// 결과 출력
void printResults(int max, int min) {
    std::cout << "최댓값: " << max << std::endl;
    std::cout << "최솟값: " << min << std::endl;
}

int main() {
    int numbers[SIZE];

    inputNumbers(numbers, SIZE);

    int max = findMax(numbers, SIZE);
    int min = findMin(numbers, SIZE);

    printResults(max, min);

    return 0;
}
