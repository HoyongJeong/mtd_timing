#ifndef ACTINI_h
#define ACTINI_h 1

////////////////////////////////////////////////////////////////////////////////
//   ActIni.hh
//
//   This file is a header for ActIni class. Every actions are initialized
// through this class.
//
//                       - Jan 10th 2025, Hoyong Jeong (hoyong5419@korea.ac.kr)
////////////////////////////////////////////////////////////////////////////////

#include "G4VUserActionInitialization.hh"
#include "G4String.hh"

class ActIni: public G4VUserActionInitialization
{
  public:
	ActIni(double bp = 0);
	virtual ~ActIni();

	virtual void BuildForMaster() const;
	virtual void Build() const;

  private:
	double m_BP;
};

#endif
