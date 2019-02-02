#include "Detector.hh"
#include "Action.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif


#include "G4UImanager.hh"
#include "QGSP_BERT_HP.hh"

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
    G4VModularPhysicsList* physicsList = new QGSP_BERT_HP;
    physicsList->SetVerboseLevel(1);
    physicsList->SetCuts();
    runManager->SetUserInitialization(physicsList);
    runManager->SetUserInitialization(new Action);    


    G4UImanager* UI = G4UImanager::GetUIpointer();
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UI->ApplyCommand(command + fileName);

    NumberOfC14 Cnumber;
    std::vector<int> vec = Cnumber.GetNumberOfC14();
    std::ofstream output;
    output.open("out.txt");
    for (auto i : vec) {
        output << i << "\n";
    }
    output.close();


    delete runManager;
    return 0;
}
