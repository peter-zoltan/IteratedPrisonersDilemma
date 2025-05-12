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

    void getPlayer(GameManager& gm) const;

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
};

#endif //MENU_H
