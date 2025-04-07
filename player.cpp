//
// Created by peter on 2025. 03. 11..
//

#include "player.h"
#include "choice.h"

#include "memtrace.h"


/**
 * @return returns pointer to dynamically allocated type PrisonerChoice with true wrapped value
 */
cooperation SelfishPrisoner::strategy() const { return false; }

/**
 * @return returns pointer to dynamically allocated type PrisonerChoice with false wrapped value
 */
cooperation LoyalPrisoner::strategy() const { return true; }