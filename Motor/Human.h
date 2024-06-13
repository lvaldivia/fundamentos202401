#pragma once
#include "Agent.h"
class Human :
    public Agent
{
public:
    Human();
    ~Human();
    void init(float speed, glm::vec2);
    void update(vector<string>& levelData,
        vector<Human*>& humans,
        vector<Zombie*>& zombies);
};

