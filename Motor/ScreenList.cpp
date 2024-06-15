#include "ScreenList.h"

ScreenList::ScreenList(Game* game)
{
    this->game = game;
}

ScreenList::~ScreenList()
{
    destroy();
}

IGameScreen* ScreenList::moveNext()
{
    //IGameScreen current = getCurrent();
    
    return nullptr;
}

IGameScreen* ScreenList::movePrevious()
{
    return nullptr;
}

void ScreenList::setCreen(int nexScreen)
{
}

void ScreenList::addScreen(IGameScreen* newScreen)
{
}

void ScreenList::destroy()
{
}

IGameScreen* ScreenList::getCurrent()
{
    return nullptr;
}
