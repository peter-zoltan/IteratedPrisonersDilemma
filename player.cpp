//
// Created by peter on 2025. 03. 11..
//

#include "player.h"

#include "memtrace.h"


int Player::IDnum = 0;

Player::Player() : ID(IDnum) { IDnum++; }

void Player::resetId() { ID = 0; }

void Player::incrementScore(int increment) { score += increment; }



/**
 * @return returns pointer to dynamically allocated type PrisonerChoice with true wrapped value
 */
cooperation SelfishPrisoner::strategy() const { return false; }

void SelfishPrisoner::print () const {
    std::cout << "Selfish #"<< ID << " score: " << score << std::endl;
}


/**
 * @return returns pointer to dynamically allocated type PrisonerChoice with false wrapped value
 */
cooperation LoyalPrisoner::strategy() const { return true; }

void LoyalPrisoner::print () const { std::cout << "Loyal #" << ID << " score: " << score  << std::endl; }