//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id$
//
// Author: Mathieu Karamitros (kara@cenbg.in2p3.fr)
//
// WARNING : This class is released as a prototype.
// It might strongly evolve or even disapear in the next releases.
//
// History:
// -----------
// 10 Oct 2011 M.Karamitros created
//
// -------------------------------------------------------------------

#include "G4DNAChemistryManager.hh"

#include "G4Scheduler.hh"
#include "G4SystemOfUnits.hh"
#include "G4Molecule.hh"
#include "G4H2O.hh"
#include "G4DNAMolecularReactionTable.hh"
#include "G4DNAWaterExcitationStructure.hh"
#include "G4DNAWaterIonisationStructure.hh"
#include "G4Electron_aq.hh"
#include "G4MolecularConfiguration.hh"
#include "G4VMoleculeCounter.hh"
#include "G4VUserChemistryList.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithABool.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4GeometryManager.hh"
#include "G4StateManager.hh"
#include "G4MoleculeFinder.hh"
#include "G4MoleculeTable.hh"

using namespace std;

G4DNAChemistryManager* G4DNAChemistryManager::fgInstance;

//------------------------------------------------------------------------------
/*
 * The chemistry manager is shared between threads
 * It is initialized both on the master thread and on the worker threads
 */
//------------------------------------------------------------------------------
G4DNAChemistryManager::G4DNAChemistryManager()
: G4VStateDependent()
, fVerbose(0)
{
}

//------------------------------------------------------------------------------

G4DNAChemistryManager*
G4DNAChemistryManager::Instance()
{

    if (fgInstance == nullptr)
    {
      fgInstance = new G4DNAChemistryManager();
    }
  return fgInstance;
}

//------------------------------------------------------------------------------

G4DNAChemistryManager*
G4DNAChemistryManager::GetInstanceIfExists()
{
  return fgInstance;
}

//------------------------------------------------------------------------------

G4DNAChemistryManager::~G4DNAChemistryManager()
{
  Clear();
  fgInstance = nullptr;
  /*
   * DEBUG : check that the chemistry manager has well been deregistered
   *  assert(G4StateManager::GetStateManager()->
   *  DeregisterDependent(this) == true);
   */
}

//------------------------------------------------------------------------------

void G4DNAChemistryManager::Clear()
{

}

//------------------------------------------------------------------------------

/*
void G4DNAChemistryManager::DeleteInstance()
{
  if(fgInstance)
  {
    G4DNAChemistryManager* deleteMe = fgInstance;
    fgInstance = 0;
    delete deleteMe;
  }
  else
  {
    G4cerr << "G4DNAChemistryManager already deleted" << G4endl;
  }
}
*/

//------------------------------------------------------------------------------

G4bool G4DNAChemistryManager::Notify(G4ApplicationState requestedState)
{
  if (requestedState == G4State_Quit)
  {
    if(fVerbose)
    {
        G4cout << "G4DNAChemistryManager::Notify ---> received G4State_Quit"
               << G4endl;
    }
    Clear();
  }
  else if(requestedState == G4State_GeomClosed)
  {
    fGeometryClosed = true;
  }
  else if (requestedState == G4State_Idle){
//    InitializeThreadSharedData();
  }

  return true;
}


//------------------------------------------------------------------------------

void G4DNAChemistryManager::Run()
{

//    G4Scheduler::Instance()->Process();
	G4cout<<"Chemistry start"<<G4endl;
}

//------------------------------------------------------------------------------

void G4DNAChemistryManager::Initialize()
{

    return;

}

//------------------------------------------------------------------------------

void
G4DNAChemistryManager::CreateWaterMolecule(ElectronicModification modification,
                                           G4int electronicLevel,
                                           const G4Track* theIncomingTrack)
{
	/*
  if(fpThreadData->fpPhysChemIO)
  {
    G4double energy = -1.;

    switch (modification)
    {
      case eDissociativeAttachment:
        energy = 0;
        break;
      case eExcitedMolecule:
        energy = GetExcitationLevel()->ExcitationEnergy(electronicLevel);
        break;
      case eIonizedMolecule:
        energy = GetIonisationLevel()->IonisationEnergy(electronicLevel);
        break;
    }

    fpThreadData->fpPhysChemIO->CreateWaterMolecule(modification,
                                                    4-electronicLevel,
                                                    energy,
                                                    theIncomingTrack);
  }

  if(fActiveChemistry)
  {
    G4Molecule * H2O = new G4Molecule (G4H2O::Definition());

    switch (modification)
    {
      case eDissociativeAttachment:
      H2O -> AddElectron(5,1);
      break;
      case eExcitedMolecule :
      H2O -> ExciteMolecule(4-electronicLevel);
      break;
      case eIonizedMolecule :
      H2O -> IonizeMolecule(4-electronicLevel);
      break;
    }

    G4Track * H2OTrack = H2O->BuildTrack(1*picosecond,
        theIncomingTrack->GetPosition());

    H2OTrack -> SetParentID(theIncomingTrack->GetTrackID());
    H2OTrack -> SetTrackStatus(fStopButAlive);
    H2OTrack -> SetKineticEnergy(0.);
    G4VITTrackHolder::Instance()->Push(H2OTrack);
  }
  */
}

//------------------------------------------------------------------------------

void
G4DNAChemistryManager::CreateSolvatedElectron(const G4Track* theIncomingTrack,
                                              G4ThreeVector* finalPosition)
// finalPosition is a pointer because this argument is optional
{
	/*
  if(fpThreadData->fpPhysChemIO)
  {
    fpThreadData->fpPhysChemIO->CreateSolvatedElectron(theIncomingTrack,
                                                       finalPosition);
  }

  if(fActiveChemistry)
  {
    G4Molecule* e_aq = new G4Molecule(G4Electron_aq::Definition());
    G4Track * e_aqTrack(0);
    if(finalPosition)
    {
      e_aqTrack = e_aq->BuildTrack(picosecond,*finalPosition);
    }
    else
    {
      e_aqTrack = e_aq->BuildTrack(picosecond,theIncomingTrack->GetPosition());
    }
    e_aqTrack -> SetTrackStatus(fAlive);
    e_aqTrack -> SetParentID(theIncomingTrack->GetTrackID());
    G4VITTrackHolder::Instance()->Push(e_aqTrack);
  }
  */
}

//------------------------------------------------------------------------------

void G4DNAChemistryManager::PushMolecule(G4Molecule*& molecule,
                                         double time,
                                         const G4ThreeVector& position,
                                         int parentID)
{
	/*
  // TODO: PhysChemIO - method unused in the released code
  
  if(fActiveChemistry)
  {
    G4Track* track = molecule->BuildTrack(time,position);
    track -> SetTrackStatus(fAlive);
    track -> SetParentID(parentID);
    G4VITTrackHolder::Instance()->Push(track);
  }
  else
  {
    delete molecule;
    molecule = 0;
  }
  */
}

//------------------------------------------------------------------------------


void G4DNAChemistryManager::
PushMoleculeAtParentTimeAndPlace(G4Molecule*& molecule,
                                 const G4Track* theIncomingTrack)
{
	/*
  // TODO: PhysChemIO - method unused in the released code

  if(fActiveChemistry)
  {
    G4Track* track = molecule->BuildTrack(theIncomingTrack->GetGlobalTime(),
                                          theIncomingTrack->GetPosition());
    track -> SetTrackStatus(fAlive);
    track -> SetParentID(theIncomingTrack->GetTrackID());
    G4VITTrackHolder::Instance()->Push(track);
  }
  else
  {
    delete molecule;
    molecule = 0;
  }
  */
}
