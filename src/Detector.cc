#include "Detector.hh"
#include <vector>

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include <vector>
#include <fstream>
#include <iostream>


Detector::Detector() 
{
    std::ifstream input;
    input.open("Atmosphere.dat");
    if (!input) std::cout << "Error" << std::endl;
    G4double tmpAltitude;
    G4double tmpDensity;
    G4int NumOfAtmosBins = 87;
    while (!input.eof()) {
        input >> tmpAltitude;
        input >> tmpDensity;
        tmpAltitude = tmpAltitude * m;
        tmpDensity = tmpDensity * kg / m3;
        this->altitude.push_back(tmpAltitude);
        this->density.push_back(tmpDensity);
    }
}
Detector::~Detector() {}

G4VPhysicalVolume* Detector::Construct()
{
    // World
    G4double World_x = 5 * cm;
    G4double World_y = 5 * cm;
    G4double World_z = 43.5 * km;

    G4NistManager* man = G4NistManager::Instance();
    G4Material* vacuum = man->FindOrBuildMaterial("G4_Galactic");
  
    G4Box* solidWorld = new G4Box("World_S", World_x, World_y, World_z);     
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, vacuum, "World_L"); 
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, 0);        //overlaps checking




    // U.S. Standard Atmosphere 1976
    G4double Bin_x = 5 * cm;
    G4double Bin_y = 5 * cm;
    G4double Bin_z = 0.5 * km;

    G4Box* AtmosBin = new G4Box("AtmosBin", Bin_x, Bin_y, Bin_z);
    std::vector<G4Material*> Airs = this->ConstuctiAtmosLayersMaterial();
    std::vector<G4LogicalVolume*> AtmosLV; 
    for (size_t i = 0; i < this->altitude.size(); i++) {
        AtmosLV.push_back(new G4LogicalVolume(AtmosBin, Airs[i], "AtmosLV" + std::to_string(altitude[i])));
        new G4PVPlacement(0, G4ThreeVector(0, 0, -43 * km + altitude[i]), "AtmosP"+std::to_string(altitude[i]), AtmosLV[i],physWorld, false, 0, 0);
    }
    return physWorld;
}


std::vector<G4Material*> Detector::ConstuctiAtmosLayersMaterial()
{
    std::vector<G4Material*> Airs;
    G4NistManager* man = G4NistManager::Instance();

    for (size_t i = 0; i < this->altitude.size(); i++) {
        Airs.push_back(man->BuildMaterialWithNewDensity("Air_"+std::to_string(altitude[i]), "G4_AIR", this->density[i]));
    }
    return Airs;
}