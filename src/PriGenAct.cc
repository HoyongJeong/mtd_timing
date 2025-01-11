////////////////////////////////////////////////////////////////////////////////
//   PriGenAct.cc
//
//   Definitions of PriGenAct class's member functions.
//
//                       - Jan 10th 2025, Hoyong Jeong (hoyong5419@korea.ac.kr)
////////////////////////////////////////////////////////////////////////////////


#include "G4ParticleGun.hh"
#include "G4IonTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "Randomize.hh"

#include "PriGenAct.hh"

//////////////////////////////////////////////////
//   Constructor and destructor
//////////////////////////////////////////////////
PriGenAct::PriGenAct(double bp)
{
	m_PG = new G4ParticleGun();

	// Gun position
	m_WorldX = 100. * mm;
	m_BeamPY =   0. * mm; 
	m_BeamPZ =  bp  * mm;

	// Set particle definition
	m_PT = G4ParticleTable::GetParticleTable();
	m_Par = m_PT -> FindParticle("mu-");
	m_PG -> SetParticleDefinition(m_Par);

	// Momentum
	m_MomDir = G4ThreeVector(1., 0., 0.);
	m_PG -> SetParticleMomentumDirection(m_MomDir);

	// Kinetic energy
	m_KinEgy = 3000. * MeV;
	m_PG -> SetParticleEnergy(m_KinEgy);

	// Gun position
	m_GunPos = G4ThreeVector(- m_WorldX / 2., m_BeamPY, m_BeamPZ);
	m_PG -> SetParticlePosition(m_GunPos);
}

PriGenAct::~PriGenAct()
{
	delete m_PG;
}

//////////////////////////////////////////////////
//   Shoot!
//////////////////////////////////////////////////
void PriGenAct::GeneratePrimaries(G4Event* anEvent)
{
	m_PG -> GeneratePrimaryVertex(anEvent);
}
