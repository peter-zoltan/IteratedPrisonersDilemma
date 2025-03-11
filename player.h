//
// Created by peter on 2025. 03. 11..
//

#ifndef PLAYER_H
#define PLAYER_H

#include "choice.h"

class Player {
    bool* memory = nullptr;
    int memLength = 1;
public:
    virtual ~Player() {
        delete[] memory;
    }
    virtual Choice strategy() const;
};

class Prisoner : Player {};

#endif //PLAYER_H
