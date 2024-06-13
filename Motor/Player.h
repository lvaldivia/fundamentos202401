#pragma once
#include "Human.h"
#include "InputManager.h"

class Player :
    public Human
{
private:
    InputManager* inputmanager;
public:
    Player();
    ~Player();
    void init(float speed, glm::vec2 position, InputManager* inputManager);
    void update(vector<string>& levelData,
        vector<Human*>& humans,
        vector<Zombie*>& zombies);
};

