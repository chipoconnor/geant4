//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: ExN04EMPhysics.cc,v 1.4 2003/12/03 11:03:06 gcosmo Exp $
// GEANT4 tag $Name: geant4-07-01 $
//
// 

#include "ExN04EMPhysics.hh"

#include "globals.hh"
#include "G4ios.hh"
#include <iomanip>   


ExN04EMPhysics::ExN04EMPhysics(const G4String& name)
               :  G4VPhysicsConstructor(name)
{
}

ExN04EMPhysics::~ExN04EMPhysics()
{
}

#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"

#include "G4Gamma.hh"

#include "G4Electron.hh"
#include "G4Positron.hh"

#include "G4NeutrinoE.hh"
#include "G4AntiNeutrinoE.hh"

void ExN04EMPhysics::ConstructParticle()
{
  // gamma
  G4Gamma::GammaDefinition();
 
  // electron
  G4Electron::ElectronDefinition();
  G4Positron::PositronDefinition();
  G4NeutrinoE::NeutrinoEDefinition();
  G4AntiNeutrinoE::AntiNeutrinoEDefinition();
}


#include "G4ProcessManager.hh"


void ExN04EMPhysics::ConstructProcess()
{
  G4ProcessManager * pManager = 0;
  
  // Gamma Physics
  pManager = G4Gamma::Gamma()->GetProcessManager();
  pManager->AddDiscreteProcess(&thePhotoEffect);
  pManager->AddDiscreteProcess(&theComptonEffect);
  pManager->AddDiscreteProcess(&thePairProduction);

  // Electron Physics
  pManager = G4Electron::Electron()->GetProcessManager();

  pManager->AddProcess(&theElectronMultipleScattering, -1, 1, 1);
  pManager->AddProcess(&theElectronIonisation,         -1, 2, 2);
  pManager->AddProcess(&theElectronBremsStrahlung,     -1, 3, 3);  


  //Positron Physics
  pManager = G4Positron::Positron()->GetProcessManager();
 
  pManager->AddProcess(&thePositronMultipleScattering, -1, 1, 1);
  pManager->AddProcess(&thePositronIonisation,         -1, 2, 2);
  pManager->AddProcess(&thePositronBremsStrahlung,     -1, 3, 3);  
  pManager->AddProcess(&theAnnihilation,                0,-1, 4);  

}


