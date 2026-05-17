#include "MainCharacter.h" //Needed for character creation
#include "Location.h" //probably only needed for the test
#include "Item.h"//probably only needed for the test
#include "LoadNewYork.h" //Bring in load map
#include "minigames.h" //probably only needed for the test
#include "Introduction.h" 
#include "Response.h"
#include "FFOF.h"
#include "Art.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {  
    //Loading maps...
    vector<Location*> NYC = LoadNewYork();
    
    /*
    //Character creation...
    string userName;
    userName = Introduction();
    */
    string userResponse;
    string userName; //DELETE for Final
    

    
    userName = "Melinoe"; //Test input
    MainCharacter mc = MainCharacter(userName);
    
    //Part of start game
    mc.currentLocation = NYC.at(0);
    mc.arriveToLocation();
    
    
    while (userResponse != "HOME") { //Change the end condition for game over
        cout << "What would you like to do?\n";
        Formatting(userResponse);
        userResponse = Respond(userResponse);
        if (userResponse == "go") {
            cout << "Where would you like to go?\n";
            mc.currentLocation->canTravel();
            Formatting(userResponse);
            mc.traverseToLocation(userResponse);
            mc.arriveToLocation();
        }
        else if (userResponse == "examine") {
            cout << mc.currentLocation->description << endl;
            cout << "You see signs for: " << endl;
            mc.currentLocation->canTravel();
        }
        else if (userResponse == "talk") {
            cout << "Gonna put some NPC stuff here";
        }
        else if (userResponse == "whereami") {
            cout << "You are in " << mc.currentLocation->name << endl;
        }
        else if (userResponse == "name") {
            cout << "Your name is " << mc.name << endl;
        }
    } 



  


    system("pause > 0"); //TAKE OUT ONLY FOR TESTING AND CLEAN INPUT IN VS
}

