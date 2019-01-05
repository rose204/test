/*
 * G4VChemDiffusion.hh
 *
 *  Created on: Dec 27, 2018
 *      Author: wgshin
 */

#ifndef INCLUDE_G4VCHEMDIFFUSION_HH_
#define INCLUDE_G4VCHEMDIFFUSION_HH_

#include "G4VChemProcess.hh"

class G4VChemDiffusion: public G4VChemProcess {
public:
	G4VChemDiffusion();
	virtual ~G4VChemDiffusion();
};

#endif /* INCLUDE_G4VCHEMDIFFUSION_HH_ */
