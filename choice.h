//
// Created by peter on 2025. 03. 11..
//

#ifndef CHOICE_H
#define CHOICE_H

class Choice {
public: virtual ~Choice();
};

class PrisonerChoice : public Choice {
public:
    bool snitch;
    explicit PrisonerChoice(bool snitch);
};

#endif //CHOICE_H
