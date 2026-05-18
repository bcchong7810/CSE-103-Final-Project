#include "LoadWorld.h"
#include "Location.h"
#include "NPC.h"
#include <vector>
#include <string>
#include <iostream>
#include "Art.h"//test

using namespace std;

vector<Location*> LoadWorld() {
	//Start in Subway after intro
	Location* subway = new Location("THE SUBWAY", "There is a faint stench of urine, fresh and stagnant. The dark blue columns are slightly damn with a thin veneer of grime. Out of the corner of your eye you see something small scurrying back and forth");
	Location* met = new Location("THE METROPOLITAN MUSEUM OF ART", "There is a large staircase tapering into a large doorway flanked by light gray limestone Corinthian columns", subway);
	Location* greatHall = new Location("GREAT HALL", "Test Description", met);
	Location* ancientGreeceExhibit = new Location("ANCIENT GREEK ART EXHIBIT", "Test Description", greatHall);
	Location* ancientEgyptExhibit = new Location("ANCIENT EGYPT ART EXHIBIT", "Test Description", greatHall);
	Location* medievalArt = new Location("MEDIEVAL ART EXHIBIT", "Test Description", greatHall);
	Location* sphinx = new Location("THE GREAT SPHINX OF GIZA", "Test Description");
	Location* cairo = new Location("MAIN CITY OF CAIRO", "Test Description", sphinx);
	Location* pyramids = new Location("THE GREAT PYRAMID OF GIZA", "Test Description", cairo, sphinx);
	Location* kalamata = new Location("KALAMATA", "Test Description", cairo);
	Location* sparta = new Location("SPARTA", "Test Description", kalamata);
	Location* ephyra = new Location("EPHYRA", "Test Description", sparta);
	Location* alexandria = new Location("AlEXANDRIA", "Test Description", cairo, kalamata);
	Location* santorini = new Location("SANTORINI", "Test Description", alexandria);
	Location* athens = new Location("ATHENS", "Test Description", ephyra, santorini);
	Location* elysium = new Location("ELYSIUM", "Test Description", ephyra);
	Location* olympus = new Location("BASE OF MOUNT OLYMPUS", "Test Description", athens);
	Location* asphodel = new Location("ASPHODEL MEADOWS", "Test Description", ephyra);
	Location* mourning = new Location("MOURNING FIELDS", "Test Description", asphodel);
	Location* tartarus = new Location("TARTARUS", "Test Description", mourning, asphodel);
	

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

	//medievalArt
	medievalArt->nextLocationOne = ancientEgyptExhibit;
	medievalArt->nextLocationTwo = ancientGreeceExhibit;

	//ancientEgyptExhibit
	ancientEgyptExhibit->nextLocationOne = medievalArt;
	ancientEgyptExhibit->NPCone = new NPC("Sphinx", "Test Description");


	//sphinx
	sphinx->nextLocationOne = pyramids;
	sphinx->nextLocationTwo = cairo;

	//cairo
	cairo->nextLocationOne = kalamata;
	cairo->nextLocationTwo = alexandria;

	//pyramids no new connections

	//kalamata
	kalamata->nextLocationOne = sparta;
	kalamata->nextLocationTwo = alexandria;

	//sparta
	sparta->nextLocationOne = ephyra;
	
	//ephyra
	ephyra->nextLocationOne = athens;
	ephyra->nextLocationTwo = elysium;

	//alexandria
	alexandria->nextLocationOne = santorini;

	//santorini
	santorini->nextLocationOne = athens;
	
	//athens
	athens->nextLocationOne = olympus;
	
	//olympus no next location, dead end... keep for NPC creation
	

	//elysium
	elysium->nextLocationOne = asphodel;

	//asphodel meadows
	asphodel->nextLocationOne = mourning;
	asphodel->nextLocationTwo = tartarus;

	//mourning fields
	mourning->nextLocationOne = tartarus;

	//tartarus home??

	vector<Location*> world = { subway, met, greatHall, ancientGreeceExhibit, ancientEgyptExhibit, medievalArt, sphinx, cairo, pyramids, kalamata, sparta, ephyra, alexandria, santorini, athens, olympus, elysium, asphodel, mourning, tartarus};

	return world;
	

}


	

