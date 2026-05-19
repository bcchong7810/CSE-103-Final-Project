#ifndef MC__
#define MC__
#include <vector>
#include <string>
#include "Location.h"
#include "Item.h"

class MainCharacter {
public:
    std::string getLocation();
    double moneyInWallet();
    MainCharacter(std::string userName);
    Location* currentLocation;
    std::string name;
    double wallet;
    std::vector<Item> inventory;
    int hitPoints;
    int armorClass;
    int weaponBonus;
    int numberofDeaths;
    std::string emptyString;
    void arriveToLocation();
    void traverseToLocation(std::string locationName);
    void AddMoney(double money);
    void SubtractMoney(double money);

};

#endif