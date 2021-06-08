#pragma once
#include "State.h"
#include "Scene.h"
#include "Graphics.h"

class Graphics;

class MenuState : public State, public Scene {
public:
	MenuState(Graphics& graphics);
	void Handle1() override;
	void Handle2() override;
};