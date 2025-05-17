//
// Created by peter on 2025. 05. 17..
//

#include <iostream>
#include "test.h"
#include "gtest_lite.h"
#include "memtrace.h"

void testPlayer() {
    //std::cout << "hya" << std::endl;
}

void testGM() {
    GameManager gm(1, 1, 1, 1, 1);
    gm.addPlayer(new Selfish());
    gm.addPlayer(new Naive());
    gm.runGame();
    gm.sort();
    TEST (gm, sort) {
        for ( auto it = gm.players.begin(); it + 1 != gm.players.end(); ++it) {
            EXPECT_TRUE((*it)->getScore() >= (*(it + 1))->getScore()) << "Scores should be in descending order" << std::endl;
        }
    } END
    std::cout << gm;
}

void testFM() {
    GameManager gm(1, 1, 1, 1, 1);
    FileManager fm;
    fm.saveToFile("", gm);
}