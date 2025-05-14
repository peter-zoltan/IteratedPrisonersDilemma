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

void Menu::getPlayer(GameManager& gm) const {
    std::string line;
    cout << "Add player(s): ";
    cin.ignore(1);
    getline(cin, line);
    for (int i = 0; line[i] != '\0'; i++) {
        line[i] = tolower(line[i]);
    }
    if (line.find("selfish") != std::string::npos) {
        gm.addPlayer(new Selfish());
        cout << "Selfish prisoner added." << endl;
    }
    if (line.find("naive") != std::string::npos) {
        gm.addPlayer(new Naive());
        cout << "Naive prisoner added." << endl;
    }
    if (line.find("vengeful") != std::string::npos) {
        gm.addPlayer(new Vengeful());
        cout << "Vengeful prisoner added." << endl;
    }
}


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
    Selfish selfish;        cout << selfish << endl;
    Naive naive;            cout << naive << endl;
    Vengeful vengeful;      cout << vengeful << endl;
    Copycat copycat;        cout << copycat << endl;
    Random random;          cout << random << endl;
    Majority majority;      cout << majority << endl;
    Player::resetId();
    cout << endl << "Add player(s) [1]" << endl << "Start game [2]" << endl;
    char input;
    cin >> input;
    switch (input) {
        case '1': getPlayer(GM); break;
        case '2': break;
        default: cout << "Invalid input." << endl; break;
    }
    //cout << endl;
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