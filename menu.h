//
// Created by peter on 2025. 04. 19..
//

#ifndef MENU_H
#define MENU_H
#include "gameManager.h"

class Menu {
public:
    GameManager initialize() const;
    void playerSelection(GameManager&) const;
    void gameComplete(bool&, const GameManager&) const;
    void save(const GameManager&) const;
};

#endif //MENU_H
