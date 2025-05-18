/**
 * @file main.cpp
 * Contains the main() function for the project.
 * Handles tests and the application loop.
 */

#include <iostream>

#include "player.h"
#include "gameManager.h"
#include "menu.h"
#include "fileManager.h"
#include "test.h"

#include "memtrace.h"

/**
 * Main function for the project, if macro CPORTA is defined tests are ran,
 * otherwise handles the application loop with one game constituting a cycle.
 */
int main() {

    #ifndef CPORTA
    bool running = true;
    while (running) {
        Menu menu;
        GameManager GM = menu.initialize();
        menu.playerSelection(GM);
        GM.runGame();
        menu.gameComplete(running, GM);
    }
    #else
    testPlayer();
    testGM();
    testFM();
    testMenu();
    #endif
}