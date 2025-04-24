//
// Created by peter on 2025. 03. 11..
//

/**
 * @file gameManager.h
 * Header file for the class GameManager.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include <vector>
using std::vector;

/**
 * @class GameManager
 * Runs the simulation of the Iterated Prisoner's Dilemma.
 * Keeps track of the players and the game's parameters.
 */
class GameManager {

    vector<Player*> players;    /**< List of players participating in the game. */
    int rounds;                 /**< Number of rounds to be played each match.  */
    int R;                      /**< Point value of mutual cooperation.         */
    int P;                      /**< Point value of mutual defection.           */
    int T;                      /**< Point value of one-sided defection.        */
    int S;                      /**< Point value of one-sided cooperation.      */

public:

    static bool concise;        /**< Controls the contents when writing to an output stream. */

    /**
     * Constructor initializing the integer members of the class.
     * @param rounds Number of rounds to be played each match.
     * @param R Point value of mutual cooperation.
     * @param P Point value of mutual defection.
     * @param T Point value of one-sided defection.
     * @param S Point value of one-sided cooperation.
     */
    GameManager(int rounds, int R, int P, int T, int S);

    /**
     * Copy constructor.
     * @param gm The instance to be copied.
     */
    GameManager(const GameManager& gm);

    /**
     * Destructor, deletes the contents of member variable players.
     */
    ~GameManager();

    /**
     * Runs the simulation of the game with parameters as specified by the instance's member variables.
     */
    void runGame() const;

    /**
     * Adds the parameter to the back of the list of players.
     * @param player Pointer to the player to be added to the list.
     */
    void addPlayer(Player* player);

    /**
     * Sorts the list of players by score descending.
     */
    void sort();

    /**
     * Friend operator, prints the number of rounds played, and the players' information.
     * @param os The stream to where the operator will write.
     * @param gm Reference to the instance from which the data printed is taken.
     * @return Returns the stream given as parameter.
     */
    friend std::ostream& operator<<(std::ostream& os, const GameManager& gm);

};
std::ostream& operator<<(std::ostream& os, const GameManager& gm);

#endif //GAMEMANAGER_H
