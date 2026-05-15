#include "FFOF.h"
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

string InputSanitizer(string userInput){
	string cleanUserString = "";
	for (int i = 0; i < userInput.length(); i++) {
		if (isalpha(userInput[i])) {
			cleanUserString += tolower(userInput[i]);
		}
	}
	return cleanUserString;
}

void InputDecisionMaker(string cleanUserInput) {
	cout << "Placeholder";
}

void LineBreak() {
	cout << "Placeholder";
}

void SpaceBreak() {
	cout << "Placeholder";
}

void ArtOne() {
	cout << "Placeholder";
}

void ArtTwo() {
	cout << "Placeholder";
}
