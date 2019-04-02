#include "Detector.hh"
#include "Action.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif


#include "G4UImanager.hh"
#include "QGSP_BERT_HP.hh"
#include "QGSP_BIC_HP.hh"
#include "G4UIExecutive.hh"


#include "Randomize.hh"
#include "Constant.hh"
#include "G4SystemOfUnits.hh"
#include <vector>
#include <iostream>
#include <fstream>



int main(int argc, char const *argv[])
{
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    G4int seconds = time(NULL);
    G4Random::setTheSeed(seconds);

    // Construct the default run manager
    #ifdef G4MULTITHREADED
        G4MTRunManager* runManager = new G4MTRunManager;
    #else
        G4RunManager* runManager = new G4RunManager;
    #endif

    // Construct Detector
    runManager->SetUserInitialization(new Detector());

    // Physics list
    // G4VModularPhysicsList* physicsList = new QGSP_BERT_HP;
    G4VModularPhysicsList* physicsList = new QGSP_BIC_HP;
    physicsList->SetVerboseLevel(1);
    runManager->SetUserInitialization(physicsList);
    runManager->SetUserInitialization(new Action);    


    G4UImanager* UI = G4UImanager::GetUIpointer();
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UI->ApplyCommand(command + fileName);

    // Output results
    // | Ene | C14 | Be10 | Cl36 |
    Number number;
    std::ofstream output;
    output.open("out.txt");
    for (size_t i = 0; i < number.vecC.size(); i++) {
        output << number.vecEnergy[i] << " " << number.vecC[i] << " " << number.vecBe[i] << " " <<  number.vecCl[i] << "\n";
    }
    output.close();


    delete runManager;
    return 0;
}
