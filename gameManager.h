//
// Created by peter on 2025. 03. 11..
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "player.h"

class GameManager {
    Player* players = nullptr;
    int rounds = 1;
public:
    void runGame() const;
};

#endif //GAMEMANAGER_H
