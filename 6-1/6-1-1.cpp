#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int score1;
    int score2;

    void input(std::string n, int s1, int s2) {
        name = n;
        score1 = s1;
        score2 = s2;
    }

    int getTotalScore() {
        return score1 + score2;
    }
};

class ScoreCalculator {
public:
    int getAverage(int total, int count) {
        return total / count;
    }
};

int main() {
    Student s1;
    Student s2;
    ScoreCalculator calc;

    std::string name1, name2;
    int s1_1, s1_2, s2_1, s2_2;

    std::cout << "학생 1 이름과 두 과목 점수 입력: ";
    std::cin >> name1 >> s1_1 >> s1_2;

    std::cout << "학생 2 이름과 두 과목 점수 입력: ";
    std::cin >> name2 >> s2_1 >> s2_2;

    s1.input(name1, s1_1, s1_2);
    s2.input(name2, s2_1, s2_2);

    int total1 = s1.getTotalScore();
    int total2 = s2.getTotalScore();

    int avg1 = calc.getAverage(total1, 2);
    int avg2 = calc.getAverage(total2, 2);

    std::cout << "이름: " << s1.name << "\n총점: " << total1 << "\n평균: " << avg1 << std::endl;
    std::cout << "이름: " << s2.name << "\n총점: " << total2 << "\n평균: " << avg2 << std::endl;

    return 0;
}
