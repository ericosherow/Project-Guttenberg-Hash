#include <iostream>
#include <functional>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cctype>
#include <vector> 
#include <fstream>
#include <sstream>
#include "HashTable.h"
#include "Word.h"
#include "FSTree.h"
#include "DirNode.h"
#include "Guttenberg.h"

using namespace std; 



Guttenberg::Guttenberg()
{
	index = 0; //gloabl index for hashyboi.filedirectory// insures modulatrity 
}

Guttenberg::~Guttenberg()
{

}


// Function: run 
// Input:  filename 
// Returns: 
// Does: runs Guttenber, creates hash program 
void Guttenberg::run(string filename)
{

	//cerr << "Guttenberg::RUN" << endl; 	
		FSTree *tree = new FSTree(filename);
		bool completedtree;
		completedtree = traversal(tree->getRoot(), tree->getRoot()->getName()); 
 	//int num = hashyboi.get_num_insertions(); 
	//int unique = hashyboi.get_unique_insertions();	
	 
 		 		
	while (true)	{ 		 
		string query1 = " ";
		string query2 = " ";
		cout << "Query?" << endl; 
		cin >> query1;
		//cerr << "Query1" << query1 << endl; 
		
		if (query1 == "@q" || query1 == "@quits")
		{
			cerr << "Quits" << endl; 
			return; 
		}

		if(query1 == "@i" || query1 == "@insensitive"){ // fix @insense 
			cin >> query2;
			if (query1 == "@insensitive")
				query1 = "@i"; 

			query1 += query2;
		}

		hashyboi.runQuery(query1);
	}

	delete tree; 
}

// Function: word file insertion 
// Input: string file name 
// Returns: 
// Does: opens file stream and inserts words to hashtable 
void Guttenberg::word_file_insertion(string filename)
{
	ifstream infile; 
	infile.open(filename);

	if (!infile.is_open()) {
	    cerr << "Could not open " << " for reading\n";
	    exit(1); 
	}
	string word = " "; 
	string wholeLine = " "; 
	string cur_data = filename; 

	hashyboi.constructDirectory(cur_data); //insert file name to direcrory; 

    while (!infile.eof()) 
    {

    	getline(infile, wholeLine); 

    	istringstream ss(wholeLine);

    	while (ss >> word)
    	{
    		Word(word, index); //INDEX = cur_data(file path) in directory
    		hashyboi.insertWord(word, index);//inserts into hashyboi (make global private in .h)
    											//inserts word (string ) &
    		amountWords++;														//cur_data = filename +line
    	} amountLines++;
    } 
    index++; 
}

// Function: traversal 
// Input: dirnode pointer, string of current filename 
// Returns: true if done 
// Does:  traverses dir tre 
//file tree traversal 
bool Guttenberg::traversal(DirNode *root, string cur_data) //root has been set
{

	if (root->hasSubDir()) {
		for (int i = 0; i < root->numSubDirs(); i++){
			string directory =  cur_data + "/" + root->getSubDir(i)->getName();  
			traversal(root->getSubDir(i), directory);
		}
	}
 
	if (root->hasFiles()) {
		for (int j = 0; j < root->numFiles(); j++) {
			string file = cur_data + "/" + root->getFile(j); 
			//cout << file << endl; //prints text files 
			string temp; 
			for (int i = file.length()-1; i > 0; i--) {
				temp += file[i];
				if (temp == "txt.") {
					j++;
					word_file_insertion(file);
				}
			}
		}
	}
	return true;  
}

