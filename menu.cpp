//
// Created by peter on 2025. 04. 19..
//

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
    SelfishPrisoner selfish;    cout << selfish << endl;
    NaivePrisoner naive;        cout << naive << endl;

    GM.addPlayer(new SelfishPrisoner());
    GM.addPlayer(new NaivePrisoner());
}

void Menu::gameComplete(bool& running, const GameManager& GM) const {
    GameManager::concise = true;
    cout << GM;
    running = false;
}

void Menu::save(const GameManager& GM) const {
    FileManager FM;
}