#include <iostream>
#include <string>
#include <vector>

class Library
{
public:
    static constexpr std::size_t MAX_BOOKS = 10;

    // 책 추가 ─ 성공 시 true, 실패(가득 참) 시 false
    bool addBook(const std::string& title)
    {
        if (books_.size() >= MAX_BOOKS) { return false; }
        books_.push_back({ title, false });
        return true;
    }

    // index 번째 책 대여
    void rentBook(std::size_t index)
    {
        if (validIndex(index) && !books_[index].rented)
        {
            books_[index].rented = true;
            ++transactionCount_;
        }
    }

    // index 번째 책 반납
    void returnBook(std::size_t index)
    {
        if (validIndex(index) && books_[index].rented)
        {
            books_[index].rented = false;
            ++transactionCount_;
        }
    }

    // 현재 상태 출력
    void printStatus() const
    {
        for (std::size_t i = 0; i < books_.size(); ++i)
        {
            std::cout << i << " : " << books_[i].title << " - "
                << (books_[i].rented ? "대여중" : "보유중") << '\n';
        }
    }

    ~Library()
    {
        std::cout << "===== 프로그램 종료 =====\n"
            << "총 거래 : " << transactionCount_ << "회\n";
    }

private:
    struct Book
    {
        std::string title;
        bool        rented;
    };

    bool validIndex(std::size_t index) const
    {
        return index < books_.size();
    }

    std::vector<Book>      books_;
    static std::size_t     transactionCount_;
};

// static 멤버 정의
std::size_t Library::transactionCount_ = 0;

int main()
{
    Library lib;
    lib.addBook("C++ Primer");
    lib.addBook("Effective Modern C++");
    lib.rentBook(1);
    lib.printStatus();
    return 0;
}
