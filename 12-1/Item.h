#pragma once
#include <string>

class Item {
protected:
    std::string name;
    int count;
public:
    Item(const std::string& name, int count);
    virtual ~Item();
    virtual std::string getName() const;
    virtual int getCount() const;
    virtual void setCount(int c);
    virtual void printInfo() const = 0;
}; 