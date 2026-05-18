#include "MainCharacter.h" //Needed for character creation
#include "Location.h" //probably only needed for the test
#include "Item.h"//probably only needed for the test
#include "LoadWorld.h" //Bring in load map
#include "minigames.h" //probably only needed for the test
#include "Introduction.h" 
#include "Response.h"
#include "FFOF.h"
#include "Art.h"
#include "DialogueSystem.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {  
    //Loading maps...
    vector<Location*> world = LoadWorld();
    
    //Character creation...
    string userName;
    userName = Introduction();

    string userResponse;
    //string userName; //DELETE for Final
    

    
    //userName = "Melinoe";
    MainCharacter mc = MainCharacter(userName);
    
    //Part of start game DELETE FOR FINAL
    mc.currentLocation = world.at(0);
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
            mc.currentLocation->listofNPCS();
        }
        else if (userResponse == "talk") {
            cout << "Who or what do you want to talk to?\n";
            Formatting(userResponse);
            while (LocationNameSanitizer(userResponse) != mc.currentLocation->NPCone->name && LocationNameSanitizer(userResponse) != mc.currentLocation->NPCtwo->name && LocationNameSanitizer(userResponse) != "STOP") {
                    cout << "I don't recognize who or what that is. Try again or STOP.\n";
                    Formatting(userResponse);
            }
            if (LocationNameSanitizer(userResponse) == mc.currentLocation->NPCone->name) {
                DialogueSystem(mc.currentLocation->NPCone);
                if (mc.currentLocation->NPCone->name == "SPHINX") {
                    mc.currentLocation = world.at(6);
                    cout << "There's no going back, now...\n"
                        "You feel yourself falling forwards and backwards at the same time.\n"
                        "You land in a pile of hot sand. The sun is blazing above you.\n"
                        "The heat is oppressive, you run forward to hide in a shadow\n"
                        "You look up and see the Great Sphinx of Giza before you.\n";
                } 
            }
            else if (LocationNameSanitizer(userResponse) == mc.currentLocation->NPCtwo->name) {
                DialogueSystem(mc.currentLocation->NPCtwo);
            } 
                LineBreak();
                SpaceBreak();
        }
        else if (userResponse == "whereami") {
            cout << "You are in " << mc.currentLocation->name << endl;
        }
        else if (userResponse == "name") {
            cout << "Your name is " << mc.name << endl;
        }
    } 
  
    SpaceBreak(); //Testing remove
    SpaceBreak();
    cout << "Exit Game";
    system("pause > 0"); //TAKE OUT ONLY FOR TESTING AND CLEAN INPUT IN VS
}

