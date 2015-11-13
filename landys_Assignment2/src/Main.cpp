//LANDY CAMOU
//MAIN

//This program takes data from a file. This file contains the ID, name, last name, sentence, and time served of some prisoners.
//Once read a single prisoner an object of class Prisoner is created.
//Then an object of class Jailed is created using the same data of the object Prisoner
//After that the peogram compute the good time for that Jailed prisoner and defines if the object of class Jailed is destructed and a Parole object is created
//The program applies changes to TimeToRelease of  the original class Prisoner object
//The program applies changes to TimeToRelease of the new Jailed or Parole object (whatever is the case)
//By now we will have 2 objects for each Prisoner----- Prisoners class object and Jailed or Parole object
//At the end we will have all prisoners converted into Prisoners class objects, and we will have a certain number of Jailed prisoners and a certain number
//of Parole prisoners
//The program creates a heap of Prisoners class objects (since we dont create a heap for Jailed and another heap for Parole) we put all prisoners together
//but by now we already know who is Jailed and who is Parole
//At the end we take out the first 6 prisoners who are going to be free from the heap
/*************************************************************************************************************************************************/



#include <istream>
#include "Heap_Funct.h"
#include "JailedHeader.h"
#include "ParoleHeader.h"

using namespace std;



int main()
{

	
	int current = 0, credit_debit_months;			//declaring variable current to count how many objects have been sent to the Heap
	int prisCount = getNumberOfPrisoners();			//calling function that counts the number of prisoners in the file prisoners_data

	cout << " \n \n -------- Number of prisoners on file: " << prisCount << endl;	//printing the number of prisoners in the file
	ifstream file;
	Prisoners* PrisonersHeap = new Prisoners[prisCount];		//creating an array called prisonersheap using the number of prisoners
	string dummy;
	 file.open("C:/Users/Kmuk/Documents/assignment2/prisoner_data.csv");			//opening the file
	getline(file, dummy);
	while (!file.eof() && current<50){							

		Prisoners * Prisoner = new Prisoners;					//creating an object of class Prisoners
		Prisoner->Read(file);									//getting data form file and inserting data into the object Prisoner


		Jailed*  jailPris1 = new Jailed(Prisoner, 0, 0.1);		//creating an object of class Jailed, using the object Prisoner
																//this constructor takes the object and takes number of infractions and the good time rate
																//we can type  infractions or we can customize good time rate
																//if infractions and rate are set to zero the the JailedPris and Prisoner will be the same
																//using this constructor we can change the data from jailPris1 without changing the object Prisoner

		
		credit_debit_months = jailPris1->getCreditOrDebitTime();		//getting how many months will be debited or credited
		
		cout << "\n\n Prisoner time to release before: " << Prisoner->getTimeToRelease();

		Prisoner->CreditDebitTime(credit_debit_months);					//changing Time To Release from the object Prisoner 
		cout << "\nPrisoner time to release after: " << Prisoner->getTimeToRelease() << endl;

		if (jailPris1->getTimeToRelease() + jailPris1->getCreditOrDebitTime() < .33* jailPris1->getSentence())	//checking if time to release is less than 1/3 sentence
		{
			delete jailPris1;				//if YES, jailPris1 is deleted

			Parole* ParolePris1 = new Parole(Prisoner);						//and a PArole object is created using the same object Prisoner
			ParolePris1->setTimeToRelease(Prisoner->getTimeToRelease());	//changing time to release of Parole object so it will be the same than PRisoner
			cout << "*****NOW THIS IS A PAROLE PRISONER: " <<endl;
			ParolePris1->Print();
		}
		else{

			cout << "\n *****JAILED PRISONER!!!!!" << endl;		//if time to release is MORE than 1/3 sentence then Prisoner stay being Jailed
			jailPris1->CreditDebitTime(credit_debit_months);	//changing time to release for jailPris1 so it will be the same than Prisoner
			jailPris1->Print();
		}														//by now we have the object Prisoner after debited or credited good time and we have 
																//another object of the class Jailed or class Parole with the same data as Prisoner


		insertPrisoner_Heap(PrisonersHeap, Prisoner, current, prisCount);	//inserting Prisoner object into heap
																			//since we don't create different heaps for Jailed and Parole we use the base class 
																			//the heap will be of class Prisoners so we can insert all objects without care of class
		organize_Heap(PrisonersHeap, current);								//reheap 
		current++;															//incrementing the number of objects alredy inserted

		system("pause");
	}
	file.close();

	

	//once finished creating Jailed and Parole objects and finished inserting Prisoner objects into the heap we print the heap
	cout << "\n\n\n\n*************HEAP*************" << endl;
	cout << "\n************************************" << endl;
	for (int i = 0; i < prisCount; i++){
		cout << "\n\n";
		PrisonersHeap[i].Print(); 
		system("pause");
		}

	//printing the first 6 prisoners ( shortest time to release)
	cout << "\n\n*******************************************"<<endl;
	cout << "********** FIRST 6 PRISONERS***************" << endl;

	int first_to_be_free = 6;			//variable holding the number of prisoners that will be set free soon

	for (int i = 0; i < first_to_be_free; i++){
		PrisonersHeap[0].Print();						//printing the root of the heap(shortest time to release)
		prisCount--;									//since we got 1 out, we decrement the number of prisoners in the heap
		PrisonersHeap[0] = PrisonersHeap[prisCount];	//inserting the last element in the heap into root
		outFromHeap(PrisonersHeap,0, prisCount-1);		//reheap after we got 1 out
		system("pause");
		}



	system("pause");
}