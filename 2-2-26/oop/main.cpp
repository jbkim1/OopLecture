// ============================================================
// 객체지향(OOP) 버전
// - 데이터(numbers, max, min)와 기능(입력, 분석, 출력)을
//   하나의 클래스(NumberAnalyzer)로 묶음
// - main()은 객체를 생성하고 메서드를 호출하는 역할만 담당
// ============================================================

#include <iostream>

class NumberAnalyzer {
private:
    static const int SIZE = 10;
    int numbers[SIZE];
    int max;
    int min;

public:
    // 생성자: 초기값 설정
    NumberAnalyzer() : max(0), min(0) {}

    // 사용자로부터 숫자 입력받기
    void input() {
        std::cout << SIZE << "개의 정수를 입력하세요: ";
        for (int i = 0; i < SIZE; i++) {
            std::cin >> numbers[i];
        }
    }

    // 최댓값과 최솟값 계산
    void analyze() {
        max = min = numbers[0];
        for (int i = 1; i < SIZE; i++) {
            if (numbers[i] > max) {
                max = numbers[i];
            }
            if (numbers[i] < min) {
                min = numbers[i];
            }
        }
    }

    // 결과 출력
    void printResults() const {
        std::cout << "최댓값: " << max << std::endl;
        std::cout << "최솟값: " << min << std::endl;
    }
};

int main() {
    NumberAnalyzer analyzer;

    analyzer.input();
    analyzer.analyze();
    analyzer.printResults();

    return 0;
}
