#include "RunAction.hh"
#include <fstream>

#include "G4Run.hh"

RunAction::RunAction() : G4UserRunAction() 
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
    std::ofstream out;
    out.open("output.txt");
    for (auto i : NumberOfC14) {
        out << i << "\n";
    }
    out.close();
}