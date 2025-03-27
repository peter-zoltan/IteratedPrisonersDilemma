//
// Created by peter on 2025. 03. 24..
//

#include "playerArray.h"

#include "memtrace.h"

PlayerArray::~PlayerArray() {
    for (int i = 0; i < size; i++) { delete players[i]; }
    delete[] players;
}

void PlayerArray::add(Player* player) {
    Player** newArray = new Player*[size + 1];
    for (int i = 0; i < size; i++) { newArray[i] = players[i]; }
    newArray[size] = player;
    size++;
    delete[] players;
    players = newArray;
}

Player* PlayerArray::operator[](int index) const {
    if (index < 0 || index >= size) throw "index out of range";
    return players[index];
}