#include "EventAction.hh"
#include "G4Event.hh"
#include "G4TrajectoryContainer.hh"
#include "G4VTrajectory.hh" 
#include "Constant.hh"
#include <vector>


EventAction::EventAction(): G4UserEventAction() {}

EventAction::~EventAction() {}

void EventAction::EndOfEventAction(const G4Event* anEvent)
{
    G4TrajectoryContainer* container = anEvent->GetTrajectoryContainer();
    G4int n_trajectory = container->size();
    G4int n_carbon = 0;
    for (size_t i = 0; i < n_trajectory; i++) {
        G4VTrajectory* tra = (*container)[i];
        G4int pdgcode = tra->GetPDGEncoding();
        if (pdgcode >= 1000060140 & pdgcode <= 1000060149) {
            n_carbon += 1;
        }
    }
    NumberOfC14 number;
    number.push_back(n_carbon);
}