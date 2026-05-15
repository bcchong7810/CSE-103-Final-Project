#ifndef MC__
#define MC__
#include <vector>
#include <string>
#include "Location.h"
#include "Item.h"

class MainCharacter {
public:
    std::string getName();
    std::string getLocation();
    int moneyInWallet();
    MainCharacter(std::string userName);
    Location* currentLocation;
    std::string name;
    int wallet;
    std::vector<Item> inventory;
    int hitPoints;
    int armorClass;
    int weaponBonus;
    int numberofDeaths;
    std::string emptyString;


};

#endif