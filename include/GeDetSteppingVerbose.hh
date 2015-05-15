


class GeDetSteppingVerbose;

#ifndef GeDetSteppingVerbose_h
#define GeDetSteppingVerbose_h 1

#include "G4SteppingVerbose.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class GeDetSteppingVerbose : public G4SteppingVerbose 
{
 public:
   
  GeDetSteppingVerbose();
 ~GeDetSteppingVerbose();

  void StepInfo();
  void TrackingStarted();

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
