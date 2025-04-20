//
// Created by peter on 2025. 03. 11..
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ostream>
#include <vector>
using std::vector;

typedef bool cooperation;

/**
 * @class Player
 * abstract class, does not define type of game or strategy as is
 * optionally has a memory of their opponents past action(s) within the match
 */
class Player {

protected:

    static int IDcounter;
    int ID;
    int score = 0;
    vector<cooperation> memory;

public:

    Player();

    virtual ~Player() = default;

    /**
     * determines what actions the player takes
     * optionally uses the player's memory
     */
    virtual cooperation strategy() const = 0;

    virtual std::ostream& print (std::ostream&) const = 0;

    void resetId();

    void incrementScore(int increment);

    int getScore() const;

    int getID() const;

    virtual Player* clone() const = 0;
};
std::ostream& operator<<(std::ostream& os, const Player&);


/**
 * @class SelfishPrisoner
 * snitches every time
 */
class SelfishPrisoner : public Player {

public:

    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    Player* clone() const override;

};


/**
 * @class LoyalPrisoner
 * never snitches
 */
class LoyalPrisoner : public Player {

public:

    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    Player* clone() const override;

};

#endif //PLAYER_H
