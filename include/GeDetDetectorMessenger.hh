//


#ifndef GeDetDetectorMessenger_h
#define GeDetDetectorMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class GeDetDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class GeDetDetectorMessenger: public G4UImessenger
{
  public:
    GeDetDetectorMessenger(GeDetDetectorConstruction*);
   ~GeDetDetectorMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
    GeDetDetectorConstruction* myDetector;
    
    G4UIdirectory*             N02Dir;
    G4UIdirectory*             detDir;
    G4UIcmdWithAString*        TargMatCmd;
    G4UIcmdWithAString*        ChamMatCmd;    
    G4UIcmdWithADoubleAndUnit* FieldCmd;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

