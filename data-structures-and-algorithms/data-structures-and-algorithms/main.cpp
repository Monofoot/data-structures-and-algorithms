#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Engine.h"
#include "MenuState.h"
#include "TestState.cpp"

/*
* Comment on what this is
*/

int main(int argc, char* argv[])
{
	Engine *engine = new Engine(new TestState); // We're going to have to do something about this.

	while (true) {

	}

	SDL_Quit();
	return 0;
}