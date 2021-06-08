#pragma once

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	const int WIDTH = 640;
	const int HEIGHT = 480;
	void drawBackground(int r, int g, int b, int a);
	void drawRectangle(int x, int y, int w, int h,
					   int r, int g, int b, int a);
	~Graphics();
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};