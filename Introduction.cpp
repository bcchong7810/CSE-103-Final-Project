#include "Introduction.h"
#include "Response.h"
#include "FFOF.h"
#include <iostream>
#include <string>

using namespace std;

string Introduction() {
	string userNameInput;
	string userInput;
	cout << "You hear a faint voice in the back of your mind, but you can't make out what is being said.\n"
		"You realize that you feel like you are floating in a void with no sensory feedback except for the faint voice.\n"
		"You begin to feel the heavy oppression of gravity as it slowly takes affect. It starts from the top of your head.\n"
		"Gradually the heaviness moves down the back of your head, to your neck, back and legs until you finally feel the ground on the soles of your feet.\n"
		"More and more voices slowly creep into your ears. Distinctly different from the quiet voice from before that seemed to originate from within.\n"
		"You realize that your eyes have been closed this entire time. You feel like you have been asleep this entire time. But you also feel like you're trapped.\n"
		"You struggle to breathe and you're trying to wake up, but you can't!\n"
		"You finally are able to take a deep breath and open your eyes.\n"
		"You're not sure what happened, you look around to find yourself in a lecture hall. You look at the blackboard and see SPHINX OF BLACK QUARTZ JUDGE MY VOW written down.\n"
		"You find yourself standing over an attendance sheet. Still unsure of what just happened, you decide you better write down your name for credit. What do you write down?\n";
	getline(cin, userNameInput);
	cout << "\nDoes the name " << userNameInput << " feel correct?\n";
	getline(cin, userInput);
	while (!YesNoResponse(InputSanitizer(userInput))) {
		cout << endl << "What name feels correct to you?\n";
		getline(cin, userNameInput);
		cout << endl << userNameInput << "..." << "Does this name sound familiar to you?\n";
		getline(cin, userInput);
	}
	cout << "\n..." << userNameInput << "... Right, that's my name you say to yourself. ";
	cout << "You slowly remember that you are a student of City College. Well that was a weird out of body experience.\n";
	cout << "You leave City College and try to pull yourself together. You still feel not quite like yourself, maybe even a little bit nauseated.\n";
	cout << "You feel this urge to go to a museum. A museum always makes you feel better. You head to THE SUBWAY.\n";
	LineBreak();
	return userNameInput;
			
		
}