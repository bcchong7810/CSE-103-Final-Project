#include "DialogueSystem.h"
#include "FFOF.h"
#include "Response.h"
#include <iostream>
#include <string>

using namespace std;

void DialogueSystem(NPC* npc) {
	string userInput;
	cout << npc->name << ": " << npc->dialogue;
	if (npc->name == "SPHINX") {
		while (true) { // Changed: to prevent possible infinite loops with double Formatting(userInput)
			Formatting(userInput);
			if (userInput == "SPHINX OF BLACK QUARTZ JUDGE MY VOW") {
				break;
			}
			cout << "Those are not the words of power!\nDo you still want to speak them yourself?\n";
			string choice;
			Formatting(choice);
			if (YesNoResponse(choice)) {
				cout << "Invoke the words of power!\n";
			}
			else {
				cout << "You hear a faint voice from within: The words of power are \"SPHINX OF BLACK QUARTZ JUDGE MY VOW\".\n"
					"Before you can stop yourself the words leave your lips as an INVOCATION.";
				break;
			}
		}

	}

}