#include <iostream>
#include <vector> 
#include <unordered_set>

#ifndef WORD_H
#define WORD_H

using namespace std; 

class Word{

public : 
	//default Constructor 
	Word();
	//Paramiterized Constructor 
	Word(string name, int path);
	
	//Destructor 
	~Word();

	

	//core functions 
	void insertFilePos(int inFile_pos); //inserts file position (if search found) 
										//RETURNS amount of appearences 

	//geters/setters 
	string getName(); 

	vector<int>& getVectorFiles(); //returns int ( index) to file positions in Guttenberg.directory

	int getAmount();

	string searchFiles();

	//int get_path_size();

	int VectorSize(); 

	bool find_vector_elem(string inWord);

	void printVector();

	void printWhole(ostream &out);






	//friend ostream & operator << (ostream &outfile, const word &a); 

	//friend bool operator != (const word &a1, const word &a2);

	//friend bool operator == (const word &a1, const word &a2);


private : 

	string wordName; //term 

	int amount;  //amount of appearences 


	//int linenum;

	vector<int> locFiles; // index location of all appearences in gerp file direcrory 

	//void ordered_copy(const Actor &a);

	//void ordered_delete();

}; 
#endif 