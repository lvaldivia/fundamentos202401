#include "TextureCache.h"
#include "ImageLoader.h"

TextureCache::TextureCache()
{
}

TextureCache::~TextureCache()
{
}

GLTexture TextureCache::getTexture(string texturePath)
{
    //opcion 1
    /*map<string, GLTexture>::iterator mit
                = textureMap.find(texturePath);*/
    //opcion 2
    auto mit = textureMap.find(texturePath);
    if (mit == textureMap.end()) {
        GLTexture texture = ImageLoader::loadPng(texturePath);
        //opcion 1
        /*pair<string, GLTexture> newPair(texturePath, texture);
        textureMap.insert(newPair);*/
        //opcion 2
        textureMap[texturePath] = texture;
        return texture;
    }
    return mit->second;
}
