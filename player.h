//
// Created by peter on 2025. 03. 11..
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ostream>
#include <vector>
using std::vector;

//#include "choice.h"

typedef bool cooperation;

/**
 * @class Player
 * abstract class, does not define type of game or strategy as is
 * optionally has a memory of their opponents past action(s) within the match
 */
class Player {

    static int ID;
    vector<cooperation> memory;

public:

    virtual ~Player() = default;

    /**
     * determines what actions the player takes
     * optionally uses the player's memory
     */
    virtual cooperation strategy () const = 0;

    virtual void print () const = 0;

};


/**
 * @class SelfishPrisoner
 * snitches every time
 */
class SelfishPrisoner : public Player {

public:

    cooperation strategy () const override;

    void print () const override { std::cout << "Selfish" << std::endl; }

};


/**
 * @class LoyalPrisoner
 * never snitches
 */
class LoyalPrisoner : public Player {

public:

    cooperation strategy () const override;

    void print () const override { std::cout << "Loyal" << std::endl; }

};

#endif //PLAYER_H
