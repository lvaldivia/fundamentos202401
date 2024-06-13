#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>
using namespace std;
enum WindowFlags {
	INVISIBLE = 0x1,
	FULLSCREEN = 0x2,
	BORDERLESS = 0x4
};

class Window
{
private:
	SDL_Window* window;
	int screenWidth;
	int screenHeight;
public:
	Window();
	~Window();
	int create(string windowName,
		int screenWidth, int screenHeight, int currentFlags);
	void swapWindow();
	int getScreenWidth() {
		return screenWidth;
	}
	int getScreenHeight() {
		return screenHeight;
	}

};

