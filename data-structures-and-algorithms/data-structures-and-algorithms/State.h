#pragma once

/*
* Base state class. All concrete states should implement
* this state class and provide a backreference to the engine.
* The backreference allows states to transition the engine
* from one state to the other.
*/

class Engine;

class State {
protected:
	Engine* engine_;
public:
	void setContext(Engine* engine);
	virtual void Handle1() = 0;
	virtual void Handle2() = 0;
};