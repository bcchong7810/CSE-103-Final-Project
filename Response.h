#ifndef RESPONSE__
#define RESPONSE__

#include <string>

std::string LocationNameSanitizer(std::string locationName);
std::string InputSanitizer(std::string userInput);
bool YesNoResponse(std::string sanitizedInput); //change return type
std::string Respond(std::string sanitizedInput);

#endif