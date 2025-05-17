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
 *
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