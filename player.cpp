//
// Created by peter on 2025. 03. 11..
//

#include "player.h"

#include "memtrace.h"


int Player::IDcounter = 0;

Player::Player() : ID(IDcounter) { IDcounter++; }

void Player::resetId() { ID = 0; }

void Player::incrementScore(int increment) { score += increment; }

int Player::getScore() const { return score; }

int Player::getID() const { return ID; }

std::ostream& operator<<(std::ostream& os, const Player& p) { return p.print(os); }

//

cooperation SelfishPrisoner::strategy() const { return false; }

std::ostream& SelfishPrisoner::print(std::ostream& os) const {
    os << "Selfish #"<< ID << " score: " << score << std::endl;
    return os;
}

Player* SelfishPrisoner::clone() const {
    auto* clone = new SelfishPrisoner();
    return clone;
}

//

cooperation LoyalPrisoner::strategy() const { return true; }

std::ostream& LoyalPrisoner::print(std::ostream& os) const {
    std::cout << "Loyal #" << ID << " score: " << score  << std::endl;
    return os;
}

Player* LoyalPrisoner::clone() const {
    auto* clone = new LoyalPrisoner();
    return clone;
}