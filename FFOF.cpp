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
