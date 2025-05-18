//
// Created by peter on 2025. 05. 17..
//

/**
 * @file test.cpp
 * Soure file for the tests.
 */

#include <iostream>
#include "test.h"
#include "gtest_lite.h"
#include "memtrace.h"

void testPlayer() {
    Player::resetId();
    Selfish player;;

    TEST (player, ID) {
        EXPECT_EQ(0, player.getID());
    } END

    player.incrementScore(3);

    TEST (player, score) {
        EXPECT_EQ(3, player.getScore());
        EXPECT_EQ(player.score, player.getScore());
    } END

    TEST (player, compare) {
        Naive player2;
        player2.incrementScore(5);
        EXPECT_FALSE(player.greaterThan(player2));
        EXPECT_TRUE(player2.greaterThan(player));
    } END

    TEST (player, memory) {
        player.remember(true);
        EXPECT_EQ(static_cast<size_t>(1), player.memory.size());
        EXPECT_TRUE(player.memory[0]);
        player.forget();
        EXPECT_TRUE(player.memory.empty());
    } END
}

void testGM() {
    GameManager gm(1, 5, 2, 10, -1);

    TEST(gm, parameters) {
        EXPECT_EQ(1, gm.rounds);
        EXPECT_EQ(5, gm.R);
        EXPECT_EQ(2, gm.P);
        EXPECT_EQ(10, gm.T);
        EXPECT_EQ(-1, gm.S);
    } END

    gm.addPlayer(new Selfish());
    gm.addPlayer(new Naive());
    gm.addPlayer(new Vengeful());
    gm.addPlayer(new Copycat());
    gm.addPlayer(new Random);
    gm.addPlayer(new Majority());

    TEST (gm, size) {
        EXPECT_EQ(static_cast<size_t>(6), gm.players.size());
    } END

    gm.runGame();
    gm.sort();

    TEST (gm, sort) {
        for ( auto it = gm.players.begin(); it + 1 != gm.players.end(); ++it) {
            EXPECT_TRUE((*it)->getScore() >= (*(it + 1))->getScore()) << "Scores should be in descending order" << std::endl;
        }
    } END

    TEST (gm, copy) {
        GameManager copy = gm;
        EXPECT_EQ(copy.rounds, gm.rounds);
        EXPECT_EQ(copy.R, gm.R);
        EXPECT_EQ(copy.P, gm.P);
        EXPECT_EQ(copy.T, gm.T);
        EXPECT_EQ(copy.S, gm.S);
    } END

}

void testFM() {
    GameManager gm(1, 5, 2, 10, -1);
    FileManager fm;
    fm.saveToFile("test", gm);
    std::ifstream testFile ("test.txt");
    string line;
    std::getline(testFile, line);
    char c;

    TEST (fm, notempty) {
        EXPECT_NO_THROW(c = line.at(0)) << "File should not be empty." << std::endl;
    } END

    c = ' ';
    line[0] = c;    // not nice, only done so that 'line.at(0)' on it's own doesn' complain that the value is discarded
    testFile.close();
}

void testMenu() {
    GameManager gm(1, 5, 2, 10, -1);
    Menu menu;

    TEST (menu, checkPlayer) {
        menu.checkPlayer(gm, " selfishnaiverandomd dsmajorityselfishvengeful", "selfish", &Selfish::wrap);
        menu.checkPlayer(gm, " selfishnaiverandomd dsmajorityselfishvengeful", "naive", &Naive::wrap);
        menu.checkPlayer(gm, " selfishnaiverandomd dsmajorityselfishvengeful", "vengeful", &Vengeful::wrap);
        menu.checkPlayer(gm, " selfishnaiverandomd dsmajorityselfishvengeful", "copycat", &Copycat::wrap);
        menu.checkPlayer(gm, " selfishnaiverandomd dsmajorityselfishvengeful", "random", &Random::wrap);
        menu.checkPlayer(gm, " selfishnaiverandomd dsmajorityselfishvengeful", "majority", &Majority::wrap);
        EXPECT_EQ(static_cast<size_t>(6), gm.players.size()) << "Six instances should be found within the string." << std::endl;
    } END

    TEST (menu, checkAll) {
        menu.checkAll(gm, "sf fallallfsl");
        EXPECT_EQ(static_cast<size_t>(18), gm.players.size()) << "Eighteen instances should be found within the string." << std::endl;
    } END

}