#include <vector>
#include <string>
#include "Response.h"
#include "Location.h"
#include "MainCharacter.h"
#include "Item.h"
#include "FFOF.h"

using namespace std;



MainCharacter::MainCharacter(string userName) {
        name = userName;
        currentLocation = nullptr;
        inventory;
        wallet = 100;
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
    return currentLocation->name;
}

double MainCharacter::moneyInWallet() {
    return wallet;
}

void MainCharacter::arriveToLocation() {  
    cout << "You arrive at " << this->currentLocation->name << "." << endl;
    if (this->currentLocation->numVisits == 0) {
        cout << this->currentLocation->description << endl << endl;
    }
    this->currentLocation->numVisits = this->currentLocation->numVisits + 1;
    cout << "\n";
}

void MainCharacter::traverseToLocation(string locationName) {
    bool notValidLocation = true;
    string newInput = locationName;
    while (notValidLocation) {
        for (int i = 0; i < this->currentLocation->locations.size(); i++) {
            if (LocationNameSanitizer(newInput) == LocationNameSanitizer(this->currentLocation->locations.at(i)->name)) {
                this->currentLocation = this->currentLocation->locations.at(i);
                notValidLocation = false;
                break;
            } else if (newInput.length() == 1 && isdigit(newInput.at(0))) {
                if (stoi(newInput) == i + 1) {
                    this->currentLocation = this->currentLocation->locations.at(i);
                    notValidLocation = false;
                    break;
                }
            }
        }


        if (notValidLocation) {
            cout << "Please enter a valid location.\n";
            getline(cin, newInput);
            Formatting(newInput);
        }
    }
}

