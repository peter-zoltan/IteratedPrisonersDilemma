//
// Created by peter on 2025. 04. 19..
//

#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "gameManager.h"

class FileManager {
public:
    void saveToFile(const char*, const GameManager& GM) const;
};

#endif //FILEMANAGER_H
