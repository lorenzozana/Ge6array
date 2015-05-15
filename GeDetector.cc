

#include "GeDetDetectorConstruction.hh"
#include "GeDetPhysicsList.hh"
#include "GeDetPrimaryGeneratorAction.hh"
#include "GeDetRunAction.hh"
#include "GeDetEventAction.hh"
#include "GeDetSteppingAction.hh"
#include "GeDetSteppingVerbose.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"
#include "QGSP_BIC.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv)
{
  // User Verbose output class
  //
  G4VSteppingVerbose* verbosity = new GeDetSteppingVerbose;
  G4VSteppingVerbose::SetInstance(verbosity);
  
  // Run manager
  //
  G4RunManager * runManager = new G4RunManager;

  // User Initialization classes (mandatory)
  //
  GeDetDetectorConstruction* detector = new GeDetDetectorConstruction;
  runManager->SetUserInitialization(detector);
  //
  // GeDetPrimaryGeneratorAction* pga = new GeDetPrimaryGeneratorAction;   //  Added 19/03/07x
//   runManager->SetUserInitialization(pga);

  //G4VUserPhysicsList* physics = new GeDetPhysicsList;
  //runManager->SetUserInitialization(physics);
  runManager->SetUserInitialization(new QGSP_BIC);
  
#ifdef G4VIS_USE
  // Visualization, if you choose to have it!
  //
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
#endif
   
  // User Action classes
  //
  G4VUserPrimaryGeneratorAction* gen_action = new GeDetPrimaryGeneratorAction(detector);
  runManager->SetUserAction(gen_action);
  //
  G4UserRunAction* run_action = new GeDetRunAction;
  runManager->SetUserAction(run_action);
  //
  //  G4UserEventAction* event_action = new GeDetEventAction((GeDetPrimaryGeneratorAction*)gen_action);
  G4UserEventAction* event_action = new GeDetEventAction(static_cast<GeDetPrimaryGeneratorAction*>(gen_action));
  runManager->SetUserAction(event_action);
  //
  G4UserSteppingAction* stepping_action = new GeDetSteppingAction;
  runManager->SetUserAction(stepping_action);

  // Initialize G4 kernel
  //
  runManager->Initialize();
      
  // Get the pointer to the User Interface manager
  //
  G4UImanager * UI = G4UImanager::GetUIpointer();  

  if(argc==1)  // Define (G)UI terminal for interactive mode
  { 
    // G4UIterminal is a (dumb) terminal
    //
    G4UIsession * session = 0;
#ifdef G4UI_USE_TCSH
      session = new G4UIterminal(new G4UItcsh);      
#else
      session = new G4UIterminal();
#endif
    UI->ApplyCommand("/control/execute vis.mac");    
    session->SessionStart();
    delete session;
  }
  else   // Batch mode
  { 
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UI->ApplyCommand(command+fileName);
  }

  // Free the store: user actions, physics_list and detector_description are
  //                 owned and deleted by the run manager, so they should not
  //                 be deleted in the main() program !

#ifdef G4VIS_USE
  delete visManager;
#endif

  delete runManager;
  delete verbosity;

  return 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

