//************************************************************************************************************************************
//LANDY CAMOU
//Class Jailed... Derived from Class Prisoner
//************************************************************************************************************************************
#ifndef JAILED_H
#define JAILED_H
#include "PrisonersHeader.h"

//using namespace std;
class Jailed : public Prisoners
{
public:
	
	//constructor
	//     
	Jailed(string , int, int,int, float, string, string);  //two new variables Infractions and Rate
	Jailed( Prisoners*, int,float );

	//destructor
	~Jailed();
	//set functions
	void setRate(float);
	void setInfractions(int);
	void Print();
	
	
	//get functions
	int getRate();
	 int getCreditOrDebitTime();
	int getInfractions();



private:
	int Infractions=0;
	float  Rate=0.1;
	//int credit_debit_months;





};
#endif