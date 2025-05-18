//
// Created by peter on 2025. 03. 11..
//

/** @file player.cpp
 * Source file for the class Player and it's inheritors.
 */

#include <random>
#include <iomanip>
#include "player.h"
#include "gameManager.h"

#include "memtrace.h"

using std::endl;


int Player::IDcounter = 0;

Player::Player() : ID(IDcounter) { IDcounter++; }

void Player::resetId() { IDcounter = 0; }

void Player::incrementScore(int increment) { score += increment; }

int Player::getScore() const { return score; }

int Player::getID() const { return ID; }

void Player::remember(cooperation coop) { memory.push_back(coop); }

void Player::forget() { memory.clear(); }

bool Player::greaterThan(const Player& other) const { return score > other.score; }

std::ostream& operator<<(std::ostream& os, const Player& p) {
    if (GameManager::concise) { return p.print(os); }
    return p.descript(os);
}

//

cooperation Selfish::strategy() const { return false; }

std::ostream& Selfish::print(std::ostream& os) const {
    os << "Selfish\t(ID:" << std::setw(2) << ID << ") - " << score << " points" << endl;
    return os;
}

std::ostream& Selfish::descript(std::ostream& os) const {
    os << "Selfish" << endl << "[Always defects.]" << endl;
    return os;
}

//

cooperation Naive::strategy() const { return true; }

std::ostream& Naive::print(std::ostream& os) const {
    os << "Naive\t(ID:" << std::setw(2) << ID << ") - " << score << " points" << endl;
    return os;
}

std::ostream& Naive::descript(std::ostream& os) const {
    os << "Naive" << endl << "[Always cooperates.]" << endl;
    return os;
}

//

cooperation Vengeful::strategy() const {
    for (const cooperation i : memory) {
        if(!i) { return false; }
    }
    return true;
}

std::ostream& Vengeful::print(std::ostream& os) const {
    os << "Vengeful\t(ID:" << std::setw(2) << ID << ") - " << score << " points" << endl;
    return os;
}

std::ostream& Vengeful::descript(std::ostream& os) const {
    os << "Vengeful" << endl << "[Cooperates until the other player defects for the first time in the match.]" << endl;
    return os;
}

//

cooperation Copycat::strategy() const {
    if (memory.empty()) { return true; }
    return memory.back();
}

std::ostream& Copycat::print(std::ostream& os) const {
    os << "Copycat\t(ID:" << std::setw(2) << ID << ") - " << score << " points" << endl;
    return os;
}

std::ostream& Copycat::descript(std::ostream& os) const {
    os << "Copycat" << endl << "[Copies the last choice made by their opponent, starts out with cooperation.]" << endl;
    return os;
}

//

cooperation Random::strategy() const {
    return rand() > (RAND_MAX / 2);
}

std::ostream& Random::print(std::ostream& os) const {
    os << "Random\t(ID:" << std::setw(2) << ID << ") - " << score << " points" << endl;
    return os;
}

std::ostream& Random::descript(std::ostream& os) const {
    os << "Random" << endl << "[Chooses between cooperation and defection at random.]" << endl;
    return os;
}

//

cooperation Majority::strategy() const {
    int countC = 0, countD = 0;
    if (memory.empty()) { return true; }
    for (const cooperation i : memory) {
        if (i) { countC++; }
        else { countD++; }
    }
    if (countC >= countD) { return true; }
    return false;
}

std::ostream& Majority::print(std::ostream& os) const {
    os << "Majority\t(ID:" << std::setw(2) << ID << ") - " << score << " points" << endl;
    return os;
}

std::ostream& Majority::descript(std::ostream& os) const {
    os << "Majority" << endl << "[Cooperates at first, then copies the choice their opponent has made more in the match.]" << endl;
    return os;
}

