#include "IO.h"

/*
* What is this
*/

/* Called at begin on each new drame*/
void IO::newFrame() {
	_pressedKeys.clear();
	_releasedKeys.clear();
}

void IO::keyDownEvent(const SDL_Event& event) {
	_pressedKeys[event.key.keysym.scancode] = true;
	_heldKeys[event.key.keysym.scancode] = true;
}

void IO::keyUpEvent(const SDL_Event& event) {
	_releasedKeys[event.key.keysym.scancode] = true;
	_heldKeys[event.key.keysym.scancode] = false;
}

bool IO::isKeyPressed(SDL_Scancode key) {
	return _pressedKeys[key];
}

bool IO::isKeyReleased(SDL_Scancode key) {
	return _releasedKeys[key];
}

bool IO::isKeyHeld(SDL_Scancode key) {
	return _heldKeys[key];
}