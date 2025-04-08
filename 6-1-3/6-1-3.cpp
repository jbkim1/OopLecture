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
    int calculateTotalFromStudent(Student student) {
        return student.getScore1() + student.getScore2();
    }

    double calculateAverage(int total, int count) {
        return (double)total / count;
    }

    int getHighestScore(int a, int b, int c) {
        if (a >= b && a >= c) return a;
        if (b >= a && b >= c) return b;
        return c;
    }
};

int main() {
    Student s1, s2, s3;
    ScoreCalculator calc;

    std::string n1, n2, n3;
    int a1, a2, b1, b2, c1, c2;

    std::cout << "학생 1 이름과 두 과목 점수 입력: ";
    std::cin >> n1 >> a1 >> a2;
    s1.setInfo(n1, a1, a2);

    std::cout << "학생 2 이름과 두 과목 점수 입력: ";
    std::cin >> n2 >> b1 >> b2;
    s2.setInfo(n2, b1, b2);

    std::cout << "학생 3 이름과 두 과목 점수 입력: ";
    std::cin >> n3 >> c1 >> c2;
    s3.setInfo(n3, c1, c2);

    int total1 = calc.calculateTotalFromStudent(s1);
    int total2 = calc.calculateTotalFromStudent(s2);
    int total3 = calc.calculateTotalFromStudent(s3);

    double avg1 = calc.calculateAverage(total1, 2);
    double avg2 = calc.calculateAverage(total2, 2);
    double avg3 = calc.calculateAverage(total3, 2);

    int highest = calc.getHighestScore(total1, total2, total3);

    std::cout << "이름: " << s1.getName() << " 총점: " << total1 << " 평균: " << avg1 << std::endl;
    std::cout << "이름: " << s2.getName() << " 총점: " << total2 << " 평균: " << avg2 << std::endl;
    std::cout << "이름: " << s3.getName() << " 총점: " << total3 << " 평균: " << avg3 << std::endl;

    std::cout << "\n세 학생 중 최고 총점: " << highest << std::endl;

    return 0;
}
