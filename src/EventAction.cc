#include "EventAction.hh"

EventAction::EventAction(): G4UserEventAction() {}

EventAction::~EventAction() {}

void EventAction::EndOfEventAction(const G4Event* anEvent)
{
}