#pragma once
#include "Item.h"

class Sword : public Item {
public:
    Sword(int count);
    void printInfo() const override;
}; 