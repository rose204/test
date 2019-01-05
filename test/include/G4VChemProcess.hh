/*
 * G4VChemProcess.hh
 *
 *  Created on: Dec 24, 2018
 *      Author: wgshin
 */

#ifndef INCLUDE_G4VCHEMPROCESS_HH_
#define INCLUDE_G4VCHEMPROCESS_HH_

#include "G4VProcess.hh"

class G4VChemProcess : public G4VProcess{
public:

	  G4VChemProcess();
	  virtual ~G4VChemProcess();


	  virtual void StartTracking(G4Track*);


};

#endif /* INCLUDE_G4VCHEMPROCESS_HH_ */
