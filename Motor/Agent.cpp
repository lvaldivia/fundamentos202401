#include "Agent.h"
#include "Level.h"
#include "ResourceManager.h"

void Agent::checkTilePosition(const vector<string>& levelData, vector<glm::vec2>& collideTilePosition, float x, float y)
{
   
    glm::vec2 cornesPos = glm::vec2(floor(x /(float) TILE_WIDTH),
        floor(y/ (float)TILE_WIDTH)
           );
    if (cornesPos.x < 0 || cornesPos.x >= levelData[0].size()
        || cornesPos.y < 0 || cornesPos.y >= levelData.size()) {
        return;
    }
    if (levelData[cornesPos.y][cornesPos.x] != '.') {
        collideTilePosition.push_back(cornesPos *
            (float)TILE_WIDTH + glm::vec2((float)TILE_WIDTH / 2.0f));
    }
    
}

void Agent::collideWithTile(glm::vec2 tilePos)
{
    const float TILE_RADIUS = (float)TILE_WIDTH / 2.0f;
    const float MIN_DISTANCE = AGENT_RADIUS + TILE_RADIUS;

    glm::vec2 centerPosition = position + glm::vec2(AGENT_RADIUS);
    glm::vec2 distVec = centerPosition - tilePos;
    float xDepth = MIN_DISTANCE - abs(distVec.x);
    float yDepth = MIN_DISTANCE - abs(distVec.y);
    if (xDepth > 0 || yDepth > 0) {
        if (std::max(xDepth, 0.0f) < std::max(yDepth, 0.0f)) {
            if (distVec.x < 0) {
                position.x -= xDepth;
            }
            else {
                position.x += xDepth;
            }
        }
        else {
            if (distVec.y < 0) {
                position.y -= yDepth;
            }
            else {
                position.y += yDepth;
            }
        }
    
    }
}

Agent::Agent()
{
}

void Agent::update(vector<string>& levelData,
    vector<Human*>& humans,
    vector<Zombie*>& zombies)
{
}

void Agent::draw(SpriteBatch& spritebatch)
{
    static int textureID = 
        ResourceManager::getTexture("Images/circle.png").id;
    const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
    glm::vec4 destRect(position.x, position.y, AGENT_WIDTH, AGENT_WIDTH);
    spritebatch.draw(destRect, uvRect, textureID, 0.0f, color);
}

bool Agent::collideWithLevel(const vector<string> levelData)
{
    vector<glm::vec2> collideWithTilePosition;
    checkTilePosition(levelData, collideWithTilePosition,
        position.x, position.y);
    checkTilePosition(levelData, collideWithTilePosition,
        position.x+ AGENT_WIDTH, position.y);
    checkTilePosition(levelData, collideWithTilePosition,
        position.x, position.y+ AGENT_WIDTH);
    checkTilePosition(levelData, collideWithTilePosition,
        position.x+ AGENT_WIDTH, position.y + AGENT_WIDTH);

    if (collideWithTilePosition.size() == 0)return false;
    for (size_t i = 0; i < collideWithTilePosition.size(); i++)
    {
        collideWithTile(collideWithTilePosition[i]);
    }
    return true;
}

Agent::~Agent()
{
}

bool Agent::collideWithAgent(Agent* agent)
{
    glm::vec2 centerPosA = position + glm::vec2(AGENT_RADIUS);
    glm::vec2 centerPosB = agent->getPosition() + glm::vec2(AGENT_RADIUS);
    glm::vec2 dist = centerPosA - centerPosB;
    const float MIN_DISTANCE = AGENT_WIDTH;
    float distance = glm::length(dist);
    float collisionDepth = MIN_DISTANCE - distance;
    if (collisionDepth > 0) {
        glm::vec2 collisionDEpthVec =
            glm::normalize(dist) * collisionDepth;
        position += collisionDEpthVec / 2.0f;
        agent->position += collisionDEpthVec / 2.0f;
        return true;
    }
    return false;
}
