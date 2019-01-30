#ifndef RUNACTION_H
#define RUNACTION_H

#include "G4UserRunAction.hh"
#include "globals.hh"
#include <vector>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Run;
class HistoManager;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class RunAction : public G4UserRunAction
{
  public:
   RunAction();
  ~RunAction();

   virtual void BeginOfRunAction(const G4Run*);
   virtual void EndOfRunAction(const G4Run*);

};


#endif