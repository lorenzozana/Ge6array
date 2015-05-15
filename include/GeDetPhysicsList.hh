#ifndef GeDetPhysicsList_H
#define GeDetPhysicsList_H 1

#include "globals.hh"
#include "G4VUserPhysicsList.hh"

class GeDetPhysicsList : public G4VUserPhysicsList
{
  public:
    GeDetPhysicsList();
    ~GeDetPhysicsList();
 
  protected:
    // Construct particles and processes
    void ConstructParticle();
    void ConstructProcess();

    //
    void SetCuts();

  protected:
    // these methods Construct particles
    void ConstructBosons();
    void ConstructLeptons();
    void ConstructMesons();
    void ConstructBaryons();

  protected:
    // these methods Construct physics processes and register them
    void ConstructGeneral();
    void ConstructEM();
    void ConstructOp();

};

#endif

