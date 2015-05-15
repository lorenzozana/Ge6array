

#ifndef GeDetRunAction_h
#define GeDetRunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"


class G4Run;

class GeDetRunAction : public G4UserRunAction
{
  public:
    GeDetRunAction();
   ~GeDetRunAction();

  public:
    void BeginOfRunAction(const G4Run*);
    void EndOfRunAction(const G4Run*);
};



#endif





