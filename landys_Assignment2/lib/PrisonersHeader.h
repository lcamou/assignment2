/**************************************************************************************************/
//LANDY CAMOU
//CLASS PRISONERS
/**************************************************************************************************/
#ifndef PRIS_H
#define PRIS_H
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
using namespace std;
class Prisoners
{
	
public:
	
	//constructors
	Prisoners();
	//         id  sent  tserv  name   lastname
	Prisoners(string,  int,  int,  string, string);

	Prisoners(Prisoners*);		//copy constructor

	//set functions
	void setName(string);
	void setLastName(string);
	void setIDNumber(string);
	void setSentence(int);
	void setTimeServed(int);
	void setTimeToRelease(int);
	void setTimeToRelease(int, int);
	void Read(ifstream &file);
	void Print();

	//GET FUNCTIONS
	string getIDNumber();
	int getSentence();
	int getTimeServed();
	string getName();
	string getLastName();
	int getTimeToRelease();
	void CreditDebitTime(int);

	void setCredDeb(int, int);
	int getCredDebMonths();


private:
	string ID, Name, LastName;
	int  SentenceMonths, TimeServed, TimeToRelease;
	int C_D_Months = 0;

};
#endif