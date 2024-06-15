#pragma once
#include "IGameScreen.h"
#include "Window.h"
#include "SpriteBatch.h"
class MenuScreen :
    public IGameScreen
{
private:
    Window* window = nullptr;
    SpriteBatch spriteBatch;
public:
    MenuScreen(Window* window);
    virtual void build() override;
    virtual void destroy() override;
    virtual void onExit() override;
    virtual void onEntry() override;
    virtual void update() override;
    virtual void draw() override;
    virtual void checkInput() override;
    virtual int getNextScreen() const override;
    virtual int getPreviousScreen() const override;
    ~MenuScreen();
};

