

#ifndef GeDetMagneticField_H
#define GeDetMagneticField_H

#include "G4UniformMagField.hh"

class G4FieldManager;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


class GeDetMagneticField: public G4UniformMagField
{
  public:
  
   GeDetMagneticField(G4ThreeVector);  //  The value of the field
   GeDetMagneticField();               //  A zero field
  ~GeDetMagneticField();  
      
   //Set the field (fieldValue,0,0)
   void SetFieldValue(G4double fieldValue);
   void SetFieldValue(G4ThreeVector fieldVector);
      
   G4ThreeVector GetConstantFieldValue();

  protected:

      // Find the global Field Manager
      G4FieldManager* GetGlobalFieldManager();   // static 
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
