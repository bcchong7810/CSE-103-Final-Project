#ifndef LOCATION__
#define LOCATION__
#include <string>
#include <vector>
#include "NPC.h"

class Location {
public:
    std::string name;
    std::string description;
    
    Location* nextLocationOne;
    Location* nextLocationTwo;
    Location* nextLocationThree;
    Location* priorLocationOne;
    Location* priorLocationTwo;

    std::vector<Location*> locationsDraft;
    std::vector<Location*> locations;
    
    NPC* NPCone;
    NPC* NPCtwo;

    Location(std::string locationName, std::string locationDescription, Location* priorLocationOne = nullptr, Location* priorLocationTwo = nullptr);

    int numVisits;

    void canTravel();

};

#endif



