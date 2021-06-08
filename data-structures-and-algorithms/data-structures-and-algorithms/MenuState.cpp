#include "MenuState.h"
#include <iostream>


MenuState::MenuState(Graphics& graphics)
{
	std::cout << "Entered MenuState.\n";
	// Set background.
	this->setBackground(10, 10, 10, 10, graphics);
	this->setButton(15, graphics.HEIGHT / 1.25, graphics.WIDTH / 4, graphics.HEIGHT / 6,
		            0, 255, 255, 255, graphics);
}

void MenuState::Handle1() {
	std::cout << "Testing";
}

void MenuState::Handle2() {
	std::cout << "Test state 2 triggered?";
}