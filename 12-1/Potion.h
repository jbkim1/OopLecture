#pragma once
#include "Item.h"

class Potion : public Item {
public:
    Potion(int count);
    void printInfo() const override;
}; 