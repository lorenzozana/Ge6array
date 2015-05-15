
#ifndef GeDetTrackerSD_h
#define GeDetTrackerSD_h 1

#include "G4VSensitiveDetector.hh"
#include "globals.hh"
#include "GeDetTrackerHit.hh"
#include "GeDetTrackerSD.hh"
#include "G4Allocator.hh"

class G4HCofThisEvent;
class G4Step;

class GeDetTrackerSD  : public G4VSensitiveDetector
{
public:
  
GeDetTrackerSD(G4String);
  ~GeDetTrackerSD();
  
  void Initialize(G4HCofThisEvent*);
  G4bool ProcessHits(G4Step* astep,G4TouchableHistory* ROHist);
  void EndOfEvent(G4HCofThisEvent*);
  void clear();
  void DrawAll();
  void PrintAll();
 


private:
  
  GeDetTrackerHitsCollection* fCollection;  
  G4int fHCID;

  G4int * fhitID;
  G4int fNelements;
  G4int fNhits;

  G4int fNAfterHits;
  G4int  fAfterPulseHit;

 
};

#endif
