


#include "GeDetTrackerHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

G4Allocator<GeDetTrackerHit> GeDetTrackerHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GeDetTrackerHit::GeDetTrackerHit() {
  fhitID=0;
  fEdep=0.;
  fPos=G4ThreeVector();
  fTime=0.;
 fEAfterPulse=0;
 fAfterPulseTime=0;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GeDetTrackerHit::~GeDetTrackerHit() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GeDetTrackerHit::GeDetTrackerHit(const GeDetTrackerHit& right)
  : G4VHit()
{



  fhitID=right.fhitID;
 fEdep=right.fEdep;
 fEAfterPulse=right.fEAfterPulse;
 fAfterPulseTime=right.fAfterPulseTime;
  fPos+right.fPos;
  fTime=right.fTime;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

const GeDetTrackerHit& GeDetTrackerHit::operator=(const GeDetTrackerHit& right)
{

 fEAfterPulse=right.fEAfterPulse;
 fAfterPulseTime=right.fAfterPulseTime;

  fhitID=right.fhitID;
  fEdep=right.fEdep;
  fPos+right.fPos;
  fTime=right.fTime;
  return *this;


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4int GeDetTrackerHit::operator==(const GeDetTrackerHit& right) const
{
  return (this==&right) ? 1 : 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GeDetTrackerHit::Draw()
{
  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
  if(pVVisManager)
  {
    G4Circle circle(pos);
    circle.SetScreenSize(2.);
    circle.SetFillStyle(G4Circle::filled);
    G4Colour colour(1.,0.,0.);
    G4VisAttributes attribs(colour);
    circle.SetVisAttributes(attribs);
    pVVisManager->Draw(circle);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GeDetTrackerHit::Print()
{;

}



