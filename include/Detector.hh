#ifndef DETECTOR_H
#define DETECTOR_H

#include "G4VUserDetectorConstruction.hh"

class PhysicalVolume;

class Detector : public G4VUserDetectorConstruction
{
    public:
        Detector();
        ~Detector();

        virtual G4VPhysicalVolume* Construct();
};


#endif