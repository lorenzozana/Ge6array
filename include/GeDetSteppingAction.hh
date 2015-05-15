

#ifndef GeDetSteppingAction_h
#define GeDetSteppingAction_h 1

#include "G4UserSteppingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class GeDetSteppingAction : public G4UserSteppingAction
{
  public:
    GeDetSteppingAction();
   ~GeDetSteppingAction(){};

    void UserSteppingAction(const G4Step*);
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
