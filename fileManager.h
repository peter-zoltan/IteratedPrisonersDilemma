//
// Created by peter on 2025. 04. 19..
//

/**
 * @file fileManager.h
 * Header file for the class FileManager.
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "gameManager.h"

/**
 * @class FileManager
 * Handles saving to file.
 */
class FileManager {

public:

    /**
     * Writes a game's results (number of rounds, players' name, ID and scores) to file.
     * @param filename Name of the file to where it writes.
     * @param gm The instance of GameManager from which data should be saved to file.
     */
    void saveToFile(string filename, const GameManager& gm) const;

    friend void testFM();    // Added as a friend so there's no need for getters solely for testing.

};

#endif //FILEMANAGER_H
