



#include "GeDetEventAction.hh"
#include "GeDetTrackerHit.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4SDManager.hh"
#include "G4UImanager.hh"
#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "Randomize.hh"
#include "GeDetPrimaryGeneratorAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....


GeDetEventAction::GeDetEventAction(GeDetPrimaryGeneratorAction* pga)
{

 
   fpga = pga;
  //eventMessenger = new MuGeEventActionMessenger(this);
  germCollID=-1;
  
  //Construct Root output
  fMuGeFile= new TFile("MuGe.root","RECREATE","MuGermanium Simulation");
  fMuGeNtuple= new TNtuple("MuGe","MuGeillator Output","Ecount:edep1:edep2:edep3:edep4:edep5:edep6:edep7:edep8:afterpulse");
 
  totEvents=0; 
 
}


// }
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

GeDetEventAction::~GeDetEventAction()
{

  if(fMuGeNtuple&&fMuGeFile)fMuGeNtuple->Write();
  if(fMuGeFile)fMuGeFile->Close();
  // delete fMuGeNtuple;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void GeDetEventAction ::BeginOfEventAction(const G4Event* evt)
{
 G4int evtNb = evt->GetEventID();

 if (germCollID==-1)
   {
    G4SDManager * SDman = G4SDManager::GetSDMpointer();
       germCollID = SDman->GetCollectionID("GeDetTrackerHitGeDetTrackerSD");
   } 

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void GeDetEventAction::EndOfEventAction(const G4Event* evt)
{

  totEvents++;
  //  G4cout<<"EndofEventAction"<<G4endl;
  G4RunManager *runMan = G4RunManager::GetRunManager();
  G4int runID=runMan->GetCurrentRun()->GetRunID();
  
  G4int evtNb = evt->GetEventID();

  G4HCofThisEvent* HCE = evt->GetHCofThisEvent();
  GeDetTrackerHitsCollection* SHC = NULL;
  G4double Edep[9]={0,0,0,0,0,0,0,0,0};

  if (HCE){
    SHC = (GeDetTrackerHitsCollection*)(HCE->GetHC(germCollID));
    //  printf("inhere\n");
  }
  if(!SHC){return;}

  //  printf("here\n");
  G4double edep=0;
  // G4cout<<SHC<<G4endl;
  //Lets loop over the hits!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //store the hit infobg
  Float_t APTime=0;
  for(G4int i=0;i<SHC->entries();i++)
    {
      GeDetTrackerHit* hit = (GeDetTrackerHit *)(SHC->GetHit(i));
      //  G4cout<<i<<" "<<hit->GetHitID()<<" "<<hit->GetEdep()<<G4endl;
      Edep[hit->GetHitID()] = hit->GetEdep();
      if(APTime==0) APTime = hit->GetAfterPulseTime();    

	//printf("after pulse 1: %f\n\n", APTime/ms);}

    }
 

  fMuGeNtuple->Fill(fpga->GetRandEnergy(),Edep[0]/CLHEP::MeV,Edep[1]/CLHEP::MeV,Edep[2]/CLHEP::MeV,Edep[3]/CLHEP::MeV,Edep[4]/CLHEP::MeV,Edep[5]/CLHEP::MeV,Edep[6]/CLHEP::MeV,Edep[7]/CLHEP::MeV,APTime/CLHEP::ms);
 // printf("afterpulse: %f\n",Edep[8]);//
//  printf("Edep1: %f\n\n", Edep[0]/MeV); 
//  printf("Edep2: %f\n\n", Edep[1]/MeV); 
//  printf("Edep3: %f\n\n", Edep[2]/MeV); 
//  printf("Edep4: %f\n\n", Edep[3]/MeV); 
//  printf("Edep5: %f\n\n", Edep[4]/MeV); 
//  printf("Edep6: %f\n\n", Edep[5]/MeV); 
//  printf("Front Si: %f\n\n", Edep[6]/MeV);
//  printf("Back Si: %f\n\n", Edep[7]/MeV);
 // printf("incident : %f\n\n",fpga->GetRandEnergy() );
 //printf("after pulse 2: %f\n\n",Edep[8] );
 //G4cout<<"after pulse 2: "<<APTime/ms<<G4endl;
//  G4cout<<"Total energy deposited in the Ge "<<Edep[0]+Edep[1]+Edep[2]+Edep[3]+Edep[4]+Edep[5]/MeV<<G4endl;
// G4cout<<"Total energy deposited in the DSSDs "<<Edep[6]+Edep[7]/MeV<<G4endl;

 if (G4VVisManager::GetConcreteInstance())
    {
     G4TrajectoryContainer* trajectoryContainer = evt->GetTrajectoryContainer();
     G4int n_trajectories = 0;
     if (trajectoryContainer) n_trajectories = trajectoryContainer->entries();

     for (G4int i=0; i<n_trajectories; i++) 
        { G4Trajectory* trj = (G4Trajectory*)
	                                ((*(evt->GetTrajectoryContainer()))[i]);
         trj->DrawTrajectory();
          
        }
  }


}
