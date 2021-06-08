#pragma once

class Graphics;
class Scene;
class State;

class Engine {
public:
	Engine(State* state);
	~Engine();
	template <typename T, typename... Args> void cleanup(T* t, Args&&... args);
	void Request1();
	void Request2();
private:
	void TransitionTo(State* state);
	void testState();
	void loop();
	void update(float elapsedTime);
	State* state_;
};