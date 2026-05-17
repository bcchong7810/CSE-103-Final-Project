#include "LoadNewYork.h"
#include "Location.h"
#include <vector>
#include <string>
#include <iostream>
#include "Art.h"//test

using namespace std;

vector<Location*> LoadNewYork() {
	//Start in Subway after intro
	Location* subway = new Location("THE SUBWAY", "There is a faint stench of urine, fresh and stagnant. The dark blue columns are slightly damn with a thin veneer of grime. Out of the corner of your eye you see something small scurrying back and forth");
	Location* met = new Location("THE METROPOLITAN MUSEUM OF ART", "There is a large staircase tapering into a large doorway flanked by light gray limestone Corinthian columns", subway);
	Location* greatHall = new Location("GREAT HALL", "Test Description", met);
	Location* ancientGreeceExhibit = new Location("ANCIENT GREEK ART EXHIBIT", "Test Description", greatHall);
	Location* ancientEgyptExhibit = new Location("ANCIENT EGYPT ART EXHIBIT", "Test Description", greatHall);
	Location* medievalArt = new Location("MEDIEVAL ART EXHIBIT", "Test Description", greatHall);
	//Extra code Location gothicByDesign = Location("Gothic By Design", "");

	//subway
	subway->nextLocationOne = met;
	
	//met
	met->nextLocationOne = greatHall;

	//greatHall
	greatHall->nextLocationOne = ancientEgyptExhibit;
	greatHall->nextLocationTwo = medievalArt;
	greatHall->nextLocationThree = ancientGreeceExhibit;
	
	//ancientGreeceExhibit
	ancientGreeceExhibit->nextLocationOne = medievalArt;
	
	//ancientEgyptExhibit
	ancientEgyptExhibit->nextLocationOne = medievalArt;

	//medievalArt
	medievalArt->nextLocationOne = ancientEgyptExhibit;
	medievalArt->nextLocationTwo = ancientGreeceExhibit;

	vector<Location*> newYork = {subway, met, greatHall, ancientGreeceExhibit, ancientEgyptExhibit, medievalArt};

	return newYork;
	

}


	

