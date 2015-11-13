//************************************************************************************************************************************
//LANDY CAMOU
//Class Jailed... Derived from Class Prisoner
//************************************************************************************************************************************

#include "JailedHeader.h"
//using namespace std;


Jailed::Jailed(string  id, int sent, int tserv,int infrac,  float rate, string name, string last) 
	: Prisoners(id, sent, tserv, name, last) //variables inherited from Prisoners
{
	
	setInfractions(infrac);
	setRate(rate);
}

Jailed::Jailed(Prisoners*  p, int in, float rate) //constructor used to create a Jaled object using a Prisoner object
{
	
	setIDNumber(p->getIDNumber());
	setSentence(p->getSentence());
	setTimeServed(p->getTimeServed());
	setName(p->getName());
	setLastName(p->getLastName());
	setRate(rate);
	setInfractions(in);

}

Jailed::~Jailed()
{
	
		cout << "\n     JAILED PRISONER DESCTRUCTED!!!!!!!" << endl;
}


void Jailed::setInfractions(int inf)
{
	if (inf < 0)
	{
		cout << inf << " is an Invalid Number of Infractions... \n";
		cout << "Number of Infractions  will be set to 0... \n \n";
		Infractions = 0;
	}
	else
		Infractions = inf;

}

void Jailed::setRate(float r)
{
	if (r<0 || r>1)
	{
		cout << r << " is an Invalid Number ... \n";
		cout << "Rate will be set to .1 by default... \n \n";
		Rate = .1;
	}
	else
		Rate = r;
}



 int Jailed::getCreditOrDebitTime()
{
	
	 
	 if (Infractions > 0)
	 {
		 cout << "\n This Prisoner has: " << Infractions << " Infractions... 1 Extra month is added for each Infraction!!!!!" << endl;
		 return Infractions;		//for every infraction the jailed prisoner gets 1 extra month  in jail
	 }
	 else
	 {
		
		 return -Rate*getTimeServed();       //the prisoner gets rate*timetoRelease months less from the starting sentence
	 }
}




int Jailed::getRate()
{
	return Rate;
}

int Jailed::getInfractions()
{
	return Infractions;
}


void Jailed::Print()
{
	Prisoners::Print();
	cout << "Debited or Credited Time: " << getCreditOrDebitTime() << " Months" << endl;

}