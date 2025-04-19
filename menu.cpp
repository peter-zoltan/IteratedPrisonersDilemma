//
// Created by peter on 2025. 04. 19..
//

#include "menu.h"
#include "fileManager.h"

GameManager Menu::initialize() const {
    int rounds, R, P, T, S;
    std::cin >> rounds >> R >> P >> T >> S;
    GameManager GM(rounds, R, P, T, S);
    return GM;
}

void Menu::playerSelection(GameManager& GM) const {
    GM.addPlayer(new SelfishPrisoner());
    GM.addPlayer(new LoyalPrisoner());
}

void Menu::gameComplete(bool& running, const GameManager& GM) const {
    running = false;
}

void Menu::save(const GameManager& GM) const {
    FileManager FM;
}