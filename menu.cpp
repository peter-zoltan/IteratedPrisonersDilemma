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

void Menu::checkPlayer(GameManager& gm, const string& line, const string& type, Player* (*newType)()) const {
    size_t start = 0;
    size_t end = line.length() - 1;
    string Type = type;
    Type[0] = toupper(Type[0]);
    while (start < end && line.substr(start, end).find(type) != std::string::npos) {
        gm.addPlayer(newType());
        cout << Type << " prisoner added." << endl;
        start = start + line.substr(start, end).find(type) + type.length() - 1;
    }
}

void Menu::getPlayer(GameManager& gm) const {
    string line;
    cout << "Add player(s): ";
    cin.ignore(1);
    getline(cin, line);
    for (int i = 0; line[i] != '\0'; i++) {
        line[i] = tolower(line[i]);
    }
    checkPlayer(gm, line, "selfish", &Selfish::wrap);
    checkPlayer(gm, line, "naive", &Naive::wrap);
    checkPlayer(gm, line, "vengeful", &Vengeful::wrap);
    checkPlayer(gm, line, "copycat", &Copycat::wrap);
    checkPlayer(gm, line, "random", &Random::wrap);
    checkPlayer(gm, line, "majority", &Majority::wrap);
    cout << endl;
}

void Menu::listPlayerTypes() {
    Selfish selfish;        cout << selfish << endl;
    Naive naive;            cout << naive << endl;
    Vengeful vengeful;      cout << vengeful << endl;
    Copycat copycat;        cout << copycat << endl;
    Random random;          cout << random << endl;
    Majority majority;      cout << majority << endl;
    Player::resetId();
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
    listPlayerTypes();
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
    cout << GM << endl << "Save results to file [1]" << endl << "Next game [2]" << endl << "Exit[3]" << endl;
    char temp;
    cin >> temp;
    running = false;
}

void Menu::save(const GameManager& GM) const {
    FileManager FM;
    string filename;
    getline(std::cin, filename);
    FM.saveToFile(filename.c_str(), GM);
}