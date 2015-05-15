
 
#ifndef GeDetPrimaryGeneratorAction_h
#define GeDetPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "TROOT.h"
#include "TFile.h"
#include "TNtuple.h"
#include "globals.hh"

class GeDetDetectorConstruction;
class G4ParticleGun;
class G4Event;
class GeDetPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  GeDetPrimaryGeneratorAction(){};    
  GeDetPrimaryGeneratorAction(GeDetDetectorConstruction*);    
  ~GeDetPrimaryGeneratorAction();
  
public:
  void GeneratePrimaries(G4Event*);
  
  
  
  //  inline void SetEcount(int Ecount){fEcount = Ecount;};
  
  
  
  inline void SetRandEnergy(G4double randEnergy){fRandEnergy = randEnergy;};
  inline double GetRandEnergy() {return fRandEnergy;};
  
private:
  G4ParticleGun* particleGun;
  GeDetDetectorConstruction* myDetector;
  
  //  //ROOT STUFF
  TFile* fEcountFile;
  TNtuple* fEcountNtuple;
  TString fFilePion;
  
  
  double fRandEnergy;
  int fCounter;
  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif


