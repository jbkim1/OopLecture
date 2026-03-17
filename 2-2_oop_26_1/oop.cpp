#include <iostream>
using namespace std;

class NumberAnalyzer {
private:
    int numbers[10];
    int size;
    int max;
    int min;

public:
    NumberAnalyzer(int s) : size(s), max(0), min(0) {}

    void input() {
        cout << size << "개의 정수를 입력하세요: ";
        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }
    }

    void analyze() {
        max = min = numbers[0];
        for (int i = 1; i < size; i++) {
            if (numbers[i] > max) {
                max = numbers[i];
            }
            if (numbers[i] < min) {
                min = numbers[i];
            }
        }
    }

    void printResult() {
        cout << "최댓값: " << max << endl;
        cout << "최솟값: " << min << endl;
    }
};

int main() {
    NumberAnalyzer analyzer(10);

    analyzer.input();
    analyzer.analyze();
    analyzer.printResult();

    return 0;
}
