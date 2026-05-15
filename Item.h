#ifndef ITEM__
#define ITEM__

#include <iostream>
#include <string>

class Item {
public:
    std::string name;
    std::string description;
    Item(std::string itemName, std::string itemDescription);
    int amount;
    std::string getName();
    std::string getDescription();
private:
    void useItem();

};

#endif