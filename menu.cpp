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

int Menu::getRounds() const {
    string str_rounds;
    while (true) {
        cout << "Number of rounds each match: ";
        cin >> str_rounds;
        int i = 0;
        while (str_rounds[i] != '\0' && isdigit(str_rounds[i])) { i++; }
        if (i > 0) {
            const int rounds = stoi(str_rounds.substr(0, i));
            if (rounds < 1) { cout << "Number of rounds can't be less than 1." << endl << endl; }
            else { return rounds; }
        }
        else { cout << "Invalid input, not a number." << endl << endl; }
    }
}

int Menu::getR() const {
    string str_R;
    int R;
    while (true) {
        cout << "Value of mutual cooperation: ";
        cin >> str_R;
        int start = 0;
        int end = 0;
        bool negative = false;
        if (str_R[0] == '-') {
            negative = true;
            start++;
            end++;
        }
        while (str_R[end] != '\0' && isdigit(str_R[end])) { end++; }
        if (end > 0) {
            R = stoi(str_R.substr(start, end));
            if (negative) { R = -R; }
            return R;
        }
        else { cout << "Invalid input, not a number." << endl << endl; }
    }
}

int Menu::getP(int R) const {
    string str_P;
    int P;
    while (true) {
        cout << "Value of mutual defection: ";
        cin >> str_P;
        int start = 0;
        int end = 0;
        bool negative = false;
        if (str_P[0] == '-') {
            negative = true;
            start++;
            end++;
        }
        while (str_P[end] != '\0' && isdigit(str_P[end])) { end++; }
        if (end > 0) {
            P = stoi(str_P.substr(start, end));
            if (negative) { P = -P; }
            if (P >= R) {cout << "Value has to be lower than that of mutual cooperation (R = " << R << ")." << endl << endl; }
            else { return P; }
        }
        else { cout << "Invalid input, not a number." << endl << endl; }
    }
}

int Menu::getT(int R) const {
    string str_T;
    int T;
    while (true) {
        cout << "Value of one-sided defection: ";
        cin >> str_T;
        int start = 0;
        int end = 0;
        bool negative = false;
        if (str_T[0] == '-') {
            negative = true;
            start++;
            end++;
        }
        while (str_T[end] != '\0' && isdigit(str_T[end])) { end++; }
        if (end > 0) {
            T = stoi(str_T.substr(start, end));
            if (negative) { T = -T; }
            if (T <= R) {cout << "Value has to be higher than that of mutual cooperation (R = " << R << ")." << endl << endl; }
            else { return T; }
        }
        cout << "Invalid input, not a number." << endl << endl;
    }
}

int Menu::getS(int R, int P, int T) const {
    string str_S;
    int S;
    while (true) {
        cout << "Value of one-sided cooperation: ";
        cin >> str_S;
        int start = 0;
        int end = 0;
        bool negative = false;
        if (str_S[0] == '-') {
            negative = true;
            start++;
            end++;
        }
        while (str_S[end] != '\0' && isdigit(str_S[end])) { end++; }
        if (end > start) {
            S = stoi(str_S.substr(start, end));
            if (negative) { S = -S; }
            if (S >= P) {cout << "Value has to be lower than that of mutual defection (P = " << P << ")." << endl << endl; }
            else {
                if (S + T >= 2 * R) { cout << "Added value of one-sided cooperation and of one-sided defection "
                                              "(T = " << T << ") has to be lower than twice the value of mutual "
                                              "cooperation (2 * R = " << 2 * R << ")." << endl << endl; }
                else { return S; }
            }
        }
        else { cout << "Invalid input, not a number." << endl << endl; }
    }
}

GameManager Menu::initialize() const {
    int rounds = getRounds(),
        R = getR(),
        P = getP(R),
        T = getT(R),
        S = getS(R, P, T);
    cout << endl;
    GameManager GM(rounds, R, P, T, S);
    return GM;
}

void Menu::checkPlayer(GameManager& gm, const string& line, const string& type, Player* (*newType)()) const {
    size_t start = 0;
    size_t end = line.length();
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
    cin >> line;
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

void Menu::playerSelection(GameManager& gm) const {
    GameManager::concise = false;
    listPlayerTypes();
    string input;
    do {
        cout << "Add player(s) [1]" << endl << "Start game [2]" << endl;
        cin >> input;
        switch (input[0]) {
            case '1': getPlayer(gm); break;
            case '2': break;
            default: cout << "Invalid input." << endl << endl; break;
        }
    } while (input[0] != '2');
    //cout << endl;
}

void Menu::gameComplete(bool& running, GameManager& gm) const {
    GameManager::concise = true;
    gm.sort();
    cout << gm << endl;
    string input;
    do {
        cout << "Save results to file [1]" << endl << "Next game [2]" << endl << "Exit [3]" << endl;
        cin >> input;
        switch (input[0]) {
            case '1':save(gm); break;
            case '2': break;
            case '3': running = false; break;
            default: cout << "Invalid input." << endl << endl; break;
        }
    } while (input[0] != '2' && input[0] != '3');
}

void Menu::save(const GameManager& gm) const {
    FileManager FM;
    string filename;
    cout << "Filename: ";
    cin >> filename;
    FM.saveToFile(filename, gm);
}