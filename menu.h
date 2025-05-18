//
// Created by peter on 2025. 04. 19..
//

/**
 * @file menu.h
 * Header file for the class Menu.
 */

#ifndef MENU_H
#define MENU_H
#include "gameManager.h"

/**
 * @class Menu
 * Handles the standard IO for setting up the game, saving to file and exiting the program.
 */
class Menu {

    /**
     * Gets the number of rounds that should be played from the standard input.
     * @return Returns the number of rounds.
     */
    int getRounds() const;

    /**
     * Gets the value of mutual cooperation (R) from the standard input.
     * @return Returns the value of R.
     */
    int getR() const;

    /**
     * Gets the value of mutual defection (P) from the standard input.
     * @param R Makes sure that P < R.
     * @return Returns the value of P.
     */
    int getP(int R) const;

    /**
     * Gets the value of one-sided defection (T) from the standard input.
     * @param R Makes sure that T > R.
     * @return Returns the value of T.
     */
    int getT(int R) const;

    /**
     * Gets the value of one-sided cooperation (S) from the standard input.
     * @param P Makes sure that S < P.
     * @param R && @param T Makes sure that S + T < 2 * R.
     * @return Returns the value of T.
     */
    int getS(int R, int P, int T) const;

    /**
     * Checks the parameter 'line' for occurrences of the parameter 'type', and calls the parameter
     * 'newType()' for each find, adding a new Player to parameter 'gm' every time.
     * @param gm GameManager instance to which the Players are added.
     * @param line The line it checks for Players.
     * @param type The type of Player it checks for.
     * @param newType This function's return value if given as parameter to 'gm.addPlayer()'.
     */
    void checkPlayer(GameManager& gm, const string& line, const string& type, Player* (*newType)()) const;

    /**
     * Gets a line from the standard input and calls 'checkPlayer' to search for each Player type mentioned within.
     * @param gm GameManager instance to which the Players are added.
     */
    void getPlayer(GameManager& gm) const;

    /**
     * Lists each type of Player defined in the source code along with their descriptions.
     */
    static void listPlayerTypes();

public:

    /**
     * Asks for the parameters of the game through the standard IO.
     * @return Returns an instance of GameManager initialized with the given parameters.
     */
    GameManager initialize() const;

    /**
     * Handles the selection of players to be added to the game.
     * @param gm The instance of GameManager to where the players are added.
     */
    void playerSelection(GameManager& gm) const;

    /**
     * Displays the results of a game, directs to saving to file, starting a new game, or exiting the program.
     * @param running Changed to false if the program should exit without starting a new game.
     * @param gm The instance of GameManager from which data may be saved to file.
     */
    void gameComplete(bool& running, GameManager& gm) const;

    /**
     * Handles saving a game's results to file by calling an instance of FileManager with the relevant parameters.
     * @param gm The instance of GameManager from which data should be saved to file.
     */
    void save(const GameManager& gm) const;

    friend void testMenu();    // Added as a friend so there's no need for getters solely for testing.
};

#endif //MENU_H
