

#include "GeDetSteppingAction.hh"
#include "G4SteppingManager.hh"
#include "G4Track.hh"
#include "G4StepPoint.hh"



GeDetSteppingAction::GeDetSteppingAction()
{ }



void GeDetSteppingAction::UserSteppingAction(const G4Step* aStep)
{
  G4Track * theTrack = aStep->GetTrack();
  if(theTrack->GetTrackStatus()!=fAlive) { return; }
  
  G4double cutTime = aStep->GetPreStepPoint()->GetGlobalTime();
  if (cutTime > 0.007*CLHEP::ms )
    {
      theTrack->SetTrackStatus(fStopAndKill);
    }
  

 else
   {
     theTrack->SetTrackStatus(fStopAndKill);
   }


} 




// void RE01SteppingAction::UserSteppingAction(const G4Step * theStep)
// {
//   // Suspend a track if it is entering into the calorimeter

//   // check if it is alive
//   G4Track * theTrack = theStep->GetTrack();
//   if(theTrack->GetTrackStatus()!=fAlive) { return; }

//   // get region information
//   G4StepPoint * thePrePoint = theStep->GetPreStepPoint();
//   G4LogicalVolume * thePreLV = thePrePoint->GetPhysicalVolume()->GetLogicalVolume();
//   RE01RegionInformation* thePreRInfo
//    = (RE01RegionInformation*)(thePreLV->GetRegion()->GetUserInformation());
//   G4StepPoint * thePostPoint = theStep->GetPostStepPoint();
//   G4LogicalVolume * thePostLV = thePostPoint->GetPhysicalVolume()->GetLogicalVolume();
//   RE01RegionInformation* thePostRInfo
//    = (RE01RegionInformation*)(thePostLV->GetRegion()->GetUserInformation());

//   // check if it is entering to the calorimeter volume
//   if(!(thePreRInfo->IsCalorimeter()) && (thePostRInfo->IsCalorimeter()))
//   { theTrack->SetTrackStatus(fSuspend); }
// }
 
