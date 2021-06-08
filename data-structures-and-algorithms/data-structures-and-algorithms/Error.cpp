#include "Error.h"
#include <SDL.h>
#include <iostream>
#include <string>


void Error::SDLError(std::ostream& os, const std::string& message){
	os << message << " error: " << SDL_GetError() << std::endl;
}
