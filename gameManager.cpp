//
// Created by peter on 2025. 03. 11..
//

#include "gameManager.h"

#include "memtrace.h"


GameManager::GameManager(const vector<Player*>& players, int rounds) : players(players) {
    if (rounds > 0) this->rounds = rounds;
    else this->rounds = 1;
}


GameManager::GameManager() {
    for (vector<Player*>::iterator player = players.begin(); player != players.end(); player++) {
        delete *player;
    }
}
