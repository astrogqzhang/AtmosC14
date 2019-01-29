#ifndef TRACKINGACTION_H
#define TRACKINGACTION_H

#include "G4UserTrackingAction.hh"
#include "globals.hh"

class TrackingAction : public G4UserTrackingAction
{
    public:
        TrackingAction();
        ~TrackingAction() {};

        virtual void PostUserTrackingAction(const G4Track*);
};



#endif