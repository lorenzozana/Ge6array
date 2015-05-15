

#include "GeDetPrimaryGeneratorAction.hh"
#include "GeDetDetectorConstruction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"
#include "Randomize.hh"
#include "GeDetDetectorConstruction.hh"

GeDetPrimaryGeneratorAction::GeDetPrimaryGeneratorAction(
                                               GeDetDetectorConstruction* myDC)
:myDetector(myDC)
{

  fCounter = 0;

  //Construct Root output
  // fEcountFile= new TFile("Ecount.root","RECREATE","MuGermanium Simulation");
  //fEcountNtuple= new TNtuple("Ecount","EnergyOutput","Ecount");
  
  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);

// default particle

//   G4double lowEnergy = 10;
//   G4double energyRange = 180;
//   G4double randEnergy = lowEnergy + energyRange*G4UniformRand();

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle("pi+");
  
  particleGun->SetParticleDefinition(particle);
   particleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.));
  //  particleGun->SetParticleEnergy(randEnergy*MeV);

  // G4cout<<"Energy of the particle is:  "<<randEnergy<<" MeV"<<G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
GeDetPrimaryGeneratorAction::~GeDetPrimaryGeneratorAction()
{
  delete particleGun;
  // fEcountFile->cd();
  // if(fEcountNtuple&&fEcountFile)fEcountNtuple->Write();
  // if(fEcountFile)fEcountFile->Close();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GeDetPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{ 
  G4double position = -10.*(myDetector->GetWorldFullLength());
  
  // G4double xgun = 1.5-( 3*G4UniformRand());
  // G4double ygun = 1.5-(3*G4UniformRand());
  
  // G4cout<<"initial xy coords of the particle is:  "<<xgun<<ygun<<G4endl; 
  
  //  particleGun->SetParticlePosition(G4ThreeVector(xgun*cm,ygun*cm,134*mm));
  particleGun->SetParticlePosition(G4ThreeVector(0*CLHEP::cm,0*CLHEP::cm,134*CLHEP::mm));
  
  //The solid angle this maps out corresponds to the 8mm radius cut on the back DSSD in the expt (given the dimensions):
  
  
  // G4double xgunAngle =0.1-( 0.2*G4UniformRand());
  // G4double ygunAngle =0.1-( 0.2*G4UniformRand());
  
  // particleGun->SetParticleMomentumDirection(G4ThreeVector(xgunAngle,ygunAngle,-1.));
  
  G4double lowEnergy = 0;
  G4double energyRange = 150;
  //G4double randEnergy = lowEnergy + energyRange*G4UniformRand();
  //particleGun->SetParticleEnergy(randEnergy);
  //  G4cout<<"Energy of the particle is:  "<<randEnergy<<" MeV"<<G4endl;
  fRandEnergy = lowEnergy + energyRange*G4UniformRand();
  particleGun->SetParticleEnergy(fRandEnergy);
  
  //   G4double particlechoice = G4UniformRand();
  
  //   G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  
  
//   if (particlechoice < 0.3333333333)
//     {
  
// G4ParticleDefinition* particle = particleTable->FindParticle("pi+");
//     }
//   if (particlechoice >= 0.3333333333 && particlechoice < 0.666666667)
//     {
  
// G4ParticleDefinition* particle = particleTable->FindParticle("e-");
//     }
//   if (particlechoice >= 0.666666667)
//     {
  
// G4ParticleDefinition* particle = particleTable->FindParticle("proton");
//     }
  
//  particleGun->SetParticleDefinition(particle);
  
  // fEcountNtuple->Fill(randEnergy/MeV);
  
  fCounter++;
  
  if(fCounter%1000==0){
    G4cout<<"count number"  <<fCounter<<G4endl;
    G4cout<<"Now then, here's the random energy   "<<fRandEnergy<<G4endl;
  }
  particleGun->GeneratePrimaryVertex(anEvent);
  
  



}









//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

