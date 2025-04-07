//
// Created by peter on 2025. 03. 11..
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include <vector>
using std::vector;


class GameManager {

    vector<Player*> players;
    int rounds;
    GameManager();  // hiding default constructor

public:

    GameManager(const vector<Player*>& players, int rounds = 1);

    void runGame() const;

    ~GameManager();
};

#endif //GAMEMANAGER_H
