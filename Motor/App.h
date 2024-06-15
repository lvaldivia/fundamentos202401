#pragma once
#include <algorithm>
#include "Game.h"
#include "MenuScreen.h"
#include "GamePlayScreen.h"
class App : public Game
{
public:
	App();
	~App();
	virtual void onInit() override;
	virtual void addScreen() override;
	virtual void onExit() override;
private:
	std::unique_ptr<MenuScreen> menuScreen = nullptr;
	std::unique_ptr<GameplayScreen>gamePlayScreen = nullptr;
	
};

