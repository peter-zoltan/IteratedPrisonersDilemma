/**
 * @file main.cpp
 */

#include <iostream>

#include "player.h"
#include "gameManager.h"
#include "menu.h"
#include "fileManager.h"

#include "memtrace.h"

/**
 * Runs a game with parameters customized by the user through the standard IO
 * with an instance of Selfish and Naive, displays the
 * unsorted results then exits on any button press + enter.
 */
int main() {

    bool running = true;
    while (running) {
        Menu menu;
        GameManager GM = menu.initialize();
        menu.playerSelection(GM);
        GM.runGame();
        menu.gameComplete(running, GM);
    }

}