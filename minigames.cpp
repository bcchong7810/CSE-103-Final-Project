#include <cstdlib> // change random to cstdlib
#include <iostream>
#include "minigames.h"
#include <iomanip>
#include "MainCharacter.h"

using namespace std;

int RNG(int num, int lowerbound) { // A RNG Generator
    int rng = (rand() % num) + lowerbound;
    return rng;
}

void RPSGame(int input) { // A Game of Rock Paper Scisscors Spock Lizard
    // 0 is rock; 1 is paper; 2 is scissors; 3 is spock; 4 is lizard

    int opponentNum = RNG(5, 0);
    // Gives opponent a random outcome

    if (opponentNum == (input + 1) % 5 || opponentNum == (input + 3) % 5) { /* When oppoenent is one or three spots in the cycle from 0 to 5 higher, then they win.
    Ex: You: 4, Opponent: 2. 4, 0, 1, 2. When it cycles back, 2 is 3 spots after 4, so lizard loses to scissors. */
        cout << "You Lose!!!\n";
    }
    else if (opponentNum == input) {
        cout << "Tie!!!\n";
    }
    else {
        cout << "You Win!!!\n";
    }
}

void RPSRules() { // Explains Rules for Rock Paper Scissors Spock Lizard
    cout << "Rules for Rock-Paper-Scissors-Spock-Lizard\n" << endl;
    cout << "Rock: Loses Against: Paper and Spock & Wins Against: Scissors and Lizard\n"; // Rock[Loses and Wins]
    cout << "Paper: Loses Against: Scissors and Lizard & Wins Against: Spock and Rock\n"; // Paper[Loses and Wins]
    cout << "Scissors: Loses Against: Spock and Rock & Wins Against: Lizard and Paper\n"; // Scissors[Loses and Wins]
    cout << "Spock: Loses Against: Lizard and Paper & Wins Against: Rock and Scissors\n"; // Spock[Loses and Wins]
    cout << "Lizard: Loses Against: Rock and Scissors & Wins Against: Paper and Spock\n"; // Lizard[Loses and Wins]
}

int Gambling(MainCharacter& totalMoney, double betting, int guess) { //Pass in variable not pointer
    cout << endl << totalMoney.moneyInWallet() << endl;
    if (betting > totalMoney.moneyInWallet()) { // Cannot bet when user don't have enough money
        cout << "You do not have enough money to wager $" << betting << "!!!\n";
        return 0;
    }
    if (guess < 2 || guess > 12) { // the sum of two dice is between 2 and 12 [inclusive]
        cout << "Invalid Guess" << guess << endl;
        return 0;
    }

    double won = 0;
    int die1 = RNG(6, 1);
    int die2 = RNG(6, 1);
    int rng = die1 + die2;

    if (guess != rng) { // When user loses
        totalMoney.SubtractMoney(betting);
        cout << "First Die: " << die1 << "& Second Die: " << die2 << endl; // Let's user know what the dice rolls were
        cout << "You Lose\n";
        cout << "Now You Have $" << fixed << setprecision(2) << totalMoney.moneyInWallet() << " LEFT";
        cout << "Better Luck Next Time\n";
        return 0;
    }

    else { // when user wins; house takes 5 percent
        if (guess == 2 || guess == 12) {
            won = betting * 35 * 0.95; // 35:1 odds
        }
        else if (guess == 3 || guess == 11) {
            won = betting * 17 * 0.95; // 17:1 odds
        }
        else if (guess == 4 || guess == 10) {
            won = betting * 11 * 0.95; // 11:1 odds
        }
        else if (guess == 5 || guess == 9) {
            won = betting * 8 * 0.95; // 8:1 odds
        }
        else if (guess == 6 || guess == 8) {
            won = betting * 6.1 * 0.95; // 6.1:1 odds
        }
        else if (guess == 7) {
            won = betting * 5 * 0.95; // 5:1 odds
        }
        totalMoney.AddMoney(won);
        cout << "First Die: " << die1 << "& Second Die: " << die2 << endl; // Let's user know what the dice rolls were
        cout << "Congrats!!! You Won $" << fixed << setprecision(2) << won << "!!!\n";
        cout << "Now You Have $" << fixed << setprecision(2) << totalMoney.moneyInWallet();
        return 0;
    }
}

void GamblingRules() { // Rules for Gambling
    cout << "Rules for Gambling\n" << endl;
    cout << "Make a Wager for the Sum of Two Dice\n";
    cout << "The Greater The Odds, The Less You Get\n";
    cout << "Be Responsible With Your Money\n";
    cout << "REMINDER: THE HOUSE ALWAYS WIN\n";
}

int DiceGame(MainCharacter &totalMoney) { //WIN 50 LOSE 50 cannot play if <50
    int game = -1;

    while (game < 0) { // Game continues until a WINNER
        int userDie = RNG(6, 1); // Gives both the user and enemy a random die number
        int enemyDie = RNG(6, 1);

        cout << "You Rolled: " << userDie << endl;
        cout << "Enemy Rolled: " << enemyDie << endl << endl;
        if (enemyDie > userDie) { // When user loses
            totalMoney.SubtractMoney(50);
            cout << "You Lose\n" << endl;
            cout << "Now You Have $" << fixed << setprecision(2) << totalMoney.moneyInWallet() << " LEFT";
            game += 1; // stops the while loop
        }
        else if (userDie > enemyDie) { // When user wins
            totalMoney.AddMoney(50);
            cout << "You Win\n" << endl;
            cout << "Now You Have $" << fixed << setprecision(2) << totalMoney.moneyInWallet();
            game += 1; // stops the while loop
        }
        else if (userDie == enemyDie) { // When there is a tie
            cout << "It's a tie. Rerolling ...\n\n";
        }
    }
    return 0;
}

void DiceGameRules() { // Rules for the Dice Game
    cout << "Rules\n" << endl;
    cout << "You Get a Die & Your Enemy Get a Die\n";
    cout << "Both players will roll until one gets the higher number\n";
    cout << "The player with the higher number wins\n";
    cout << "If You Win: +$50; If You Lose: -$50";
}