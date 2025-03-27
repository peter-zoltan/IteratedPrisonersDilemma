//
// Created by peter on 2025. 03. 24..
//

#ifndef PLAYERARRAY_H
#define PLAYERARRAY_H

#include "player.h"

/**
 * @class PlayerArray
 * stores and manages a heterogenous collection of players
 */
class PlayerArray {

    Player** players;
    int size;

public:
    PlayerArray() : players(nullptr), size(0) {}

    ~PlayerArray() { delete[] players; }

    int getSize() const { return size; }

    void add(Player* player);

    Player* operator[](int index) const;

};

#endif //PLAYERARRAY_H
