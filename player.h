//
// Created by peter on 2025. 03. 11..
//

/**
 * @file player.h
 * Header file for the class Player and it's inheritors.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
using std::vector;

/** @typedef cooperation
 * Alias for boolean for intuitive understanding of mapping of true/false to cooperation/defection.
 */
typedef bool cooperation;


/**
 * @class Player
 * Abstract class, strategies are defined in it's inheritors.
 * Stores their own score as well as their opponents past actions within the match.
 */
class Player {

protected:

    static int IDcounter;          /**< Static integer incremented with every new instance.              */
    int ID;                        /**< Differentiates the instance from others of the exact same type.  */
    int score = 0;                 /**< Score gathered in the game.                                      */
    vector<cooperation> memory;    /**< List of actions taken by the opponent in a given match.          */

public:

    /**
     * Constructor, initializes the instance's ID, then increments the static member variable IDcounter.
     */
    Player();

    /**
     * Virtual destructor.
     */
    virtual ~Player() = default;

    /**
     * Determines whether the player cooperates or defects.
     * Optionally uses the player's memory.
     */
    virtual cooperation strategy() const = 0;

    /**
     * Prints the instance's type, ID and score.
     * @param os : The stream to where the function will write.
     * @return Returns the stream given as parameter.
     */
    virtual std::ostream& print(std::ostream& os) const = 0;

    /**
     * Prints the instance's type and a brief description of it's strategy.
     * @param os : The stream to where the function will write.
     * @return Returns the stream given as parameter.
     */
    virtual std::ostream& descript(std::ostream& os) const = 0;

    /**
     * Sets static member variable IDcounter to 0.
     */
    static void resetId();

    /**
     * Increments member score by the given parameter.
     * @param increment The amount by which member variable score is incremented.
     */
    void incrementScore(int increment);

    /**
     * Getter for member score.
     * @return Returns the integer value of member variable score.
     */
    int getScore() const;

    /**
     * Getter for member ID.
     * @return Returns the integer value of member variable ID.
     */
    int getID() const;

    /**
     * Creates another instance of the same type.
     * @return Returns pointer to the created object.
     */
    virtual Player* clone() const = 0;

};

/**
 * Calls Player::print() if boolean GameManager::concise is true, otherwise calls Player::descript().
 * @param os : The stream to where the operator will write.
 * @return Returns the stream given as parameter.
 */
std::ostream& operator<<(std::ostream& os, const Player&);


/**
 * @class SelfishPrisoner
 * Inheritor of abstract class Player.
 * Snitches every time.
 */
class SelfishPrisoner : public Player {

public:

    /**
     * @return Returns false.
     */
    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    std::ostream& descript(std::ostream&) const override;

    Player* clone() const override;

};


/**
 * @class NaivePrisoner
 * Inheritor of abstract class Player.
 * Cooperates every time.
 */
class NaivePrisoner : public Player {

public:

    /**
     * @return Returns true.
     */
    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    std::ostream& descript(std::ostream&) const override;

    Player* clone() const override;

};


/**
 * @class VengefulPrisoner
 * Inheritor of abstract class Player.
 * Cooperates until their opponent defects for the first time,
 * they then defect every round for the rest of the match.
 */
class VengefulPrisoner : public Player {

public:

    /**
     * @return Returns true if the opponent has not defected in the match, otherwise returns false.
     */
    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    std::ostream& descript(std::ostream&) const override;

    Player* clone() const override;

};

#endif //PLAYER_H
