#include "Scene.h"
#include "Engine.h"
#include "Graphics.h"
#include <iostream>

Scene::Scene(){
	// If the scene isn't clear, clear it.
}

Scene::~Scene(){
	// Clear the scene.
}

void Scene::setBackground(int r, int g, int b, int a, Graphics& graphics){
	graphics.drawBackground(r, g, b, a);
}

void Scene::setButton(int x, int y, int w, int h,
	                  int r, int g, int b, int a, Graphics& graphics)
{
	graphics.drawRectangle(x, y, w, h, r, g, b, a);
}