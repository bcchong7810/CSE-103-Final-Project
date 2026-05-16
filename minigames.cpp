#include <random>
#include <iostream>
#include "minigames.h"
#include <iomanip>
using namespace std;

void RPSGame(int input) {
    // 0 is rock; 1 is paper; 2 is scissors; 3 is spock; 4 is lizard

    int opponentNum = rand() % 5;
    // Gives opponent a random outcome

    if (opponentNum == (input + 1) % 5 || opponentNum == (input + 3) % 5) {
        cout << "You Lose!!!\n";
    }
    else if (opponentNum == input) {
        cout << "Tie!!!\n";
    }
    else {
        cout << "You Win!!!\n";
    }
}

void RPSRules() {
        cout << "Rules for Rock-Paper-Scissors-Spock-Lizard\n" << endl;
        cout << "Rock: Loses Against: Paper and Spock & Wins Against: Scissors and Lizard\n";
        cout << "Paper: Loses Against: Scissors and Lizard & Wins Against: Spock and Rock\n";
        cout << "Scissors: Loses Against: Spock and Rock & Wins Against: Lizard and Paper\n";
        cout << "Spock: Loses Against: Lizard and Paper & Wins Against: Rock and Scissors\n";
        cout << "Lizard: Loses Against: Rock and Scissors & Wins Against: Paper and Spock\n";
}

int Gambling(double &amount, double betting, int guess) { //Pass in variable not pointer
    cout << endl << amount << endl;
    if (betting > amount) {
        cout << "You do not have enough money to wager $" << betting << "!!!\n";
        return 0;
    }
    if (guess < 2 || guess > 12) {
        cout << "Invalid Guess" << guess << endl;
        return 0;
    }

    double won = 0;
    int die1 = (rand() % 6) + 1;
    int die2 = (rand() % 6) + 1;
    int rng = die1 + die2;

    if (guess != rng) {
        amount -= betting;
        cout << "You Lose\n";
        cout << "Better Luck Next Time\n";
        return 0;
    }

    else {
        if (guess == 2 || guess == 12) {
            won = betting * 35 * 0.95;
            amount += won;
        }
        else if (guess == 3 || guess == 11) {
            won = betting * 17 * 0.95;
            amount += won;
        }
        else if (guess == 4 || guess == 10) {
            won = betting * 11 * 0.95;
            amount += won;
        }
        else if (guess == 5 || guess == 9) {
            won = betting * 8 * 0.95;
            amount += won;
        }
        else if (guess == 6 ||  guess == 8) {
            won = betting * 6.1 * 0.95;
            amount += won;
        }
        else if (guess == 7) {
            won = betting * 5 * 0.95;
            amount += won;
        }
        cout << "Congrats!!! You Won $" << fixed << setprecision(2) << won << "!!!\n";
        return 0;
    }
}

void GamblingRules() {
    cout << "Rules for Gambling\n" << endl;
    cout << "Make a Wager for the Sum of Two Dice\n";
    cout << "The Greater The Odds, The Less You Get\n";
    cout << "Be Responsible With Your Money\n";
    cout << "REMINDER: THE HOUSE ALWAYS WIN\n";
}


int DieRoll() {
    int rng = (rand() % 6) + 1;
    return rng;
}

int DiceGame() {
    int game = -1;

    while (game < 0) {
        int userDie = (rand() % 6) + 1;
        int enemyDie = (rand() % 6) + 1;

        cout << "You Rolled: " << userDie << endl;
        cout << "Enemy Rolled: " << enemyDie << endl << endl;
        if (enemyDie > userDie) {
            cout << "You Lose\n" << endl;
            game += 1;
        }
        else if (userDie > enemyDie) {
            cout << "You Win\n" << endl;
            game += 1;
        }
        else if (userDie == enemyDie) {
            cout << "It's a tie. Rerolling ...\n\n";
        }
    }
    return 0;
}

void DiceGameRules() {
    cout << "Rules\n" << endl;
    cout << "You Get a Die & Your Enemy Get a Die\n";
    cout << "Both players will roll until one gets the higher number\n";
    cout << "The player with the higher number wins\n";
}
