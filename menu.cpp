//
// Created by peter on 2025. 04. 19..
//

/**
 * @file menu.cpp
 * Source file for the class Menu.
 */

#include "menu.h"
#include "fileManager.h"

#include "memtrace.h"

using std::cout;
using std::cin;
using std::endl;

GameManager Menu::initialize() const {
    int rounds, R, P, T, S;
    cout << "Number of rounds each match: ";        cin >> rounds;
    cout << "Value of mutual cooperation: ";        cin >> R;
    cout << "Value of mutual defection: ";          cin >> P;
    cout << "Value of one-sided defection: ";       cin >> T;
    cout << "Value of one-sided cooperation: ";     cin >> S;
    cout << endl;
    GameManager GM(rounds, R, P, T, S);
    return GM;
}

void Menu::playerSelection(GameManager& GM) const {
    GameManager::concise = false;
    cout << "Choose players to participate:" << endl << endl;
    SelfishPrisoner selfish;    cout << selfish << endl;
    NaivePrisoner naive;        cout << naive << endl;
    Player::resetId();
    GM.addPlayer(new SelfishPrisoner());
    GM.addPlayer(new NaivePrisoner());
}

void Menu::gameComplete(bool& running, GameManager& GM) const {
    GameManager::concise = true;
    GM.sort();
    cout << GM << endl << "press any key to exit: ";
    char temp;
    cin >> temp;
    running = false;
}

void Menu::save(const GameManager& GM) const {
    FileManager FM;
    std::string filename;
    std::getline(std::cin, filename);
    FM.saveToFile(filename.c_str(), GM);
}