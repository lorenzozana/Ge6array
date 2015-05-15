

#ifndef GeDetTrackerHit_h
#define GeDetTrackerHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class GeDetTrackerHit : public G4VHit
{
   public:

      GeDetTrackerHit();
     ~GeDetTrackerHit();
      GeDetTrackerHit(const GeDetTrackerHit&);
      const GeDetTrackerHit& operator=(const GeDetTrackerHit&);
      G4int operator==(const GeDetTrackerHit&) const;

      inline void* operator new(size_t);
      inline void  operator delete(void*);

      void Draw();
      void Print();

//   public:
  
//       void SetTrackID  (G4int track)      { trackID = track; };
//       void SetTubeNb(G4int tube)      { tubeNb = tube; };  
//       void SetEdep     (G4double de)      { edep = de; };
//       void SetPos      (G4ThreeVector xyz){ pos = xyz; };
      
//       G4int GetTrackID()    { return trackID; };
//       G4int GetTubeNb()  { return tubeNb; };
//       G4double GetEdep()    { return edep; };      
//       G4ThreeVector GetPos(){ return pos; };
      
//   private:
  
//       G4int         trackID;
//       G4int         tubeNb;
//       G4double      edep;
       G4ThreeVector pos;



protected:
  
  G4double fEdep;  // Energy deposited in detector
  G4ThreeVector fPos; // Position of the hit (in what frame?)
  G4double fTime; // global time of hit
  G4int fhitID; // crystal number

  G4double fEAfterPulse; // Energy of the after pulse
  G4double fAfterPulseTime; //Time of after pulse

public:
  inline void AddAfterPulseEnergy (G4double de){fEAfterPulse += de;};
  inline void AddEnergy(G4double de) {fEdep += de;};
  inline void SetPos(G4ThreeVector pos) {fPos=pos;};
  inline void SetTime(G4double t) {fTime = t;};
  inline void SetHitID(G4int id){fhitID = id;};
  inline void SetEAfterPulse(G4double EPulse){fEAfterPulse = EPulse;};
  inline void SetAfterPulseTime(G4double PulseTime){fAfterPulseTime = PulseTime;};

  inline G4double GetEdep()     { return fEdep; };
  inline G4ThreeVector GetPos() { return fPos; };
  inline G4double    GetTime()   { return fTime; };
  inline G4int GetHitID() {return fhitID;};
  inline G4double GetEAfterPulse() {return fEAfterPulse;};
  inline G4double GetAfterPulseTime() {return fAfterPulseTime;};

  // G4double pionDecay;  //Time of pion decay


};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// typedef G4THitsCollection<GeDetTrackerHit> GeDetTrackerHitsCollection;

// extern G4Allocator<GeDetTrackerHit> GeDetTrackerHitAllocator;

// //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// inline void* GeDetTrackerHit::operator new(size_t)
// {
//   void *aHit;
//   aHit = (void *) GeDetTrackerHitAllocator.MallocSingle();
//   return aHit;
// }

// //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// inline void GeDetTrackerHit::operator delete(void *aHit)
// {
//   GeDetTrackerHitAllocator.FreeSingle((GeDetTrackerHit*) aHit);
// }

// //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// #endif




typedef G4THitsCollection<GeDetTrackerHit> GeDetTrackerHitsCollection;

extern G4Allocator<GeDetTrackerHit> GeDetTrackerHitAllocator;


inline void *GeDetTrackerHit ::operator new(size_t)
{
  void* aHit;
  aHit = (void*)GeDetTrackerHitAllocator.MallocSingle();
  return aHit;
}


inline void GeDetTrackerHit::operator delete(void* aHit)
{
  GeDetTrackerHitAllocator.FreeSingle((GeDetTrackerHit*) aHit);
}

#endif
