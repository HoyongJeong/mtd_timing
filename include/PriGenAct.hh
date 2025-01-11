#ifndef PRIGENACT_h
#define PRIGENACT_h 1

////////////////////////////////////////////////////////////////////////////////
//   PriGenAct.hh
//
//   This file is a header for PriGenAct class. You can set primary beam
// options in this class.
//
//                       - Jan 10th 2025, Hoyong Jeong (hoyong5419@korea.ac.kr)
////////////////////////////////////////////////////////////////////////////////

#include <vector>

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"
#include "G4ParticleDefinition.hh"
#include "G4Event.hh"

class G4ParticleGun;

class PriGenAct: public G4VUserPrimaryGeneratorAction
{
  public:
	PriGenAct(double bp = 0);
	~PriGenAct();

	virtual void GeneratePrimaries(G4Event* anEvent);

  private:
	G4ParticleGun*   m_PG;
	G4ParticleTable* m_PT;

	G4double m_BeamPY, m_BeamPZ;
	G4double m_WorldX;
	G4ThreeVector m_GunPos;
	G4ParticleDefinition* m_Par;
	G4ThreeVector m_MomDir;
	G4double m_KinEgy;
};

#endif
