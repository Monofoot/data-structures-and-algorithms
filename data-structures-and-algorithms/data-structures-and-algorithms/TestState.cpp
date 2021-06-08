#include "State.h"
#include <iostream>

class TestState : public State {
public:
	TestState() {
		std::cout << "I'm a new test state";
	}
	void Handle1() override {
		std::cout << "overriding testState from TestState";
	}
	void Handle2() override {
		std::cout << "overriding testStatr2 from TestState";
	}
};