//
// Created by peter on 2025. 03. 11..
//

/** @file player.cpp
 * Source file for the class Player and it's inheritors.
 */

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

cooperation SelfishPrisoner::strategy() const { return false; }

std::ostream& SelfishPrisoner::print(std::ostream& os) const {
    os << "Selfish #"<< ID << " score: " << score << endl;
    return os;
}

std::ostream& SelfishPrisoner::descript(std::ostream& os) const {
    os << "Selfish" << endl << "[Always defects.]" << endl;
    return os;
}

Player* SelfishPrisoner::clone() const {
    auto* clone = new SelfishPrisoner();
    return clone;
}

//

cooperation NaivePrisoner::strategy() const { return true; }

std::ostream& NaivePrisoner::print(std::ostream& os) const {
    os << "Naive #" << ID << " score: " << score  << endl;
    return os;
}

std::ostream& NaivePrisoner::descript(std::ostream& os) const {
    os << "Naive" << endl << "[Always cooperates.]" << endl;
    return os;
}

Player* NaivePrisoner::clone() const {
    auto* clone = new NaivePrisoner();
    return clone;
}

//

// !!implement - just so that is has a return value for now
cooperation VengefulPrisoner::strategy() const {
    for (const bool i : memory) {
        if(!i) { return false; }
    }
    return true;
}

std::ostream& VengefulPrisoner::print(std::ostream& os) const {
    os << "Vengeful #" << ID << " score: " << score << endl;
    return os;
}

std::ostream& VengefulPrisoner::descript(std::ostream& os) const {
    os << "Vengeful" << endl << "[Cooperates until the other player defects for the first time in the match.]";
    return os;
}

Player* VengefulPrisoner::clone() const {
    auto* clone = new VengefulPrisoner();
    return clone;
}