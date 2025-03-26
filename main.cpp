#include <iostream>

#include "choice.h"
#include "player.h"
#include "playerArray.h"
#include "gameManager.h"

int main() {
    std::cout << "Hello World!\n";

    PlayerArray players;
    players.add(new SelfishPrisoner());
    players.add(new LoyalPrisoner());
    players.add(new LoyalPrisoner());
    players.add(new SelfishPrisoner());

    const int n = players.getSize();
    for (int i = 0; i < n; i++) { players[i]->print(); }

}