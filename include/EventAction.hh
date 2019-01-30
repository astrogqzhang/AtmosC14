#ifndef EVENTACTION_H
#define EVENTACTION_H

#include "G4UserEventAction.hh"
#include <vector>

// global variables
std::vector<int> carbon14;


class EventAction : public G4UserEventAction
{
    public:
        EventAction();
        ~EventAction();

        virtual void EndOfEventAction(const G4Event* anEvent);
};

#endif