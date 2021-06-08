#pragma once

class Graphics;

class Scene {
public:
	Scene();
	~Scene();
	virtual void setBackground(int r, int g, int b, int a, Graphics& graphics);
	virtual void setButton(int x, int y, int w, int h,
						   int r, int g, int b, int a, Graphics& graphics);
};