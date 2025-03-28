//
// Created by peter on 2025. 03. 11..
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ostream>

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

    virtual ~Player() { delete[] memory; }

    /**
     * determines what actions the player takes
     * optionally uses the player's memory
     */
    virtual Choice* strategy () const = 0;

    virtual void print () const = 0;

};


/**
 * @class Prisoner
 * inheritor of the Player class, to play the prisoner's dilemma game
 * only declared so that collections can be more specifically typed than Player
 */
class Prisoner : public Player {};


/**
 * @class SelfishPrisoner
 * snitches every time
 */
class SelfishPrisoner : public Prisoner {

public:

    Choice* strategy () const override;

    void print () const override { std::cout << "Selfish" << std::endl; }

};


/**
 * @class LoyalPrisoner
 * never snitches
 */
class LoyalPrisoner : public Prisoner {

public:

    Choice* strategy () const override;

    void print () const override { std::cout << "Loyal" << std::endl; }

};

#endif //PLAYER_H
