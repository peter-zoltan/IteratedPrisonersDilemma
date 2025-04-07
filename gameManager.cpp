//
// Created by peter on 2025. 03. 11..
//

#include "gameManager.h"

#include "memtrace.h"


GameManager::GameManager(const vector<Player*>& players, int rounds, int R, int P, int T, int S)
    : players(players), rounds(rounds), R(R), P(P), T(T), S(S) {}


GameManager::GameManager() {
    for (vector<Player*>::iterator player = players.begin(); player != players.end(); player++) {
        delete *player;
    }
}
