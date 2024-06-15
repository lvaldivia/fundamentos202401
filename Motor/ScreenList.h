#pragma once
#include <vector>
class Game;
class IGameScreen;
class ScreenList
{
public:
	ScreenList(Game* game);
	~ScreenList();
	IGameScreen* moveNext();
	IGameScreen* movePrevious();
	void setCreen(int nexScreen);
	void addScreen(IGameScreen* newScreen);
	void destroy();
	IGameScreen* getCurrent();
protected:
	std::vector<IGameScreen*> screens;
	Game* game;
	int currentIndex = -1;
};

