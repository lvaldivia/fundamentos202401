#include "Player.h"
#include <SDL/SDL.h>

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(float speed, glm::vec2 position, InputManager* inputManager)
{
	this->speed = speed;
	this->position = position;
	this->inputmanager = inputManager;
	color.set(0, 0, 185, 255);
}

void Player::update(vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
	if (inputmanager->isKeyDown(SDLK_w)) {
		position.y += speed;
	}
	if (inputmanager->isKeyDown(SDLK_s)) {
		position.y -= speed;
	}
	if (inputmanager->isKeyDown(SDLK_a)) {
		position.x -= speed;
	}
	if (inputmanager->isKeyDown(SDLK_d)) {
		position.x += speed;
	}
	collideWithLevel(levelData);
}
