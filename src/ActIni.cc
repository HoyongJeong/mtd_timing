////////////////////////////////////////////////////////////////////////////////
//   ActIni.cc
//
//   Definitions of ActIni class's member functions.
// All actions must be initialized here in order to use multi thread.
//
//                       - Jan 10th 2025, Hoyong Jeong (hoyong5419@korea.ac.kr)
////////////////////////////////////////////////////////////////////////////////

#include "ActIni.hh"
#include "PriGenAct.hh"
#include "RunAct.hh"
#include "EveAct.hh"
#include "SteAct.hh"

//////////////////////////////////////////////////
//   Constructor
//////////////////////////////////////////////////
ActIni::ActIni(double bp): G4VUserActionInitialization()
{
	m_BP = bp;
}

//////////////////////////////////////////////////
//   Destructor
//////////////////////////////////////////////////
ActIni::~ActIni()
{
}

//////////////////////////////////////////////////
//   Build For Master
//////////////////////////////////////////////////
void ActIni::BuildForMaster() const
{
	// So, this part is for master. This program is possible to do multithread.
	// A thread will care things as a master.
	SetUserAction(new RunAct());
}

//////////////////////////////////////////////////
//   Build
//////////////////////////////////////////////////
void ActIni::Build() const
{
	// All user actions are here.
	SetUserAction(new PriGenAct(m_BP));
	SetUserAction(new RunAct(m_BP));

	EveAct* EA = new EveAct();
	SetUserAction(EA);

	SetUserAction(new SteAct(EA));
}
