//
// Created by peter on 2025. 03. 11..
//

#ifndef CHOICE_H
#define CHOICE_H

class Choice {};

class PrisonerChoice {
public:
    bool snitch;
    PrisonerChoice(bool snitch) {
        this->snitch = snitch;
    }
};

#endif //CHOICE_H
