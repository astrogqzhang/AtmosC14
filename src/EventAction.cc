#include "EventAction.hh"
#include "G4Event.hh"
#include "G4TrajectoryContainer.hh"
#include "G4VTrajectory.hh" 
#include <vector>

EventAction::EventAction(): G4UserEventAction() {}

EventAction::~EventAction() {}

void EventAction::EndOfEventAction(const G4Event* anEvent)
{
    G4TrajectoryContainer* container = anEvent->GetTrajectoryContainer();
    TrajectoryVector travec = container->GetVector();
    for (auto i: travec) {

    }
}