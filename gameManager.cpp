//
// Created by peter on 2025. 03. 11..
//

#include "gameManager.h"

#include "memtrace.h"


GameManager::GameManager(int rounds, int R, int P, int T, int S)
    : rounds(rounds), R(R), P(P), T(T), S(S) {}

GameManager::GameManager(const GameManager& GM)
    : rounds(GM.rounds), R(GM.R), P(GM.P), T(GM.T), S(GM.S) {
    for (auto player : GM.players) {
        addPlayer(player->clone());
    }
}

GameManager::~GameManager() {
    for (auto & player : players) {
        delete player;
    }
}

void GameManager::runGame () const {
    for (auto a = players.begin(); a != players.end(); ++a) {
        for (auto b = a + 1; b != players.end(); ++b) {
            if (*a != *b) {
                for (int i = 0; i < rounds; ++i) {
                    cooperation coopA = (*a)->strategy();
                    cooperation coopB = (*b)->strategy();
                    if (coopA && coopB) { (*a)->incrementScore(R); (*b)->incrementScore(R); }
                    if (coopA && !coopB) { (*a)->incrementScore(S); (*b)->incrementScore(T); }
                    if (!coopA && coopB) { (*a)->incrementScore(T); (*b)->incrementScore(S); }
                    if (!coopA && !coopB) { (*a)->incrementScore(P); (*b)->incrementScore(P); }
                }
            }
        }
    }
}

void GameManager::addPlayer(Player* player) { players.push_back(player); }

std::ostream& operator<<(std::ostream& os, const GameManager& gm) {
    for (auto player : gm.players) {
        os << *player;
    }
    return os;
}
