#ifndef PRIMARYGENERATORACTION_H
#define PRIMARYGENERATORACTION_H

#include "G4VUserPrimaryGeneratorAction.hh"

class G4GeneralParticleSource;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
    public:
        PrimaryGeneratorAction();
        ~PrimaryGeneratorAction();

        virtual void GeneratePrimaries(G4Event*);

  private:
        G4GeneralParticleSource* fParticleGun;
};

#endif