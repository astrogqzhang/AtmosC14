#include "/home/gqzhang/software/Geant/include/Geant4/G4RunManager.hh"
#include "/home/gqzhang/software/Geant/include/Geant4/G4UImanager.hh"

#include "/home/gqzhang/software/Geant/include/Geant4/ExG4DetectorConstruction01.hh"
#include "/home/gqzhang/software/Geant/include/Geant4/ExG4PhysicaList00.hh"
#include "/home/gqzhang/software/Geant/include/Geant4/ExG4ActionInitialization01.hh"

int main()
{
  G4RunManager* runManager = new G4RunManager;

  runManager->SetUserInitialization(new ExG4DetectorConstruction01);
  runManager->SetUserInitialization(new ExG4PhysicsList00);
  runManager->SetUserInitialization(new ExG4ActionInitialization01);

  // initialize G4 kernel
  runManager->Initialize();

  // get the pointer to the UI manager and set verbosities
  G4UImanager* UI = G4UImanager::GetUIpointer();
  UI->ApplyCommand("/run/verbose 1");
  UI->ApplyCommand("/event/verbose 1");
  UI->ApplyCommand("/tracking/verbose 1");

  // start a run
  int numberOfEvent = 3;
  runManager->BeamOn(numberOfEvent);

  // job termination
  delete runManager;
  return 0;
}
