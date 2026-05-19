#ifndef MINIGAMES__
#define MINIGAMES__

#include "MainCharacter.h"
#include <cstdlib>

void RPSGame(int input);
void RPSRules();
int Gambling(MainCharacter& totalMoney, double betting, int guess);
void GamblingRules();
int RNG(int num, int lowerbound); // changed DieRoll to RNG 
int DiceGame(MainCharacter& totalMoney);
void DiceGameRules();



#endif