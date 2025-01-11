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
	G4Element* m_ElH;   //  1
	G4Element* m_ElC;   //  6
	G4Element* m_ElN;   //  7
	G4Element* m_ElO;   //  8
	G4Element* m_ElSi;  // 14
	G4Element* m_ElAr;  // 18
	G4Element* m_ElY;   // 39
	G4Element* m_ElLu;  // 71


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
	G4double m_PMTX, m_PMTY, m_PMTZ;

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
	G4Box* m_SciSolid1;
	G4Box* m_SciSolid2;
	G4UnionSolid* m_SciSolidm; // Intermediate solid
	G4UnionSolid* m_SciSolid;
	G4LogicalVolume* m_SciLV;
	G4VPhysicalVolume* m_SciPV;
	
	// Geometry objects: SiPM0
	G4Box* m_PMT0Solid;
	G4LogicalVolume* m_PMT0LV;
	G4VPhysicalVolume* m_PMT0PV;

	// Geometry objects: SiPM1
	G4Box* m_PMT1Solid;
	G4LogicalVolume* m_PMT1LV;
	G4VPhysicalVolume* m_PMT1PV;

	// Surface objects: Scint
	G4LogicalBorderSurface* m_SciLBS;
};

#endif
