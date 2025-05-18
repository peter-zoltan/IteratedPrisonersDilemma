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
using std::string;

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
    /*virtual Player* clone() const = 0;*/

    /**
     * Stores the given bool value in the player's memory.
     * @param coop Value to be stored.
     */
    void remember(cooperation coop);

    /**
     * Clears the player's memory.
     */
    void forget();

    /**
     * Compares the player's score with another player's score.
     * @param other The player to be compared with.
     * @return True if the instance the function of which is being called has a higher
     * score than the player instance given as a parameter.
     */
    bool greaterThan(const Player& other) const;

    friend void testPlayer();    // Added as a friend so there's no need for getters solely for testing.

};

/**
 * Calls Player::print() if boolean GameManager::concise is true, otherwise calls Player::descript().
 * @param os : The stream to where the operator will write.
 * @return Returns the stream given as parameter.
 */
std::ostream& operator<<(std::ostream& os, const Player&);


/**
 * @class Selfish
 * Inheritor of abstract class Player.
 * Snitches every time.
 */
class Selfish : public Player {

public:

    /**
     * @return Returns false.
     */
    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    std::ostream& descript(std::ostream&) const override;

    /**
     * Wraps the return of 'new Selfish()' into a return type of Player*.
     * Done so that a pointer to this function can be passed as a pointer
     * to a function with return type Player*, yet return an instance of
     * an inheritor rather than the base class.
     * @return The return value of 'new Selfish()'.
     */
    static Player* wrap() { return new Selfish(); }

};


/**
 * @class Naive
 * Inheritor of abstract class Player.
 * Cooperates every time.
 */
class Naive : public Player {

public:

    /**
     * @return Returns true.
     */
    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    std::ostream& descript(std::ostream&) const override;

    /**
     * Wraps the return of 'new Naive()' into a return type of Player*.
     * Done so that a pointer to this function can be passed as a pointer
     * to a function with return type Player*, yet return an instance of
     * an inheritor rather than the base class.
     * @return The return value of 'new Naive()'.
     */
    static Player* wrap() { return new Naive(); }

};


/**
 * @class Vengeful
 * Inheritor of abstract class Player.
 * Cooperates until their opponent defects for the first time,
 * they then defect every round for the rest of the match.
 */
class Vengeful : public Player {

    bool wronged = false;

public:

    /**
     * @return Returns true if the opponent has not defected in the match, otherwise returns false.
     */
    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    std::ostream& descript(std::ostream&) const override;

    /**
     * Wraps the return of 'new Vengeful()' into a return type of Player*.
     * Done so that a pointer to this function can be passed as a pointer
     * to a function with return type Player*, yet return an instance of
     * an inheritor rather than the base class.
     * @return The return value of 'new Vengeful()'.
     */
    static Player* wrap() { return new Vengeful(); }

};


/**
 * @class Copycat
 * Inheritor of abstract class Player.
 * Starts out with cooperation then copies their opponent.
 */
class Copycat : public Player {

public:

    /**
     * @return Returns true in the first round, then the latest choice of their opponent every round after that.
     */
    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    std::ostream& descript(std::ostream&) const override;

    /**
     * Wraps the return of 'new Copycat()' into a return type of Player*.
     * Done so that a pointer to this function can be passed as a pointer
     * to a function with return type Player*, yet return an instance of
     * an inheritor rather than the base class.
     * @return The return value of 'new Copycat()'.
     */
    static Player* wrap() { return new Copycat(); }

};


/**
 * @class Random
 * Inheritor of abstract class Player.
 * Chooses between cooperation and defection at random,
 * with a roughly 50% chance of choosing either.
 */
class Random : public Player {

public:

    /**
     * @return Returns true or false at random, with a roughly 50% chance of returning either.
     */
    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    std::ostream& descript(std::ostream&) const override;

    /**
     * Wraps the return of 'new Random()' into a return type of Player*.
     * Done so that a pointer to this function can be passed as a pointer
     * to a function with return type Player*, yet return an instance of
     * an inheritor rather than the base class.
     * @return The return value of 'new Random()'.
     */
    static Player* wrap() { return new Random(); }

};


/**
 * @class Majority
 * Cooperates at first, then copies the choice their opponent has made more in the match.
 */
class Majority : public Player {

public:
    /**
     * @return Returns true in the first round, then the choice their opponent has made more every round after that.
     */
    cooperation strategy() const override;

    std::ostream& print(std::ostream&) const override;

    std::ostream& descript(std::ostream&) const override;

    /**
     * Wraps the return of 'new Majority()' into a return type of Player*.
     * Done so that a pointer to this function can be passed as a pointer
     * to a function with return type Player*, yet return an instance of
     * an inheritor rather than the base class.
     * @return The return value of 'new Majority()'.
     */
    static Player* wrap() { return new Majority(); }

};

#endif //PLAYER_H
