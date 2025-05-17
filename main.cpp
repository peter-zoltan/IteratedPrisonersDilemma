/**
 * @file main.cpp
 */

#include <iostream>

#include "player.h"
#include "gameManager.h"
#include "menu.h"
#include "fileManager.h"
#include "test.h"

#include "memtrace.h"

/**
 *
 */
int main() {

    #ifdef CPORTA
    testPlayer();
    testGM();
    testFM();
    #else
    bool running = true;
    while (running) {
        Menu menu;
        GameManager GM = menu.initialize();
        menu.playerSelection(GM);
        GM.runGame();
        menu.gameComplete(running, GM);
    }
    #endif
}