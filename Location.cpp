#include "Location.h"
#include "Response.h"
#include "FFOF.h"
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
    NPCone = nullptr;
    NPCtwo = nullptr;
    vector<Location*> locations;

}

void Location::canTravel() {
    vector<Location*> locationsDraft = { this->priorLocationOne, this->priorLocationTwo, this->nextLocationOne, this->nextLocationTwo, this->nextLocationThree };
    this->locations = {};
    for (int i = 0; i < locationsDraft.size(); i++) {
        if (locationsDraft.at(i) != nullptr) {
            this->locations.push_back(locationsDraft.at(i));
        }
    }
    
    for (int i = 0; i < this->locations.size(); i++) {
        cout << i + 1 << ") " << this->locations.at(i)->name << endl;
    }
    
}

void Location::listofNPCS() {
    vector<NPC*> npcs = { NPCone, NPCtwo };
    if (NPCone != nullptr || NPCtwo != nullptr) {
        cout << "\n\nA few things catch your eyes in this room:\n";
        for (int i = 0; i < npcs.size(); i++) {
            if (npcs.at(i) != nullptr) {
                cout << "-" << LocationNameSanitizer(npcs.at(i)->name) << endl;
                LineBreak();
            }
        }
    }
}

bool Location::areThereNPCS() {
    if (this->NPCone == nullptr && this->NPCtwo == nullptr) {
        return false;
    }
    else {
        return true;
    }
}



