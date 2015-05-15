#include "G4RunManager.hh"
#include "GeDetTrackerSD.hh"
#include "GeDetTrackerHit.hh"
#include "GeDetEventAction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Step.hh"
#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"
#include "G4SDManager.hh"
#include "stdio.h"
#include "G4Allocator.hh"

GeDetTrackerSD::GeDetTrackerSD(G4String name):G4VSensitiveDetector(name)
{
  collectionName.insert(G4String("GeDetTrackerHit")+name);
  // G4cout<<"Collection Name is "<<collectionName[0]<<G4endl;

  fCollection=NULL;

  fNelements=8;//numbering starts from 1 not 0
  fhitID=new G4int[fNelements];
  for(G4int i=0;i<fNelements;i++)fhitID[i]=-1;

  fHCID=-1;
  fNhits=0;
  fAfterPulseHit=0;
}


GeDetTrackerSD::~GeDetTrackerSD()
{

}

void GeDetTrackerSD ::Initialize(G4HCofThisEvent*)
{
  //Hits collections are deleted in G4RunManager, DoEventLoop
  //This calls StackPreviousEvent which deletes the G4Event
  //This deletes the hit collection for the event and thus MuGeHit s
  //G4cout<<"void MuGeSD::Initialize "<<SensitiveDetectorName<<G4endl;
  fCollection = new GeDetTrackerHitsCollection(SensitiveDetectorName,collectionName[0]);

}

G4bool GeDetTrackerSD::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{ 
  
  G4double edep = aStep->GetTotalEnergyDeposit();
  if ((edep/CLHEP::keV == 0.)) return false;      
 
  //Define the pion decay to a muon and use this to apply a cut on the event accumulation.

  // G4double pionDecay = 0.0022 * ms ;

  // G4cout<<"pay attention!!!!  the pion decay time is :" <<pionDecay<<G4endl;


  // This TouchableHistory is used to obtain the physical volume
  // of the hit
  G4TouchableHistory* theTouchable
    = (G4TouchableHistory*)(aStep->GetPreStepPoint()->GetTouchable());
  
  G4VPhysicalVolume* volume=theTouchable->GetVolume();
  G4int id=volume->GetCopyNo()-1;
  // G4cout<<volume->GetName()<<" id "<<id <<" edep "<<edep/MeV<<" "<<fhitID[id]<<G4endl;
    G4double promptTime = aStep->GetPreStepPoint()->GetGlobalTime();
    // if(promptTime<400*ns)
    // {

     if (fhitID[id]==-1  ){
       //if this crystal has already had a hit
       //don't make a new one, add on to old one.   
       //G4cout<<"Make hit "<<fCollection<<G4endl;    
       //GeDetTrackerHit* Hit = new GeDetTrackerHit;   
       GeDetTrackerHit* Hit = new GeDetTrackerHit();
       Hit->AddEnergy(edep);
       Hit->SetPos(aStep->GetPreStepPoint()->GetPosition());
       Hit->SetTime(aStep->GetPreStepPoint()->GetGlobalTime());
	    
       Hit->SetHitID(id);
       
       fhitID[id] = fCollection->insert(Hit) -1;
       // Hit->SetHitID(fhitID[id]);
       //printf("hitid: %d\n\n",fhitID[id]);
       fNhits++;

     }
  
     else // This is not new
       {
	 (*fCollection)[fhitID[id]]->AddEnergy(edep);
    //printf("inotherfnc***************  %d  \n",fhitID[id]);
    //  G4cout<<"Add The edep!!!!!!!!!!!!!!!!!!   "<<id<<" "<<(*fCollection)[fhitID[id]]->GetEdep()<<G4endl;
       }
   

 if(promptTime>0.001*CLHEP::ms && promptTime<0.007*CLHEP::ms && fAfterPulseHit==0)  //This is for the muon decay to act as a cut.
   {
     fAfterPulseHit=1;
     if (fhitID[id]==-1  ){
       //if this crystal has already had a hit
       //don't make a new one, add on to old one.   
  
       GeDetTrackerHit* Hit = new GeDetTrackerHit();
      Hit->AddAfterPulseEnergy(edep);
      Hit->SetAfterPulseTime(aStep->GetPreStepPoint()->GetGlobalTime());
    
       Hit->SetHitID(id);
       
       fhitID[id] = fCollection->insert(Hit) -1;
       // Hit->SetHitID(fhitID[id]);
       //printf("hitid: %d\n\n",fhitID[id]);
       fNhits++;

     }
  
     else // This is not new
       {
	 (*fCollection)[fhitID[id]]->AddAfterPulseEnergy(edep);
	 (*fCollection)[fhitID[id]]->SetAfterPulseTime(aStep->GetPreStepPoint()->GetGlobalTime());

       }
     //   printf("after pulse 2: %f\n\n", );
     //   printf("after pulse 2: %f\n\n",Hit->GetAfterPulseTime() );

}





  //G4cout<<"done "<<fNhits<<G4endl;
  return true;
}

void GeDetTrackerSD::EndOfEvent(G4HCofThisEvent* HCE)
{
  fAfterPulseHit=0;
  // G4cout<<"EndOfEvent( "<<fHCID<<" "<<fCollection<<" "<<fNhits<<G4endl;
  if(fHCID<0) fHCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  if(fNhits)  HCE->AddHitsCollection(fHCID,fCollection);
  //G4cout<<"EndOfEvent( "<<G4endl;
  fNhits=0;
  //reset hit arrays
  for (G4int i=0;i<fNelements;i++) 
    {
      fhitID[i]=-1;
    }
  //G4cout<<"EndOfEvent( done"<<G4endl;
}

void GeDetTrackerSD::clear()
{} 


void GeDetTrackerSD ::DrawAll()
{} 


void GeDetTrackerSD::PrintAll()
{} 
