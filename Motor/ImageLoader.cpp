#include "ImageLoader.h"
#include "picoPNG.h"
#include "Error.h"
#include "IOManager.h"

GLTexture ImageLoader::loadPng(string filePath)
{

    //RGBA
    //CYMK
    GLTexture texture = {};
    vector<unsigned char>out;
    vector<unsigned char>in;
    unsigned long width, height;
    if (!IOManager::readFileToBuffer(filePath, in)) {
        fatalError("No se puede abrir archivo " + filePath);
    }
    int errorCode = decodePNG(out, width, height, &(in[0]), in.size());
    if (errorCode != 0) {
        fatalError("decode PNG con error " + to_string(errorCode));
    }
    glGenTextures(1, &(texture.id));
    glBindTexture(GL_TEXTURE_2D, texture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 
            width, height, 0,GL_RGBA,GL_UNSIGNED_BYTE,&(out[0]));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE, 0);
    texture.heigth = height;
    texture.width = width;
    return texture;
}
