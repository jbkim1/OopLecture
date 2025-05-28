#include <iostream>
#include <string>
#include <vector>

class Library
{
public:
    static constexpr std::size_t MAX_BOOKS = 10;

    // å �߰� �� ���� �� true, ����(���� ��) �� false
    bool addBook(const std::string& title)
    {
        if (books_.size() >= MAX_BOOKS) { return false; }
        books_.push_back({ title, false });
        return true;
    }

    // index ��° å �뿩
    void rentBook(std::size_t index)
    {
        if (validIndex(index) && !books_[index].rented)
        {
            books_[index].rented = true;
            ++transactionCount_;
        }
    }

    // index ��° å �ݳ�
    void returnBook(std::size_t index)
    {
        if (validIndex(index) && books_[index].rented)
        {
            books_[index].rented = false;
            ++transactionCount_;
        }
    }

    // ���� ���� ���
    void printStatus() const
    {
        for (std::size_t i = 0; i < books_.size(); ++i)
        {
            std::cout << i << " : " << books_[i].title << " - "
                << (books_[i].rented ? "�뿩��" : "������") << '\n';
        }
    }

    ~Library()
    {
        std::cout << "===== ���α׷� ���� =====\n"
            << "�� �ŷ� : " << transactionCount_ << "ȸ\n";
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

// static ��� ����
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
