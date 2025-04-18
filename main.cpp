#include <iostream>

//#include "choice.h"
#include "player.h"
#include "gameManager.h"

#include "memtrace.h"

int main() {
    std::cout << "Hello World!\n";

    GameManager GM(5, 10, 3, 15, 1);
    GM.addPlayer(new SelfishPrisoner());
    GM.addPlayer(new SelfishPrisoner());
    GM.addPlayer(new LoyalPrisoner());
    GM.addPlayer(new LoyalPrisoner());
    GM.runGame();


}