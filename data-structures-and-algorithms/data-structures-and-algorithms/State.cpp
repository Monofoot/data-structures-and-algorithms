#include "State.h"
#include <iostream>

void State::setContext(Engine* engine) {
	this->engine_ = engine;
}