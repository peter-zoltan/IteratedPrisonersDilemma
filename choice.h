//
// Created by peter on 2025. 03. 11..
//

#ifndef CHOICE_H
#define CHOICE_H

/**
 * @class Choice
 * (not actually yet but ill try) abstract wrapper class for possible decisions of players
 */
class Choice { public: virtual ~Choice() = default; };

/**
 * @class PrisonerChoice
 * wrapper class for boolean value representing the player's choice in the prisoner's dilemma
 *
 */
class PrisonerChoice : public Choice {

    bool snitch;

public:

    PrisonerChoice(bool snitch) : Choice(), snitch(snitch) {};

    //~PrisonerChoice() {};

    //bool getChoice() const { return snitch; }
};

#endif //CHOICE_H
