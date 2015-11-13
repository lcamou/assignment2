//*************************************************************************************************************
//LANDY CAMOU
//Heap Functions
//*************************************************************************************************************

#include "PrisonersHeader.h"



//function to reheap
void organize_Heap(Prisoners heap[], int current)
{

	int root = 0, parent;
	if (current > root)					//if current position is greater than root... if we have just one element current=0 and root=0 son we don't need to reheap
	{
		parent = (current - 1) / 2;		//getting parent index
		if (heap[parent].getTimeToRelease() > heap[current].getTimeToRelease())			//checking if parent is gretaer than our current index value
		{

			Prisoners temp1(heap[current]);				//create a temporal object of class Prisoners to hold the value of current index
			heap[current] = heap[parent];				//we swap in order to get the smallest value into parent
			heap[parent] = temp1;

			organize_Heap(heap, parent);		//using recursion to reheap until completed
		}										//recursion is finished when parent becomes zero, this means we are in the root
	}
}

//function to insert objects into the heap
void insertPrisoner_Heap(Prisoners heap[], Prisoners p, int current, int size)
{
	if (current < size)
	{
		heap[current] = p;		//inserting Prisoner object into the heap using current position
	}
}

//function to count number of prisoners
int getNumberOfPrisoners(){
	string line;
	ifstream file;
	int prisCount = 0;
	file.open("C:/Users/Kmuk/Documents/assignment2/prisoner_data.csv");
	while (!file.eof()){
		getline(file, line); //counting how many lines in the file, so we get how many prisoners are 
		prisCount++;
	}

	file.close();
	return prisCount -2;		//returning number of prisoners minus 1 dummy line at the beginning and 1 dummy line at the end
}

//function to reheap after an element is out
void outFromHeap(Prisoners heap[], int root, int lastElement){

	int leftChild, rightChild, smallest;
	leftChild = root * 2 + 1;				//setting leftChild index
	rightChild = root * 2 + 2;				//setting rightChild index

	if (leftChild <= lastElement){			//checking if we have more than 2 elements after leftChild

		if (leftChild == lastElement){		//if leftChild is equal to last element it means we dont have rightChild
			smallest = leftChild;			//leftChild must have the smallest value
		}
		else{
			if (heap[leftChild].getTimeToRelease() <= heap[rightChild].getTimeToRelease())  //if not we comapare both children to get the smalles
			{
				smallest = leftChild;
			}
			else
				smallest = rightChild;
		}

		if (heap[smallest].getTimeToRelease() <= heap[root].getTimeToRelease()){	//once we get the smallest child we comapare it to the root

			Prisoners temp = heap[root];						//we swap if smallest child is less than root
			heap[root] = heap[smallest];
			heap[smallest] = temp;
			outFromHeap(heap, smallest, lastElement);			//reheap until completed
		}
	}
}
