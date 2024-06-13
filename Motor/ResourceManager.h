#pragma once
#include "GLTexture.h"
#include "TextureCache.h"
using namespace std;
class ResourceManager
{
private:
	static TextureCache textureCache;
public:
	static GLTexture getTexture(string texturePath);
};

