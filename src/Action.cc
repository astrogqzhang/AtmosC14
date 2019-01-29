#include "Action.hh"
#include "RunAction.hh"
#include "PrimaryGeneratorAction.hh"
//#include "TrackingAction.hh"
#include "EventAction.hh"

Action::Action() : G4VUserActionInitialization() {}

Action::~Action() {}

void Action::Build() const
{
    SetUserAction(new RunAction);
    SetUserAction(new PrimaryGeneratorAction);
    //SetUserAction(new TrackingAction);
    SetUserAction(new EventAction);
}