#include "EventAction.hh"
#include "G4Event.hh"
#include "G4TrajectoryContainer.hh"
#include "G4VTrajectory.hh" 
#include "Constant.hh"
#include "G4SystemOfUnits.hh"
#include <vector>
#include <iostream>


EventAction::EventAction(): G4UserEventAction() {}

EventAction::~EventAction() {}

void EventAction::EndOfEventAction(const G4Event* anEvent)
{
    G4TrajectoryContainer* container = anEvent->GetTrajectoryContainer();
    G4double ene = anEvent->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy();
    G4int n_trajectory = container->size();
    G4int n_carbon = 0;
    G4int n_Be = 0;
    G4int n_cl = 0;
    for (size_t i = 0; i < n_trajectory; i++) {
        G4VTrajectory* tra = (*container)[i];
        G4int pdgcode = tra->GetPDGEncoding();
        if (pdgcode >= 1000060140 & pdgcode <= 1000060149) {
            n_carbon += 1;
        } 
	    if (pdgcode >= 1000040100 & pdgcode <= 1000040109){
		    n_Be += 1;
	    }
	    if (pdgcode >= 1000170360 & pdgcode <= 1000170369){
            n_cl += 1;
        }
    }
    Number number;
    number.vecC.push_back(n_carbon);
    number.vecBe.push_back(n_Be);
    number.vecEnergy.push_back(ene);
    number.vecCl.push_back(n_cl);
}
