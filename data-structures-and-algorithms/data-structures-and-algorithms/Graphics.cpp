#include "Graphics.h"
#include "Error.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

/*
* Figure out comment convention
*/

Error errorHandler;

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &_window, &_renderer);
	if (_window == nullptr || _renderer == nullptr) {
		errorHandler.SDLError(std::cout, "CreateWindowAndRenderer");
	}
	SDL_SetWindowTitle(_window, "Sorting Algorithms");
}

void Graphics::drawBackground(int r, int g, int b, int a){
	SDL_SetRenderDrawColor(_renderer, r, g, b, a);

	SDL_RenderClear(_renderer);

	SDL_RenderPresent(_renderer);
}

void Graphics::drawRectangle(int x, int y, int w, int h,
							 int r, int g, int b, int a) {
	std::cout << "Drawing Rectangle";

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_SetRenderDrawColor(_renderer, r, g, b, a);

	SDL_RenderDrawRect(_renderer, &rect);

	SDL_RenderPresent(_renderer);
}

Graphics::~Graphics() {
	SDL_DestroyWindow(_window);
}