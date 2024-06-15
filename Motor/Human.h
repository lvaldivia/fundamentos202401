#pragma once
#include "Agent.h"
class Human :
    public Agent
{
private:
    glm::vec2 direction;
public:
    Human();
    ~Human();
    void init(float speed, glm::vec2 position);
    void update(vector<string>& levelData,
        vector<Human*>& humans,
        vector<Zombie*>& zombies);
};

