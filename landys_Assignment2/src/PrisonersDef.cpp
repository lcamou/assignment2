//*********************************************************************************************************
//LANDY CAMOU
//DEFINITION OF THE CLASS PRISONERS
//**********************************************************************************************************


#include "PrisonersHeader.h"
#include "JailedHeader.h"
#include <sstream>


//using namespace std;


//CONSTRUCTORS

//Default constructor
Prisoners::Prisoners()
{
	Name = "None";
	LastName = "None";
	ID = "0";
	SentenceMonths = 0;
	TimeServed = 0;
	TimeToRelease = 0;
	
}

//constructor with entries

Prisoners::Prisoners(string id, int sent, int tserv, string name, string last)
{
	setName(name);
	setLastName(last);
	setIDNumber(id);
	setSentence(sent);
	setTimeServed(tserv);
	
}

Prisoners::Prisoners(Prisoners *p)		//copy constructor used to copy Prisoners class objects into the heap
{
	ID = p->getIDNumber();
	Name = p->getName();
	LastName = p->getLastName();
	SentenceMonths = p->getSentence();
	TimeServed = p->getTimeServed();
	TimeToRelease = p->getTimeToRelease();
	C_D_Months = p->getCredDebMonths();
	
}

//FUNCTIONS DEFINITION
void Prisoners::setName(string N)
{
	Name = N;
}

void Prisoners::setLastName(string LN)
{
	LastName = LN;
}

void Prisoners::setIDNumber(string id)
{
	ID = id;
}

void Prisoners::setSentence(int m)
{
	if (m <= 0 )   //checking if sentence is an invalid number
	{
		cout << "\nThis is an Invalid Sentence... \n";
		cout << "Sentence will be set to 0... \n\n";
		SentenceMonths = 0;
		
	}else
	SentenceMonths = m;
	
}

void Prisoners::setTimeServed(int t)
{
	if (t <  0 || t > SentenceMonths)   //checking if time served is less than zero or greater than sentence
	{
		cout << t <<" Months is an Invalid Time Served... \n";
		cout << "Time Served will be set to 0... \n \n";
		TimeServed = 0;
	}
	else
	{
		TimeServed = t;
	}

	setTimeToRelease(SentenceMonths, TimeServed);
}

void Prisoners::setTimeToRelease(int t)
{
	TimeToRelease = t;
}

void Prisoners::setTimeToRelease(int s, int t)
{
	TimeToRelease = s - t;      //calculating time to release
}



void Prisoners::CreditDebitTime(int d)
{
	C_D_Months = d;
	TimeToRelease = TimeToRelease + d ;
}
//get functions definition

int Prisoners::getSentence()
{
	return SentenceMonths;
}

int Prisoners::getTimeServed()
{
	return TimeServed;
}

string  Prisoners::getIDNumber()
{
	return ID;
}
int  Prisoners::  getTimeToRelease()
{
	return TimeToRelease;
}

int Prisoners::getCredDebMonths()
{
	return C_D_Months;
}
string Prisoners::getName()
{
	return Name;
}

string Prisoners::getLastName()
{
	return LastName;
}


void Prisoners::Read(ifstream &file)			//functio used to read the file and set data into the object
{
	string line;
	getline(file, line);
	stringstream split(line);					//variable that holds the hole line but separated
	
	string word,array[5];						//array to hold each word of the line
	int i=0,value;
	while (getline(split, word, ',')){			//inserting each word into the array
		array[i] = word;
		i++;
	}
												//taking each word to initialize object's variables
	ID = array[0];
	setSentence( stoi(array[1]));
	setTimeServed( stoi(array[2]));
	Name = array[3];
	LastName = array[4];
	
	//used to read a file .txt
	/*
	file >> ID;
	file >> value;
	setSentence(value);
	file >> value;
	setTimeServed(value);
	file >> Name;
	file >> LastName;
	*/
}


//print function definition
void Prisoners::Print()
{ 
	cout <<"\nPrisoner ID:  "<< ID <<"\nSentence:  " << SentenceMonths << " Months  \n" <<  "Time Served:  " << TimeServed << " Months \n" << "Time To Release:  ";
	cout << TimeToRelease << " Months \n" << "Name: " << Name << "\nLast Name: " << LastName<<"\nCredited / Debited Months: "<<C_D_Months<< " Months"<< endl;
	

}


