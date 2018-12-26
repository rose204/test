/*
 * G4VChemReaction.hh
 *
 *  Created on: Dec 24, 2018
 *      Author: wgshin
 */

#ifndef INCLUDE_G4VCHEMREACTION_HH_
#define INCLUDE_G4VCHEMREACTION_HH_

#include "G4VChemProcess.hh"

class G4VChemReaction: public G4VChemProcess {
public:
	G4VChemReaction();
	virtual ~G4VChemReaction();
};

#endif /* INCLUDE_G4VCHEMREACTION_HH_ */
