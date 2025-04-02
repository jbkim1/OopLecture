#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int score;

public:
    void setName(std::string n) {
        name = n;
    }

    std::string getName() {
        return name;
    }

    void setScore(int s) {
        score = s;
    }

    bool isPassed() {
        return score >= 60;
    }
};

int main() {
    Student s;
    s.setName("Jane");
    s.setScore(92);

    if (s.isPassed()) {
        std::cout << s.getName() << "은(는) 합격입니다." << std::endl;
    }
    else {
        std::cout << s.getName() << "은(는) 불합격입니다." << std::endl;
    }

    return 0;
}