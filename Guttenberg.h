#include <iostream>
#include <vector> 
#include "HashTable.h"
#include "Word.h"
#include "FSTree.h"
#include "DirNode.h"


#ifndef GUTTENBERG_H
#define GUTTENBERG_H

using namespace std; 

class Guttenberg {

public : 

	Guttenberg(); 

	~Guttenberg(); 

	void run(string filename); 

	bool traversal(DirNode *root, string cur_data);

	void word_file_insertion(string filename); //runs filenameile i/o
	
private : 
	
	HashTable hashyboi; 

	int index; 

	// MOVED TO HASHTABLE vector<string> directory; // vector that holds direcrory of lines 

	int amountLines; 

	int amountWords; 

};
#endif 