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
// $Id: G4HepRepViewer.hh,v 1.17 2004/05/27 05:55:20 duns Exp $
// GEANT4 tag $Name: geant4-07-01 $
//

/**
 * @author Mark Donszelmann
 */

#ifndef G4HEPREPVIEWER_HH
#define G4HEPREPVIEWER_HH 1

// HepRep
#include "HEPREP/HepRep.h"

// Geant4
#include "G4VViewer.hh"

#include "G4HepRepMessenger.hh"

class G4HepRepViewer: public G4VViewer {
    public:
        G4HepRepViewer (G4VSceneHandler& scene, G4HepRepMessenger& messenger, const G4String& name = "");
        virtual ~G4HepRepViewer ();
        void SetView ();
        void ClearView ();
        void DrawView ();
        void ShowView ();
        void FinishView ();

        void reset();
        
    private:
        bool geometryIncluded;
        G4HepRepMessenger& messenger;
};

#endif