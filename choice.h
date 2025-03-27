//
// Created by peter on 2025. 03. 11..
//

#ifndef CHOICE_H
#define CHOICE_H

/**
 * @class Choice
 * wrapper class for possible decisions of players
 * can only be initialized from children classes
 */
class Choice {
protected:
    Choice() = default;
public:
    virtual ~Choice() = default;
};      //here it doesn't really matter that it's not abstract

/**
 * @class PrisonerChoice
 * wrapper class for boolean value representing the player's choice in the prisoner's dilemma
 */
class PrisonerChoice : public Choice {
    bool snitch;
public:
    PrisonerChoice(bool snitch) : Choice(), snitch(snitch) {};
};

#endif //CHOICE_H
