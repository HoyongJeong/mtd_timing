#ifndef DETCON_h
#define DETCON_h 1

////////////////////////////////////////////////////////////////////////////////
//   DetCon.hh
//
//   This file is a header for DetCon class. It's for construction of whole
// geometry of simulation, which includes detector geometry.
//
//                       - Jan 10th 2025, Hoyong Jeong (hoyong5419@korea.ac.kr)
////////////////////////////////////////////////////////////////////////////////

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4UnionSolid.hh"
#include "G4Tubs.hh"

class G4VPhysicalVolume;

class DetCon: public G4VUserDetectorConstruction
{
  public:
	DetCon();
	virtual ~DetCon();
	virtual G4VPhysicalVolume* Construct();

  private:
	void DefineDimensions();
	void ConstructMaterials();
	void DestructMaterials();

  private:
	// Elements
	G4Element* m_ElH;
	G4Element* m_ElC;
	G4Element* m_ElN;
	G4Element* m_ElO;
	G4Element* m_ElAr;

	// Materials
	G4Material* m_VacMat;
	G4Material* m_AirMat;
	G4Material* m_SciMat;
	G4Material* m_PMTMat;
	G4MaterialPropertiesTable* m_SciMPT;
	G4MaterialPropertiesTable* m_AirMPT;
	G4MaterialPropertiesTable* m_AirST;

	// Dimensions and detector setup
	G4double m_LabX, m_LabY, m_LabZ;
	G4double m_SciX, m_SciY, m_SciZ;
	G4double m_PMTD, m_PMTT;

	// Geometry objects: World
	G4Box* m_WorldSolid;
	G4LogicalVolume* m_WorldLV;
	G4VPhysicalVolume* m_WorldPV;

	// Geometry objects: Lab
	G4Box* m_LabSolid;
	G4LogicalVolume* m_LabLV;
	G4VPhysicalVolume* m_LabPV;


	G4OpticalSurface* m_SciOpS;

	// Geometry objects: Scint
	G4Box* m_SciSolid0;
	G4Tubs* m_SciSolid1;
	G4Tubs* m_SciSolid2;
	G4UnionSolid* m_SciSolidm; // Intermediate solid
	G4UnionSolid* m_SciSolid;
	G4LogicalVolume* m_SciLV;
	G4VPhysicalVolume* m_SciPV;
	
	// Geometry objects: PMT0
	G4Tubs* m_PMT0Solid;
	G4LogicalVolume* m_PMT0LV;
	G4VPhysicalVolume* m_PMT0PV;

	// Geometry objects: PMT1
	G4Tubs* m_PMT1Solid;
	G4LogicalVolume* m_PMT1LV;
	G4VPhysicalVolume* m_PMT1PV;

	// Surface objects: Scint
	G4LogicalBorderSurface* m_SciLBS;
};

#endif
