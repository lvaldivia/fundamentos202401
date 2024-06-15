#pragma once
#include <glm/glm.hpp>
#include <unordered_map>
using namespace std;

class InputManager
{
private:
	unordered_map<unsigned int, bool> keys;
	unordered_map<unsigned int, bool>previousKeys;
	glm::vec2 mouseCoords;
public:
	InputManager();
	glm::vec2 getMouseCoords()const {
		return mouseCoords;
	}
	void update();
	void setMouseCoords(float x, float y);
	void pressKey(unsigned int keyCode);
	bool isKeyDown(unsigned int keyCode);
	void releaseKey(unsigned int keyCode);
	bool isKeyPressed(unsigned int keyCode);
	~InputManager();
};

