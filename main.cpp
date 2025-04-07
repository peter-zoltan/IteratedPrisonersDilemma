#include <iostream>

//#include "choice.h"
#include "player.h"
#include "gameManager.h"

#include "memtrace.h"

int main() {
    std::cout << "Hello World!\n";

    vector<Player*> players;
    players.push_back(new SelfishPrisoner());
    players.push_back(new LoyalPrisoner());
    players.push_back(new LoyalPrisoner());
    players.push_back(new SelfishPrisoner());

    const size_t n = players.size();
    for (size_t i = 0; i < n; i++) { players[i]->print(); }

    std::cout << std::endl;

    vector<Player*>::iterator player;
    for (player = players.begin(); player != players.end(); player++) {
        (*player)->print();
        delete *player;
    }


}