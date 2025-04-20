#include <iostream>

#include "player.h"
#include "gameManager.h"
#include "menu.h"
#include "fileManager.h"

#include "memtrace.h"

int main() {


    GameManager test1(3, 10, 5, 15, 1);
    test1.addPlayer(new SelfishPrisoner);
    GameManager test2 = test1;


    bool running = true;
    Menu menu;
    while (running) {
        GameManager GM = menu.initialize();
        menu.playerSelection(GM);
        GM.runGame();
        menu.gameComplete(running, GM);
        std::cout << GM;
    }

}