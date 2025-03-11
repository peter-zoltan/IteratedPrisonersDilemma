//
// Created by peter on 2025. 03. 11..
//

#ifndef CLASSES_H
#define CLASSES_H

class Player {
    bool* memory = nullptr;
    int memLength = 1;
public:
    bool strategy() const;
};

class GameManager {
    Player* players = nullptr;
    int rounds = 1;
public:
    void runGame() const;
};

#endif //CLASSES_H
