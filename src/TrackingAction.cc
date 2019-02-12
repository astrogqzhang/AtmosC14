#include "globals.hh"
#include "TrackingAction.hh"
#include "G4Track.hh"

TrackingAction::TrackingAction() : G4UserTrackingAction() {}

void TrackingAction::PostUserTrackingAction(const G4Track* track)
{
}