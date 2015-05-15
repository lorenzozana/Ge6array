
 
#ifndef GeDetEventAction_h
#define GeDetEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "GeDetTrackerHit.hh"
#include "TROOT.h"
#include "TFile.h"
#include "TNtuple.h"
#include "GeDetPrimaryGeneratorAction.hh"

class GeDetEventAction : public G4UserEventAction
{
public:
  GeDetEventAction(){};
  GeDetEventAction(GeDetPrimaryGeneratorAction*);
  virtual ~GeDetEventAction();
  
public:
  virtual void   BeginOfEventAction(const G4Event*);
  virtual void   EndOfEventAction(const G4Event*);
  // GeDetPrimaryGeneratorAction(GeDetDetectorConstruction*);    
  
private:
  G4int                       germCollID;                
  
  G4int totEvents; //total number of events processed
  
  //ROOT STUFF
  TFile* fMuGeFile;
  TNtuple* fMuGeNtuple;
  TString fFileName;
  
GeDetPrimaryGeneratorAction* fpga;
  
};



#endif


    
