#ifndef RUNACT_h
#define RUNACT_h 1

////////////////////////////////////////////////////////////////////////////////
//   RunAct.hh
//
//   This file is a header for RunAct class. In addition to the basic actions,
// user can add additional user-defined actions.
//
//                       - Jan 10th 2025, Hoyong Jeong (hoyong5419@korea.ac.kr)
////////////////////////////////////////////////////////////////////////////////

#include "G4UserRunAction.hh"

class G4Run;

class RunAct: public G4UserRunAction
{
  public:
	RunAct(double bp = 0);
	virtual ~RunAct();

	virtual void BeginOfRunAction(const G4Run*); 
	virtual void   EndOfRunAction(const G4Run*);

  private:
	double m_BP;
};

#endif
