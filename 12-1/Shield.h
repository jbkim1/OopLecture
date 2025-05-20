#pragma once
#include "Item.h"

class Shield : public Item {
public:
    Shield(int count);
    void printInfo() const override;
}; 