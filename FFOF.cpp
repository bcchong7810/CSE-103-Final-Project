#include "FFOF.h"
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

void Cursor() {
	cout << ">> ";
}

void LineBreak() {
	cout << "\n\n\n";
}

void SpaceBreak() {
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void Formatting(string &userInput) {
	Cursor();
	getline(cin, userInput);
	LineBreak();
	SpaceBreak();
}

void smallFormatting() {
	LineBreak();
	SpaceBreak();
}

void intFormatting(int &num) {
	Cursor();
	cin >> num;
	cin.clear(); //Used to clear possible extra \n
	LineBreak();
	SpaceBreak();
}

void doubleFormatting(double &num) {
	Cursor();
	cin >> num;
	cin.clear();
	LineBreak();
	SpaceBreak();
}
