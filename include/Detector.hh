#ifndef DETECTOR_H
#define DETECTOR_H

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include <vector>

class PhysicalVolume;

class Detector : public G4VUserDetectorConstruction
{
    public:
        Detector();
        ~Detector();

        virtual G4VPhysicalVolume* Construct();
        std::vector<G4Material*> ConstuctiAtmosLayersMaterial();
        std::vector<G4double> density;
        std::vector<G4double> altitude;
};


#endif