//
// Created by peter on 2025. 03. 11..
//

#ifndef PLAYER_H
#define PLAYER_H

#include "choice.h"

/**
 * @class Player
 * abstract class, does not define type of game or strategy as is
 * optionally has a memory of their opponents past action(s) within the match
 */
class Player {

    bool* memory = nullptr;
    int memLength = 0;

public:

    virtual ~Player() {
        delete[] memory;
    }

    /**
     *@function strategy()
     * determines what actions the player takes
     * optionally uses the player's memory
     * may have to return pointer of reference
     */
    virtual Choice* strategy () const;

};


/**
 * @class Prisoner
 * inheritor of the Player class, to play the prisoner's dilemma game
 * only declared so that collections can be more specifically typed than Player
 */
class Prisoner : public Player {};

/**
 * @class SelfishPrisoner
 * it seems return type cannot be implicitly narrowed
 * for now there"s no point to it being more than a bool
 * I'll see later
 * strategy may have to return pointer or reference
 */
class SelfishPrisoner : public Prisoner {

public:
    Choice* strategy () const override {
        PrisonerChoice* decision = new PrisonerChoice(true);
        return decision;
    }

};

#endif //PLAYER_H
