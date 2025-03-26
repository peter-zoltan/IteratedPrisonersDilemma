//
// Created by peter on 2025. 03. 11..
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "playerArray.h"

class GameManager {

    PlayerArray players;
    int rounds;
    GameManager();  // hiding default constructor

public:

    GameManager(const PlayerArray& players, int rounds = 1) : players(players) {
        if (rounds > 0) this->rounds = rounds;
        else this->rounds = 1;
    }

    void runGame() const;
};

#endif //GAMEMANAGER_H
