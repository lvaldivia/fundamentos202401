#include "InputManager.h"

InputManager::InputManager():mouseCoords(0.0f,0.0f)
{
}

void InputManager::update()
{
    for (auto& it: keys) {
        previousKeys[it.first] = it.second;
    }
}

void InputManager::setMouseCoords(float x, float y)
{
    mouseCoords.x = x;
    mouseCoords.y = y;
}

void InputManager::pressKey(unsigned int keyCode)
{
    keys[keyCode] = true;
}

bool InputManager::isKeyDown(unsigned int keyCode)
{
    auto it = keys.find(keyCode);
    if (it != keys.end()) {
        return it->second;
    }
    return false;
}

void InputManager::releaseKey(unsigned int keyCode)
{
    keys[keyCode] = false;
}

bool InputManager::isKeyPressed(unsigned int keyCode)
{
    
    return false;
}

InputManager::~InputManager()
{
}
