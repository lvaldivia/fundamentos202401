#pragma once
#include <glm/glm.hpp>
#include "SpriteBatch.h"
#include "GLTexture.h"
#include <string>
using namespace std;

const float AGENT_WIDTH = 60.0f;
const float AGENT_RADIUS = AGENT_WIDTH / 2.0f;

class Zombie;
class Human;

class Agent
{
protected:
	glm::vec2 position;
	float speed;
	Color color;
	void checkTilePosition(const vector<string>& levelData,
		vector<glm::vec2>& collideTilePosition, float x, float y);
	void collideWithTile(glm::vec2 tilePos);
public:
	Agent();
	glm::vec2 getPosition()const { return position; }
	virtual void update(vector<string>& levelData,
		vector<Human*>& humans,
		vector<Zombie*>& zombies);
	void draw(SpriteBatch& spritebatch);
	bool collideWithLevel(const vector<string>levelData);
	virtual ~Agent();
	bool collideWithAgent(Agent* agent);
};

