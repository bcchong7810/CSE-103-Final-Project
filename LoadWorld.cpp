/*CITATIONS
* Locations inspired by the game Hades II
* https://en.wikipedia.org/wiki/Metropolitan_Museum_of_Art
* https://en.wikipedia.org/wiki/Great_Sphinx_of_Giza
* https://en.wikipedia.org/wiki/Great_Pyramid_of_Giza
* https://en.wikipedia.org/wiki/Kalamata
* https://en.wikipedia.org/wiki/Sparta
* https://en.wikipedia.org/wiki/Ancient_Corinth (for ephyra)
* https://en.wikipedia.org/wiki/Santorini
* https://en.wikipedia.org/wiki/Library_of_Alexandria
* https://en.wikipedia.org/wiki/Athens
* https://en.wikipedia.org/wiki/Tartarus
* https://en.wikipedia.org/wiki/Fields_of_sorrow (mourning fields)
* https://en.wikipedia.org/wiki/Asphodel_Meadows
* 
*/

#include "LoadWorld.h"
#include "Location.h"
#include "NPC.h"
#include <vector>
#include <string>
#include <iostream>
#include "Art.h"

using namespace std;

vector<Location*> LoadWorld() {
	//Start in Subway after intro, loads map
	Location* subway = new Location("THE SUBWAY", "There is a faint stench of urine, fresh and stagnant. The dark blue columns are slightly damn with a thin veneer of grime. Out of the corner of your eye you see something small scurrying back and forth.");
	Location* met = new Location("THE OUTSIDE OF THE METROPOLITAN MUSEUM OF ART", "There is a large staircase tapering into a large doorway flanked by light gray limestone Corinthian columns.", subway);
	Location* greatHall = new Location("GREAT HALL", "", met);
	Location* ancientGreeceExhibit = new Location("ANCIENT GREEK ART EXHIBIT", "", greatHall);
	Location* ancientEgyptExhibit = new Location("ANCIENT EGYPT ART EXHIBIT", "", greatHall);
	Location* medievalArt = new Location("MEDIEVAL ART EXHIBIT", "", greatHall);
	Location* sphinx = new Location("THE GREAT SPHINX OF GIZA", "");
	Location* cairo = new Location("MAIN CITY OF CAIRO", "", sphinx);
	Location* pyramids = new Location("THE GREAT PYRAMID OF GIZA", "", cairo, sphinx);
	Location* kalamata = new Location("KALAMATA", "", cairo);
	Location* sparta = new Location("SPARTA", "", kalamata);
	Location* ephyra = new Location("EPHYRA", "", sparta);
	Location* alexandria = new Location("AlEXANDRIA", "", cairo, kalamata);
	Location* santorini = new Location("SANTORINI", "", alexandria);
	Location* athens = new Location("ATHENS", "", ephyra, santorini);
	Location* elysium = new Location("ELYSIUM", "", ephyra);
	Location* olympus = new Location("BASE OF MOUNT OLYMPUS", "", athens);
	Location* asphodel = new Location("ASPHODEL MEADOWS", "", ephyra);
	Location* mourning = new Location("MOURNING FIELDS", "", asphodel);
	Location* tartarus = new Location("TARTARUS", "", mourning, asphodel);
	

	//Following is connecting the locations to form the map, also NPC creation and description loading
	
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
	ancientGreeceExhibit->description = "White marble statues dot the exhibit displaying the Greco - Roman ideals of beauty.\n"
										"For gods, goddesses, and mortals.Antiques from the Bronze Age now rusted green with only hints of the once metallic brown.\n"
										"And of course, Greek and Roman white marble and limestone columns can be found throughout the exhibit.\n";

	//medievalArt
	medievalArt->nextLocationOne = ancientEgyptExhibit;
	medievalArt->nextLocationTwo = ancientGreeceExhibit;
	medievalArt->description = "You enter a room surrounded by tapestries with fantastical animals oddly mixed with humans killing one another.\n"
							   "Most of the tapestries and paintings seem to have an odd flat perspective.\n"
							   "Another room is full of armor once worn by warriors of a different era.\n"
							   "A gigantic zweihander catches your eye and you are tempted to take it home, but that would be in poor form.\n";

	//ancientEgyptExhibit
	ancientEgyptExhibit->nextLocationOne = medievalArt;
	ancientEgyptExhibit->NPCone = new NPC("SPHINX", "Speak the words of power. Please use your INVOCATION voice.\n"); //ADD INVOCATION INSTRUCTIONS);
	ancientEgyptExhibit->description = "Obelisks and statues of cats. Hieroglyphic tablets and statues depicting deities that have long lay dormant.\n"
									   "Jewelry once worn with love, now just worn down. You sit by the reflecting pool and try to relax. You've had a long day.\n"
									   "A giant statue catches your eye and you feel drawn to it by an invisible force.It has a human head, eagle wings and a lion body.\n"
									   "It's a SPHINX! You resist and pull away...for now.\n";


	//sphinx
	sphinx->nextLocationOne = pyramids;
	sphinx->nextLocationTwo = cairo;
	sphinx->description = "Towering over you is a gigantic sphinx that is 66 feet high. You see an even bigger object overshadowing the Sphinx.\n"
						  "Giant pyramids overshadow the Sphinx. You don't feel that strange energy from this sphinx.\n";

	//cairo
	cairo->nextLocationOne = kalamata;
	cairo->nextLocationTwo = alexandria;
	cairo->description = "The bustling city of Cairo. You keep to yourself and try to draw as little attention to yourself as possible.\n"
						 "You find yourself in the middle of bazaar. There's multi-colored fabrics and spices all around you.\n"
						 "The spices invade your nostrils and to be honest, it's a little overwhelming.\n"
						 "You duck into a side alley to take a break from the crowd, the noise and the smell.\n"
						 "You see a few shady figures in the huddle in the corner.\n"
						 "It looks like they are GAMBLING.\n";


	//pyramids
	pyramids->description = "You stand at the base of the famous pyramids of Giza.\n" 
							"You are in awe of the labor(involuntary or otherwise) that it took to build this.\n"
							"You feel relief from the oppressive sun\n";

	//kalamata
	kalamata->nextLocationOne = sparta;
	kalamata->nextLocationTwo = alexandria;
	kalamata->description = "A quaint city by the sea. A region known for it's olives.\n"
							"Maybe you could get some olives before you leave.\n";

	//sparta
	sparta->nextLocationOne = ephyra;
	sparta->description = "You see army formations, and drills.\n"
						  "Miles of soldiers with shields, spears and armor\n"
						  "You get an uncomfortable feeling and don't linger too long\n";
	
	//ephyra
	ephyra->nextLocationOne = athens;
	ephyra->nextLocationTwo = elysium;
	ephyra->description = "Sisyphus was once the king here. Some say that this city is the entrance to Hades, the underworld.\n"
						  "They would be correct.\n";

	//alexandria
	alexandria->nextLocationOne = santorini;
	alexandria->NPCone = new NPC("MATHEMATICIANS", "???????????????????");
	alexandria->description = "Naturally you look for the Great Library of Alexandria hoping it's still there.\n"
							  "To your surprise it's still there.It reminds you of the City College campus, but bigger and more spacious.\n"
							  "You enter to find scrolls from wall to wall.You notice people huddle around a table working on what seems to be math.\n"
							  "The MATHEMATICIANS look at you, but then go back to what they were doing.\n";


	//santorini
	santorini->nextLocationOne = athens;
	santorini->description = "Your friends had told you about Santorini in the past. They described blue domed roofs and white buildings.\n"
							 "Waters that were clear and blue, as far as they eye could see. The area is grey and dusty.\n"
							 "It appears to be the latest victim of a volcanic eruption.\n";
	
	//athens
	athens->nextLocationOne = olympus;
	athens->NPCone = new NPC("GREY-EYED WOMAN", "What brings you to this part of Hellas? If you are going to be wandering around, you should be well prepared.\n");

	
	//olympus no next location, dead end... keep for NPC creation
	olympus->NPCone = new NPC("ELDERLY BEGGAR", "You have come far to visit me here, but not for nothing.\n");
	

	//elysium
	elysium->nextLocationOne = asphodel;
	elysium->description = "This is where heroes go when they die. You see a large golden haired man imposing and towering.\n"
						   "He does not notice you though and passes by you multiple times.\n"
						   "Was that Achilles?";

	//asphodel meadows
	asphodel->nextLocationOne = mourning;
	asphodel->nextLocationTwo = tartarus;

	//mourning fields
	mourning->nextLocationOne = tartarus;
	mourning->description = "You immediately feel a heaviness all over your body, but mostly concentrated in your chest.\n"
		"You look around and see the path dotted with white myrtles.\n"
		"You hear shades cry about unrequited loves, and separated lovers.\n"
		"You hear lovers scorned sobbing softly about betrayals.\n"
		"The sounds of those separated from their beloved pets are the loudest of all.\n"
		"You begin to realize this heavy feeling is grief.You try to leave, but to no avail.\n"
		"You sit down and meditate trying to process this grief.\n"
		"You finally accept what has been bothering you and you let it go.It is unclear how much time has passed.\n";

	//tartarus
	tartarus->description = "The deepest layer of Hades and some say even the Universe. Here you see the mortal who committed transgressions, that is unforgivable sins.\n"
							"You see Sisyphus pushing his boulder up a steep slope for it to come crashing down from the top. At the bottom of that slope you see Tantalus bound to a tree.\n"
							"You watch as he reaches up to grab a plump pomegranate for it to pull away at the last moment.\n"
							"You see him kneel down to try to drink some water, but the water seems to recede into the ground under his feet when he comes near.\n";

	//Returns a vector of location pointers; since the world is connected, it really just needs subway and cairo BUT the idea was to implement a fast travel system that didn't get added. Just thinking ahead...
	vector<Location*> world = { subway, met, greatHall, ancientGreeceExhibit, ancientEgyptExhibit, medievalArt, sphinx, cairo, pyramids, kalamata, sparta, ephyra, alexandria, santorini, athens, olympus, elysium, asphodel, mourning, tartarus};

	return world;
	

}


	

