#include "MainCharacter.h" //probably only needed for the test
#include "Location.h" //probably only needed for the test
#include "Item.h"//probably only needed for the test
#include "LoadNewYork.h" //Bring in load map
#include "minigames.h" //probably only needed for the test

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {   
    //Testing for games

    string mcName = "Barry";
    MainCharacter bearie = MainCharacter(mcName);

    double wallet = 400;
    double bet;
    int guess;

    cout << endl << endl << endl << endl;
    cout << "How much do you want to bet? ";
    cin >> bet;
    cout << "What is your guess? ";
    cin >> guess;

    Gambling(bearie.wallet, bet, guess);
    
    cout << bearie.wallet;



    

    //add gameLogic function/LOOP???

    cout << "Program complete!";
    system("pause > 0"); //TAKE OUT ONLY FOR TESTING AND CLEAN INPUT IN VS
}