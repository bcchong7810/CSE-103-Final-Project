#include "MainCharacter.h"
#include "Location.h"
#include "Item.h"
#include "LoadNewYork.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    vector<Location> newYork = LoadNewYork();
    string userName;
    cout << "What is your name young traveler? ";
    cin >> userName;
    MainCharacter MC = MainCharacter(userName);
    
    MC.currentLocation = &newYork.at(0); //START!
    cout << "You are currently in " << MC.currentLocation->name << endl;
    MC.currentLocation->canTravel();
    MC.currentLocation = MC.currentLocation->nextLocationOne;
    cout << "You are currently in " << MC.currentLocation->name << endl;
    MC.currentLocation->canTravel();
    MC.currentLocation = MC.currentLocation->nextLocationOne;
    cout << "You are currently in " << MC.currentLocation->name << endl;
    MC.currentLocation->canTravel();
    MC.currentLocation = MC.currentLocation->nextLocationOne;
    cout << "You are currently in " << MC.currentLocation->name << endl;
    MC.currentLocation->canTravel();
    MC.currentLocation = MC.currentLocation->nextLocationOne;
    cout << "You are currently in " << MC.currentLocation->name << endl;
    MC.currentLocation->canTravel();
    MC.currentLocation = MC.currentLocation->nextLocationOne;
    cout << "You are currently in " << MC.currentLocation->name << endl;
    MC.currentLocation->canTravel();
    MC.currentLocation = MC.currentLocation->nextLocationOne;
    cout << "You are currently in " << MC.currentLocation->name << endl;
    MC.currentLocation->canTravel();
    MC.currentLocation = MC.currentLocation->nextLocationOne;
    cout << "You are currently in " << MC.currentLocation->name << endl;
    MC.currentLocation->canTravel();


    //add gameLogic function/LOOP???

    cout << "Program complete!";
    system("pause > 0"); //TAKE OUT ONLY FOR TESTING AND CLEAN INPUT IN VS
}