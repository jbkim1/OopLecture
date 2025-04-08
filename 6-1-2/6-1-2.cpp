#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int score1;
    int score2;

public:
    void setInfo(std::string n, int s1, int s2) {
        name = n;
        score1 = s1;
        score2 = s2;
    }

    std::string getName() {
        return name;
    }

    int getScore1() {
        return score1;
    }

    int getScore2() {
        return score2;
    }
};

class ScoreCalculator {
public:
    int calculateTotal(int s1, int s2) {
        return s1 + s2;
    }

    double calculateAverage(int total, int count) {
        return (double)total / count;
    }
};

int main() {
    Student s1, s2;
    ScoreCalculator calc;

    std::string name1, name2;
    int a1, a2, b1, b2;

    std::cout << "학생 1 이름과 두 과목 점수 입력: ";
    std::cin >> name1 >> a1 >> a2;

    std::cout << "학생 2 이름과 두 과목 점수 입력: ";
    std::cin >> name2 >> b1 >> b2;

    s1.setInfo(name1, a1, a2);
    s2.setInfo(name2, b1, b2);

    int total1 = calc.calculateTotal(s1.getScore1(), s1.getScore2());
    int total2 = calc.calculateTotal(s2.getScore1(), s2.getScore2());

    double avg1 = calc.calculateAverage(total1, 2);
    double avg2 = calc.calculateAverage(total2, 2);

    std::cout << "이름: " << s1.getName() << "\n총점: " << total1 << "\n평균: " << avg1 << "\n\n";
    std::cout << "이름: " << s2.getName() << "\n총점: " << total2 << "\n평균: " << avg2 << std::endl;

    return 0;
}
