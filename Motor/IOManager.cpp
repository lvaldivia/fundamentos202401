#include "IOManager.h"
#include <fstream>
#include "Error.h"
bool IOManager::readFileToBuffer(string filePath, vector<unsigned char>& buffer)
{
    ifstream file(filePath, ios::binary);
    if (file.fail()) {
        perror(filePath.c_str());
        //fatalError("No se puede abrir el archivo " + filePath);
        return false;
    }
    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    file.seekg(0, ios::beg);
    fileSize -= file.tellg();
    buffer.resize(fileSize);
    file.read((char*)&(buffer[0]), fileSize);
    file.close();
    return true;
}
