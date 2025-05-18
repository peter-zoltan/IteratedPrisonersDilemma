//
// Created by peter on 2025. 05. 17..
//

/**
 * @file test.h
 * Header file for the tests.
 */

#ifndef TEST_H
#define TEST_H
#include "player.h"
#include "gameManager.h"
#include "fileManager.h"
#include "menu.h"

/**
 * Runs tests for the class Player and it's inheritors.
 * Friend function of class Player.
 */
void testPlayer();

/**
 * Runs tests for the class GameManager.
 * Friend function of class GameManager.
 */
void testGM();

/**
 * Runs test for the clas FileManager.
 * Friend function of clas FileManager
 */
void testFM();

/**
 * Runs test for the class Menu.
 * Friend function of the classes Menu and GameManager.
 */
void testMenu();

#endif //TEST_H
