//
// Created by peter on 2025. 04. 19..
//

/**
 * @file fileManager.h
 * Source file for the class FileManager.
 */

#include "fileManager.h"

#include "memtrace.h"

void FileManager::saveToFile(string filename, const GameManager& gm) const {
    filename.append(".txt");
    std::ofstream file;
    try { file = std::ofstream(filename.c_str()); }
    catch (std::ios_base::failure&) {
        std::cout << "File could not be opened" << std::endl << std::endl;
    }
    file << gm;
    file.close();
}
