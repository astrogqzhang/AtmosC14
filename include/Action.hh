#ifndef ACTION_H
#define ACTION_H

#include "G4VUserActionInitialization.hh"

class Action : public G4VUserActionInitialization
{
    public:
    Action();
    ~Action();

    virtual void Build() const;
};

#endif