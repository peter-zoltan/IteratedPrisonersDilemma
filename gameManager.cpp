//
// Created by peter on 2025. 03. 11..
//

#include "gameManager.h"

#include "memtrace.h"


GameManager::GameManager() {
    for (vector<Player*>::iterator player = players.begin(); player != players.end(); player++) {
        delete *player;
    }
}
