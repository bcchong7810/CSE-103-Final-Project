#include "NPC.h"
#include <string>

using namespace std;

NPC::NPC(string nameNPC, string descriptionNPC, string dialogueNPC) {
	name = nameNPC;
	description = descriptionNPC;
	dialogue = dialogueNPC;	
	money = 0;
}

