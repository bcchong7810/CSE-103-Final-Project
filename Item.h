#ifndef ITEM__
#define ITEM__

#include <iostream>
#include <string>

class Item {
public:
    std::string name;
    std::string description;
    Item(std::string itemName, std::string itemDescription);
    int amount; // changed: double to int [if the amount is use to track number of items and not money]
    std::string getName();
    std::string getDescription();
    void useItem(); // changed: from private to public [if user has access to useItem then it should be public]

};

#endif