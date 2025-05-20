#include "Item.h"

Item::Item(const std::string& name, int count) : name(name), count(count) {}
Item::~Item() {}
std::string Item::getName() const { return name; }
int Item::getCount() const { return count; }
void Item::setCount(int c) { count = c; } 