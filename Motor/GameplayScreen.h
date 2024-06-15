#pragma once
#include "IGameScreen.h"
#include "Camera2D.h"
#include "GLS_Program.h"
#include "Window.h"
#include "GLTexture.h"
#include "SpriteBatch.h"
class GameplayScreen :
    public IGameScreen
{
private:
    GLS_Program program;
    Camera2D camera;
    Window* window = nullptr;
    SpriteBatch spritebatch;
    GLTexture texture;
public:
    GameplayScreen(Window* window);
    ~GameplayScreen();
    virtual void build() override;
    virtual void destroy() override;
    virtual void onExit() override;
    virtual void onEntry() override;
    virtual void update() override;
    virtual void draw() override;
    virtual void checkInput() override;
    virtual int getNextScreen() const override;
    virtual int getPreviousScreen() const override;
};

