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


G4VPhysicalVolume* Detector::Construct()
{
    // World
    G4double World_x = 1. * km;
    G4double World_y = 1. * km;
    G4double World_z = 90. * km;
    G4Box* World  = new G4Box("WorldBox", World_x, World_y, World_z);

    G4NistManager* man = G4NistManager::Instance();
    G4Material* vacuum = man->FindMaterial("G4_Galactic");
    G4LogicalVolume* EnvWorld = new G4LogicalVolume(World, vacuum, "World", 0, 0, 0);

    G4VPhysicalVolume* phyWorld = new G4PVPlacement(0, G4ThreeVector(), EnvWorld, "World", 0, false, 0);




    // Atmosphere bins
    G4double Atmosphere_x = 1. * km;
    G4double Atmpsphere_y = 1. * km;
    G4double Atmosphere_z = 1. * km;
    G4double Atmosphere_z2 = 5. * km;
    G4double Atmosphere_z3 = 10. * km;
    G4Box* World_box = new G4Box("World1", Atmosphere_x, Atmpsphere_y, Atmosphere_z);
    G4Box* World_box2 = new G4Box("Wrold2", Atmosphere_x, Atmpsphere_y, Atmosphere_z2);
    G4Box* World_box3 = new G4Box("World3", Atmosphere_x, Atmpsphere_y, Atmosphere_z3);

    G4double density;


    // The following Logical Volume are constucted according US standard atmosphere
    // We consider the air from geant4 and only change the density
    // The data of US standard atmosphere is available in https://www.engineeringtoolbox.com/standard-atmosphere-d_604.html
    // The density of atmosphere


    density = 1.225 * kg / m3;
    G4Material* Air0 = man->BuildMaterialWithNewDensity("Air0", "Air", density);
    G4LogicalVolume* Atmosphere0;
    Atmosphere0 = new G4LogicalVolume(World_box, Air0, "Atmosphere0", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0. * km), Atmosphere0, "Atmosphere0", EnvWorld, false, 0);

    density = 1.112 * kg / m3;
    G4Material* Air1000 = man->BuildMaterialWithNewDensity("Air1000", "Air", density);
    G4LogicalVolume* Atmosphere1000;
    Atmosphere1000 = new G4LogicalVolume(World_box, Air1000, "Atmosphere1000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 1. * km), Atmosphere1000, "Atmosphere1000", EnvWorld, false, 0);

    density = 1.007 * kg / m3;
    G4Material* Air2000 = man->BuildMaterialWithNewDensity("Air2000", "Air", density);
    G4LogicalVolume* Atmosphere2000;
    Atmosphere2000 = new G4LogicalVolume(World_box, Air2000, "Atmosphere2000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 2. * km), Atmosphere2000, "Atmosphere2000", EnvWorld, false, 0);

    density = 0.9093 * kg / m3;
    G4Material* Air3000 = man->BuildMaterialWithNewDensity("Air3000", "Air", density);
    G4LogicalVolume* Atmosphere3000;
    Atmosphere3000 = new G4LogicalVolume(World_box, Air3000, "Atmosphere3000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 3. * km), Atmosphere3000, "Atmosphere3000", EnvWorld, false, 0);

    density = 0.8194 * kg / m3;
    G4Material* Air4000 = man->BuildMaterialWithNewDensity("Air4000", "Air", density);
    G4LogicalVolume* Atmosphere4000;
    Atmosphere4000 = new G4LogicalVolume(World_box, Air4000, "Atmosphere4000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 4. * km), Atmosphere4000, "Atmosphere4000", EnvWorld, false, 0);

    density = 0.7364 * kg / m3;
    G4Material* Air5000 = man->BuildMaterialWithNewDensity("Air5000", "Air", density);
    G4LogicalVolume* Atmosphere5000;
    Atmosphere5000 = new G4LogicalVolume(World_box, Air5000, "Atmosphere5000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 5. * km), Atmosphere5000, "Atmosphere5000", EnvWorld, false, 0);

    density = 0.6601 * kg / m3;
    G4Material* Air6000 = man->BuildMaterialWithNewDensity("Air6000", "Air", density);
    G4LogicalVolume* Atmosphere6000;
    Atmosphere6000 = new G4LogicalVolume(World_box, Air6000, "Atmosphere6000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 6. * km), Atmosphere6000, "Atmosphere6000", EnvWorld, false, 0);

    density = 0.5900 * kg / m3;
    G4Material* Air7000 = man->BuildMaterialWithNewDensity("Air7000", "Air", density);
    G4LogicalVolume* Atmosphere7000;
    Atmosphere7000 = new G4LogicalVolume(World_box, Air7000, "Atmosphere7000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 7. * km), Atmosphere7000, "Atmosphere7000", EnvWorld, false, 0);

    density = 0.5258 * kg / m3;
    G4Material* Air8000 = man->BuildMaterialWithNewDensity("Air8000", "Air", density);
    G4LogicalVolume* Atmosphere8000;
    Atmosphere8000 = new G4LogicalVolume(World_box, Air8000, "Atmosphere8000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 8. * km), Atmosphere8000, "Atmosphere8000", EnvWorld, false, 0);


    density = 0.4671 * kg / m3;
    G4Material* Air9000 = man->BuildMaterialWithNewDensity("Air9000", "Air", density);
    G4LogicalVolume* Atmosphere9000;
    Atmosphere9000 = new G4LogicalVolume(World_box, Air9000, "Atmosphere9000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 9. * km), Atmosphere9000, "Atmosphere9000", EnvWorld, false, 0);

    density = 0.4135 * kg / m3;
    G4Material* Air10000 = man->BuildMaterialWithNewDensity("Air10000", "Air", density);
    G4LogicalVolume* Atmosphere10000;
    Atmosphere10000 = new G4LogicalVolume(World_box2, Air10000, "Atmosphere10000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 10. * km), Atmosphere10000, "Atmosphere10000", EnvWorld, false, 0);

    density = 0.1948 * kg / m3;
    G4Material* Air15000 = man->BuildMaterialWithNewDensity("Air15000", "Air", density);
    G4LogicalVolume* Atmosphere15000;
    Atmosphere15000 = new G4LogicalVolume(World_box2, Air15000, "Atmosphere15000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 15. * km), Atmosphere15000, "Atmosphere15000", EnvWorld, false, 0);

    density = 0.08891 * kg / m3;
    G4Material* Air20000 = man->BuildMaterialWithNewDensity("Air20000", "Air", density);
    G4LogicalVolume* Atmosphere20000;
    Atmosphere20000 = new G4LogicalVolume(World_box2, Air20000, "Atmosphere20000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 20. * km), Atmosphere20000, "Atmosphere20000", EnvWorld, false, 0);

    density = 0.04008 * kg / m3;
    G4Material* Air25000 = man->BuildMaterialWithNewDensity("Air25000", "Air", density);
    G4LogicalVolume* Atmosphere25000;
    Atmosphere25000 = new G4LogicalVolume(World_box2, Air25000, "Atmosphere25000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 25. * km), Atmosphere25000, "Atmosphere25000", EnvWorld, false, 0);

    density = 0.01841 * kg / m3;
    G4Material* Air30000 = man->BuildMaterialWithNewDensity("Air30000", "Air", density);
    G4LogicalVolume* Atmosphere30000;
    Atmosphere30000 = new G4LogicalVolume(World_box3, Air30000, "Atmosphere30000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 30. * km), Atmosphere30000, "Atmosphere30000", EnvWorld, false, 0);

    density = 0.003996 * kg / m3;
    G4Material* Air40000 = man->BuildMaterialWithNewDensity("Air40000", "Air", density);
    G4LogicalVolume* Atmosphere40000;
    Atmosphere40000 = new G4LogicalVolume(World_box3, Air40000, "Atmosphere40000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 40. * km), Atmosphere40000, "Atmosphere40000", EnvWorld, false, 0);

    density = 0.001027 * kg / m3;
    G4Material* Air50000 = man->BuildMaterialWithNewDensity("Air50000", "Air", density);
    G4LogicalVolume* Atmosphere50000;
    Atmosphere50000 = new G4LogicalVolume(World_box3, Air50000, "Atmosphere50000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 50. * km), Atmosphere50000, "Atmosphere50000", EnvWorld, false, 0);

    density = 0.0003097 * kg / m3;
    G4Material* Air60000 = man->BuildMaterialWithNewDensity("Air60000", "Air", density);
    G4LogicalVolume* Atmosphere60000;
    Atmosphere60000 = new G4LogicalVolume(World_box3, Air60000, "Atmosphere60000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 26. * km), Atmosphere60000, "Atmosphere60000", EnvWorld, false, 0);

    density = 0.00008283 * kg / m3;
    G4Material* Air70000 = man->BuildMaterialWithNewDensity("Air70000", "Air", density);
    G4LogicalVolume* Atmosphere70000;
    Atmosphere70000 = new G4LogicalVolume(World_box3, Air70000, "Atmosphere70000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 70. * km), Atmosphere70000, "Atmosphere70000", EnvWorld, false, 0);

    density = 0.00001846 * kg / m3;
    G4Material* Air80000 = man->BuildMaterialWithNewDensity("Air80000", "Air", density);
    G4LogicalVolume* Atmosphere80000;
    Atmosphere80000 = new G4LogicalVolume(World_box3, Air80000, "Atmosphere80000", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 80. * km), Atmosphere80000, "Atmosphere80000", EnvWorld, false, 0);
}