#include "Location.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Location::Location(string locationName, string locationDescription, Location* priorLocationOne, Location* priorLocationTwo) {
    this->name = locationName;
    this->description = locationDescription;
    this->numVisits = 0;
    this->priorLocationOne = priorLocationOne;
    this->priorLocationTwo = priorLocationTwo;
    this->nextLocationOne = nullptr;
    this->nextLocationTwo = nullptr;
    this->nextLocationThree = nullptr;
    this->NPCone = nullptr;
    this->NPCtwo = nullptr;

}

void Location::canTravel() {
    vector<Location*> locationsDraft = {this->priorLocationOne, this->priorLocationTwo, this->nextLocationOne, this->nextLocationTwo, this->nextLocationThree};
    vector<Location*> locations;

    for (int i = 0; i < locationsDraft.size(); i++) {
        if (locationsDraft.at(i) != nullptr) {
            locations.push_back(locationsDraft.at(i));
        }
    }

    cout << "Where do you want to go?\n";

    for (int i = 0; i < locations.size(); i++) { 
        cout << locations.at(i)->name << endl;
    } 
}

