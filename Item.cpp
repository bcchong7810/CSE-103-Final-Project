#include <iostream>
#include <string>

#include "Item.h"

using namespace std;

Item::Item(string itemName, string itemDescription) {
    this->name = itemName;
    this->description = itemDescription;
    this->amount = 1;
}

void Item::useItem() {
    if (amount > 0) {
        amount--;
    }
}

string Item::getName() {
    return name;
}

string Item::getDescription() {
    return description;
}