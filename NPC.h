#ifndef NPC__
#define NPC__
#include<string>


//Make NPC.cpp
class NPC {
	public:
		std::string name;
		std::string dialogue; //Do I want this to be an object?
		NPC(std::string name, std::string dialogue = "");
		
};

#endif