#include <vector>
#include <string>
#include "Response.h"
#include "Location.h"
#include "MainCharacter.h"
#include "Item.h"
#include "FFOF.h"
#include "Art.h"
using namespace std;


//MC creator
MainCharacter::MainCharacter(string userName) {
    name = userName;
    currentLocation = nullptr;
    inventory = {};
    wallet = 100;
    hitPoints = 100;
    armorClass = 0;
    weaponBonus = 0;
    numberofDeaths = 0;
    emptyString = " ";
}



void MainCharacter::arriveToLocation() { //Prompts arrival so player is not confused
    cout << "You arrive at " << this->currentLocation->name << "." << endl;
    if (this->currentLocation->numVisits == 0) {

        if (this->currentLocation->name == "THE METROPOLITAN MUSEUM OF ART") {
            ArtMuseum();
        }
        else if (this->currentLocation->name == "ANCIENT GREEK ART EXHIBIT") {
            ArtOne();
        }
        else if (this->currentLocation->name == "MEDIEVAL ART EXHIBIT") {
            ArtMedieval();
        }
        else if (this->currentLocation->name == "THE SUBWAY") {
            ArtTitle();
        }

        cout << this->currentLocation->description << endl;

    }
    this->currentLocation->numVisits = this->currentLocation->numVisits + 1;
    cout << "\n";
}

void MainCharacter::traverseToLocation(string locationName) { //Travelling through map
    string newInput = locationName;
    while (true) {
        Location* destination = nullptr;
        string cleanInput = LocationNameSanitizer(newInput);
        for (int i = 0; i < this->currentLocation->locations.size(); i++) {
            if (cleanInput == LocationNameSanitizer(this->currentLocation->locations.at(i)->name)) {
                destination = this->currentLocation->locations.at(i);
                break;
            }
            else if (newInput.length() == 1 && isdigit(newInput.at(0))) {
                if (stoi(newInput) == i + 1) {
                    destination = this->currentLocation->locations.at(i);
                    break;
                }
            }
        }


        if (destination != nullptr) {
            this->currentLocation = destination;
            break;

        }
        cout << "Please enter a valid location.\n";
        this->currentLocation->canTravel();
        Formatting(newInput);
    }
}

void MainCharacter::AddMoney(double money) {
    wallet += money;
}

void MainCharacter::SubtractMoney(double money) {
    wallet -= money;
}

double MainCharacter::moneyInWallet() {
    return wallet;
}

