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
    int R, P, T, S, rounds;
    GameManager() {};  // hiding default constructor, not sure if it's necesary

public:

    static bool concise;

    GameManager(int rounds, int R, int P, int T, int S);

    GameManager(const GameManager&);

    ~GameManager();

    void runGame() const;

    void addPlayer(Player*);

    friend std::ostream& operator<<(std::ostream& os, const GameManager& gm);

};
std::ostream& operator<<(std::ostream& os, const GameManager& gm);

#endif //GAMEMANAGER_H
