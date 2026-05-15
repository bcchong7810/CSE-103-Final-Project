#include <vector>
#include <string>

using namespace std;

#include "MainCharacter.h"
#include "Item.h"

MainCharacter::MainCharacter(string userName) {
        name = userName;
        currentLocation = nullptr;
        inventory;
        wallet = 0;
        hitPoints = 100;
        armorClass = 0;
        weaponBonus = 0;
        numberofDeaths = 0;
        emptyString = " ";
}

string MainCharacter::getName() {
    return name;
}

string MainCharacter::getLocation() {
    return "What?";
}

int MainCharacter::moneyInWallet() {
    return wallet;
}
