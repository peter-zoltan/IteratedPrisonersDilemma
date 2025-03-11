//
// Created by peter on 2025. 03. 11..
//

#include "choice.h"

Choice::~Choice() {};

PrisonerChoice::PrisonerChoice(bool snitch) {
    this->snitch = snitch;
}

///probably dont have to take these all the way out here