#include "Response.h"
#include "FFOF.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string LocationNameSanitizer(string locationName) {
	string sanitizedLocationString = "";
	for (int i = 0; i < locationName.length(); i++) {
		if (isalpha(locationName.at(i))) {
			sanitizedLocationString += toupper(locationName.at(i));
		}
	}

	return sanitizedLocationString;

}

string InputSanitizer(string userInput) {
	string sanitizedUserInput = "";
	for (int i = 0; i < userInput.length(); i++) {
		if (isalpha(userInput.at(i))) {
			sanitizedUserInput += tolower(userInput.at(i));
		}
	}
	return sanitizedUserInput;
}

bool YesNoResponse(string sanitizedInput) {
	vector<string> yesResponse = {"yes", "y", "sure"};
	vector<string> noResponse = {"no", "n", "nope"};
	string cleanInput = sanitizedInput;
	string newInput;
	while (true) {
		for (int i = 0; i < yesResponse.size(); i++) {
			if (cleanInput == yesResponse.at(i)) {
				return true;
			}

		}

		for (int i = 0; i < noResponse.size(); i++) {
			if (cleanInput == noResponse.at(i)) {
				return false;
			}
		}
		
		cout << "Please answer yes or no.\n";
		getline(cin, newInput);
		Formatting;
		cleanInput = InputSanitizer(newInput);

	}

	
	
}

string Respond(string lowerSanitizedInput) {
	vector<string> validWords = {"observe", "examine", "lookaround" "goto", "go", "talk", "talkto", "whereami"};
	string testWord = lowerSanitizedInput;
	bool notValidWord = true;
	while (notValidWord) {
		for (int i = 0; i < validWords.size(); i++) {
			if (InputSanitizer(testWord) == validWords.at(i)) {
				notValidWord = false;
				break;
			}
		}

		if (notValidWord) {
			cout << "I don't understand. Please try again.\n";
			getline(cin, testWord);
			Formatting();
		}
	}

	if (testWord == "observe" || testWord == "examine" || testWord == "lookaround") {
		return "examine";
	} else if (testWord == "goto" || testWord == "go") {
		return "go";
	} else if (testWord == "talk" || testWord == "talkto") {
		return "talk";
	} else if (testWord == "whereami") {
		return "whereami";
	} 


}
