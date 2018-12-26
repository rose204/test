/*
 * G4DNABrownianDiffusion.hh
 *
 *  Created on: Dec 25, 2018
 *      Author: wgshin
 */

#ifndef INCLUDE_G4DNABROWNIANDIFFUSION_HH_
#define INCLUDE_G4DNABROWNIANDIFFUSION_HH_

#include "G4VChemDiffusion.hh"

class G4DNABrownianDiffusion: public G4VChemDiffusion {
public:
	G4DNABrownianDiffusion();
	virtual ~G4DNABrownianDiffusion();
};

#endif /* INCLUDE_G4DNABROWNIANDIFFUSION_HH_ */
