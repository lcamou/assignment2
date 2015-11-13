//************************************************************************************************************************************
//LANDY CAMOU
//Class Parole... Derived from Class Prisoner
//************************************************************************************************************************************
#ifndef PAROLE_H
#define PAROLE_H

#include "PrisonersHeader.h"

class Parole : public Prisoners
{
public:

	//constructor
	Parole(string, int, int, string, string);  //new variable float Floor
	Parole(Prisoners*);
	//destructor
	~Parole();

	void setFloor(float);
	float getFloor();

private:
	float const Floor = .33;


};
#endif