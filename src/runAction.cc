#include "RunAction.hh"
#include "HistoManager.hh"

#include "G4Run.hh"

RunAction::RunAction() : G4UserRunAction(), fHistoManager(0)
{
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run*)
{
}

void RunAction::EndOfRunAction(const G4Run*)
{
}