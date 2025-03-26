//
// Created by peter on 2025. 03. 11..
//

#include "player.h"
#include "choice.h"

Choice* Player::strategy () const {
    std::cout << "Called function strategy() of base class Player!!!" << std::endl;
    return nullptr;
}

/**
 * @return returns pointer to dynamically allocated type PrisonerChoice with true wrapped value
 */
Choice* SelfishPrisoner::strategy() const {
    PrisonerChoice* decision = new PrisonerChoice(true);    // requires a delete call somewhere
    return decision;                                             //probably when game manager runs it
}

/**
 * @return returns pointer to dynamically allocated type PrisonerChoice with false wrapped value
 */
Choice* LoyalPrisoner::strategy() const {
    PrisonerChoice* decision = new PrisonerChoice(false);    // requires a delete call somewhere
    return decision;
}