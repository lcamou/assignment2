//Class Parole... Derived from Class Prisoner
//************************************************************************************************************************************

#include "ParoleHeader.h"


Parole::Parole(string id, int sent, int tserv, string name, string last) :
Prisoners(id, sent, tserv, name, last)
{

}

Parole::Parole(Prisoners* p)			//constructor used to create a Parole object using a Prisoners object
{
	setIDNumber(p->getIDNumber());
	setSentence(p->getSentence());
	setTimeServed(p->getTimeServed());
	setName(p->getName());
	setLastName(p->getLastName());
	

}

Parole::~Parole()				//destructor
{

}
float Parole::getFloor()
{
	return Floor;
}