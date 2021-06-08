#pragma once
#include <string>

class Error {
public:
	void SDLError(std::ostream& os, const std::string& message);
private:
};