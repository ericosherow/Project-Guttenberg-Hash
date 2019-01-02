#include <iostream>
#include <vector>
#include "Word.h"

using namespace std; 

//constructor 
Word::Word()
{
	wordName = " "; 
	amount = 0; 
	locFiles.resize(0);
}

// Function: Paramterized Constructor 
// Input: 
// Returns: 
// Does: sets word to intial vals 
Word::Word(string name, int inFile_pos) //the hash has empty pos 
{
	wordName = name; 		//works 
	amount = 1; 			// works 
	locFiles.reserve(1);	//?
	insertFilePos(inFile_pos);	//?
}

//destructor 
Word::~Word()
{
	locFiles.clear(); 
	//delete locFiles; 
}

// Function:
// Input: 
// Returns: 
// Does: 
void Word::insertFilePos(int inFile_pos)
{
	//cerr << "Vector capacity = " << locFiles.capacity() << endl; 
	locFiles.push_back(inFile_pos); 
}

// Function: getName 
// Input: //
// Returns: string name 
// Does: returns private name 
string Word::getName()
{
	return wordName; 
}

// Function: getAmount 
// Input:
// Returns: int amount 
// Does: returns amount 
int Word::getAmount()
{
	return amount; 
}

// Function:
// Input: 
// Returns: 
// Does: 
string Word::searchFiles()
{
	return " "; 
}

// Function: VectorSize
// Input: 
// Returns: size of locFiles<int> directory 
// Does: returns locFiles.size()
int Word::VectorSize() //returns num elements 
{
	return locFiles.size(); 
}

// Function:
// Input: 
// Returns: 
// Does: 
bool Word::find_vector_elem(string inWord)
{


}

// Function: GetVectorFiles 
// Input: 
// Returns: loc Files vector 
// Does: returns vector<int> loc files 
vector<int>& Word::getVectorFiles()
{	
	return locFiles; 
}


// Function: print vector 
// Input: 
// Returns: 
// Does: printVector locfiles 
void Word::printVector()
{
	int size = locFiles.size();
	cout << "vector elements:: " << endl; 
    for (int i = 0; i < size; i++) 
        cout << i << "::" << locFiles[i] << " " << endl; 
}



