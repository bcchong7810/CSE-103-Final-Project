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

    //Instructions
    ArtTwo();
    cout << "INSTRUCTIONS: When asked what you would like to do you can type things like: go, go to, examine, observe, talk, whereami, yes, no etc...\n"
            "Sometimes there will be a clue or a prompt for a specific message. INVOCATION means you will type the words exactly in all caps with spacing\n"
            "After the verb, if appropriate you will be provided with locations or things/people to interact with\n"
            "For locations, you can type either the location out, or the corresponding number\n"
            "You can type HOME at anytime to quit from when asked \"What would you like to do?\" Good luck and have fun!";
    smallFormatting();

    //Character creation...
    string userName;
    userName = Introduction();
    string userResponse;
    MainCharacter mc = MainCharacter(userName);
    mc.currentLocation = world.at(0); //Puts player on the map
    mc.arriveToLocation();

    //GameLoop
    while (userResponse != "HOME") {
        cout << "What would you like to do?\n"; //User prompt
        Formatting(userResponse);
        userResponse = Respond(userResponse);
        if (userResponse == "go") {
            cout << "Where would you like to go?\n";
            //Starts traversal and gives list of locations
            mc.currentLocation->canTravel();
            Formatting(userResponse);
            mc.traverseToLocation(userResponse);
            mc.arriveToLocation();
        }
        else if (userResponse == "examine") { //Repeats descriptions and NPCs you can interact with
            cout << mc.currentLocation->description << endl;
            cout << "You see signs for: " << endl;
            mc.currentLocation->canTravel();
            cout << "You notice: \n";
            mc.currentLocation->listofNPCS();
        }
        else if (userResponse == "talk") {
            if (mc.currentLocation->areThereNPCS()) { //Talk to NPCs
                cout << "Who or what do you want to talk to?\n";
                mc.currentLocation->listofNPCS();
                Formatting(userResponse);
                while (LocationNameSanitizer(userResponse) != mc.currentLocation->NPCone->name && LocationNameSanitizer(userResponse) != mc.currentLocation->NPCtwo->name && LocationNameSanitizer(userResponse) != "STOP") {
                    cout << "I don't recognize who or what that is. Try again or STOP.\n";
                    Formatting(userResponse);
                }
                if (LocationNameSanitizer(userResponse) == mc.currentLocation->NPCone->name) {//Time and location jump to Ancient Egypt! New map disconected from NYC and modern world
                    DialogueSystem(mc.currentLocation->NPCone);
                    if (mc.currentLocation->NPCone->name == "SPHINX") {
                        mc.currentLocation = world.at(6); 
                        cout << "There's no going back, now...\n"
                            "You feel yourself falling forwards and backwards at the same time.\n"
                            "You land in a pile of hot sand. The sun is blazing above you.\n"
                            "The heat is oppressive, you run forward to hide in a shadow\n"
                            "You look up and see the Great Sphinx of Giza before you.\n";
                        "You try to get you bearings and pat your pockets that are empty now.\n"
                            "It appears that your phone is missing. You look again and the Sphinx appears prestine.\n"
                            "You suspect not only are you in Egypt, but you are in Ancient Egypt.\n"
                            "You look out of place in your modern clothes. So you decide to borrow some clothes that are laying around\n"
                            "As you change into your new outfit, you notice the light airy fabric, but you also notice the outfit came with 100 gold coins\n"
                            "Woops.\n";
                    }
                }
                else if (LocationNameSanitizer(userResponse) == mc.currentLocation->NPCtwo->name) {
                    DialogueSystem(mc.currentLocation->NPCtwo);
                }
            }
            else {
                cout << "There is no one to talk to.";
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
        else if (userResponse == "gambling" && mc.currentLocation->name == "MAIN CITY OF CAIRO") {//Can only gamble in Cairo
            GamblingRules();
            cout << "How much do you want to wager?\n";
            double wager;
            doubleFormatting(wager);

            cout << "What is your guess?\n";
            int userGuess;
            intFormatting(userGuess);

            Gambling(mc, wager, userGuess);
        }
    }

    SpaceBreak(); 
    SpaceBreak();
    cout << "Exit Game";
    return 0;
}
