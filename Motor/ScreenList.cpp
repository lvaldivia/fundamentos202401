#include "ScreenList.h"
#include "IGameScreen.h"

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
    IGameScreen* current = getCurrent();
    if (current->getNextScreen() != -1) {
        currentIndex = current->getNextScreen();
    }
    return getCurrent();
}

IGameScreen* ScreenList::movePrevious()
{
    IGameScreen* current = getCurrent();
    if (current->getPreviousScreen() != -1) {
        currentIndex = current->getPreviousScreen();
    }
    return getCurrent();
}

void ScreenList::setCreen(int nexScreen)
{
    currentIndex = nexScreen;
}

void ScreenList::addScreen(IGameScreen* newScreen)
{
    newScreen->screenIndex = screens.size();
    screens.push_back(newScreen);
    newScreen->build();
    newScreen->setParent(game);
}

void ScreenList::destroy()
{
    for (size_t i = 0; i < screens.size(); i++)
    {
        screens[i]->destroy();
    }
    currentIndex = -1;
    screens.resize(0);

}

IGameScreen* ScreenList::getCurrent()
{
    if (currentIndex == -1) {
        return nullptr;
    }
    return screens[currentIndex];
    
}
