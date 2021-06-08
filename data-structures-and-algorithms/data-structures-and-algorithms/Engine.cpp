#include <SDL.h>
#include "Engine.h"
#include "Graphics.h"
#include "IO.h"
#include "State.h"
#include "TestState.cpp"
#include "MenuState.h"
#include <iostream>
#include <typeinfo>

/**
* 
*/

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS; // Max time a frame can last
}

// Variadic template which abstracts all of the cleaning.
// explain why they're inline void
template<typename T, typename... Args>
void Engine::cleanup(T* t, Args&&... args)
{
	// Work for the first item.
	cleanup(t);
	// Recursive clean up which uses the rest of the arguments.
	cleanup(std::forward<Args>(args)...);
}
template<>
inline void Engine::cleanup<SDL_Window>(SDL_Window* window)
{
	if (!window) { return; }
	SDL_DestroyWindow(window);
}
template<>
inline void Engine::cleanup<SDL_Renderer>(SDL_Renderer* renderer)
{
	if (!renderer) { return; }
	SDL_DestroyRenderer(renderer);
}
template<>
inline void Engine::cleanup<SDL_Texture>(SDL_Texture* texture)
{
	if (!texture) { return; }
	SDL_DestroyTexture(texture);
}
template<>
inline void Engine::cleanup<SDL_Surface>(SDL_Surface* surface)
{
	if (!surface) { return; }
	SDL_FreeSurface(surface);
}

Engine::Engine(State *state) : state_(nullptr) {
	this->TransitionTo(state);
	this->Request1();
	SDL_Init(SDL_INIT_EVERYTHING);
	loop();
}

Engine::~Engine() {
	delete state_;
}

void Engine::TransitionTo(State* state) {
	/*
	* If this state isn't null, delete it.
	* Then set the state to the parsed state.
	*/
	std::cout << "Engine: Transition to " << typeid(state).name() << ".\n";
	if (this->state_ != nullptr) {
		delete this->state_;
	}
	this->state_ = state;
	this->state_->setContext(this);
}

void Engine::testState() {
	std::cout << "This is the delegate part? Not sure, figure it out.";
}

void Engine::Request1()
{
	this->state_->Handle1();
}

void Engine::Request2()
{
	this->state_->Handle2();
}

/*
* Happens every frame etc describe this
* SDL_Event holds every event, is checked on every loop.
*/
void Engine::loop() {
	Graphics graphics;
	IO io;
	SDL_Event event;

	int LAST_UPDATE_TIME = SDL_GetTicks();

	while (true) {
		io.newFrame();

		if (SDL_PollEvent(&event)) { // Put this in an event handler function
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					io.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				io.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
		if (io.isKeyPressed(SDL_SCANCODE_DOWN) || io.isKeyPressed(SDL_SCANCODE_S) == true) {
			std::cout << "down clicked";
			this->TransitionTo(new TestState);
			this->Request1();
		}
		if (io.isKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			this->TransitionTo(new MenuState(graphics));
		}
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			// If the event.type.motion.x and y is in a certain area, it
			// must be a button press - can we get this directly from state.button
			// or something?
			std::cout << "Detected a mouse click!!\n";
			std::cout << "The mouse click occured in x: " << event.motion.x;
		}

		// vvv How long each frame will take
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}

void Engine::update(float elapsedTime) {

}