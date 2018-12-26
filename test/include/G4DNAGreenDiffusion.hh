/*
 * G4DNAGreenDiffusion.hh
 *
 *  Created on: Dec 25, 2018
 *      Author: wgshin
 */

#ifndef INCLUDE_G4DNAGREENDIFFUSION_HH_
#define INCLUDE_G4DNAGREENDIFFUSION_HH_

#include "G4VChemDiffusion.hh"

class G4DNAGreenDiffusion: public G4VChemDiffusion {
public:
	G4DNAGreenDiffusion();
	virtual ~G4DNAGreenDiffusion();
};

#endif /* INCLUDE_G4DNAGREENDIFFUSION_HH_ */
