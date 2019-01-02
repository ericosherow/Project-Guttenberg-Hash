#include <iostream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <cassert>
#include <string>
#include <stdio.h>
#include <cctype>
#include <vector> 
#include <fstream>
#include <sstream>
#include "HashTable.h"
#include "Word.h"

using namespace std; 

const int RelativeMax = 500000; 

static const int prime = 16908799;

HashTable::HashTable() //constructor 
{
	Table = new vector<Word>[RelativeMax]; //set size 
	table_size = RelativeMax; 
	amountInsertions = 0; 
}

HashTable::~HashTable()
{
	//shrink vector? 
	for (int i = 0; i < table_size; i++)
		Table[i].clear();
	delete [] Table;
}

string HashTable::makeInsensitive(string &inWord)
{
  	string hashWord = inWord; 

  	for (size_t i = 0; i < hashWord.length(); ++i)
    	hashWord[i] = tolower(hashWord[i]);
	
	return hashWord;
}


// Function:find chain elem 
// Input: word to find, index to look at, dummuy sensity 
// Returns: index of word if present in chain 
// Does: returns index 
int HashTable::find_chain_elem(string &inWord, unsigned long  &index, char sensitivity)
{

	for (size_t i = 0; i < Table[index].size(); i++) {
		string name = Table[index][i].getName();

		if (sensitivity == 'i'){
			string inQuery = makeInsensitive(inWord);
			name = makeInsensitive(name); // return string to hash value 
			if (name == inQuery)
				return i; 
		}
		else if (name == inWord){ //if word exists in vector 
			return i; 
		}
	}



	return -1; 
}

int HashTable::vectorFind(string hashWord, unsigned long index)
{
	for (size_t i = 0; i < Table[index].size(); i++) {
		string name = Table[index][i].getName();
		name = makeInsensitive(name); 
		if (name == hashWord)
			return i; 
	}
	return -1; 
}


// Function: insert word 
// Input: name 
// Returns: 
// Does: inserts words into hashtable 
// the code priotizes o1 insertions. Table[index] == empty //hence redudant code 
void HashTable::insertWord(string &inWord, int &filepos)
{
	amountInsertions++; //up here aor initial hash 
	string parsedWord = StringProcessing(inWord); // update word have no periods 
	string hashWord = makeInsensitive(parsedWord);
	long unsigned index = calcHash(hashWord);


	if (Table[index].empty() == true) // empty insetion o(1)
	{
		// if (hashWord == "the" )
		// 	cerr << "FUCK" << endl;

		//assert(setty.find(hashWord) == setty.end()); 
		uniqueInsertions++;
		setty.insert(hashWord); 
		  
		Word newWord(parsedWord, filepos); //construct new word
		Table[index].push_back(newWord); //push word to back //works regardless of if vector is empty or has word inside
		//Table[index][0].insertFilePos(filepos);
	} 
	else {

		int chainindex = vectorFind( hashWord, index); 

		if (chainindex != -1) { //if word exists in vector 
		
			// if (hashWord == "the" )
			// 	cerr << "FUCK";

			//assert(setty.find(hashWord) != setty.end()); 

			Table[index][chainindex].insertFilePos(filepos);  
		}
		else {
			// if (hashWord == "the" )
			// 	cerr << "Swaggggg";
			assert(setty.find(hashWord) == setty.end()); 
			setty.insert(hashWord); 
			Word newWord(parsedWord, filepos);
			//cerr << "parsedWord" << parsedWord << endl; 
			Table[index].push_back(newWord);
			//cerr << Table[index].size() << "VECTORSIZE" << endl; 
			uniqueInsertions++; 
		}
	}

}

// Function:
// Input: 
// Returns: 
// Does: 
int HashTable::longestvector()
{
	// int max = 0; 

	// for (int i = 0; i < table_size; i++)
	// {
	// 	if (Table[i].size() > max)
	// 		max = Table[i].size(); 
	// }
	return 0; 
}

// Function:
// Input: 
// Returns: 
// Does: 
void HashTable::vectorsort()
{
	vector<unsigned> v; 
	for (int i = 0; i < table_size; i++)
		v.push_back(Table[i].size());

	sort(v.begin(), v.end());

	for (int j = 0; j < table_size; j++)
		cerr << " " << v[j] << " " << endl; 
}

// Function: calcHash 
// Input: key 
// Returns: int hash val 
// Does: calcs hash number 
unsigned long HashTable::calcHash(string &key)
{	
	//return std::hash<string>{}(key);
     int hashVal = 0;

     for (size_t i = 0; i < key.length(); i++) {
        hashVal = ((127 * hashVal + key[i]) % prime);
     }
    // cerr << "HAShval=" <<hashVal << endl; 

     return (hashVal % table_size);

	// hash<string> str_hash;

 //    return str_hash(key) % table_size;
}

// Function:
// Input: 
// Returns: 
// Does: 
int HashTable::get_table_size() 
{
	return table_size; 
}

// Function:
// Input: 
// Returns: 
// Does: 
int HashTable::get_num_insertions()
{
	return amountInsertions; 
}

// Function:
// Input: 
// Returns: 
// Does: 
int HashTable::get_unique_insertions()
{
	return uniqueInsertions; 
}

// Function: print 
// Input: 
// Returns: 
// Does: prints table 
void HashTable::print()
{
	//cerr << "within print" << "amountInsert=" << amountInsertions << endl; 
	cerr << "--------------" << endl;  
	for (int i = 0; i < table_size; i++) {//vector
	cerr << i << endl;  
	cerr << "vector size" << Table[i].size() << endl; 
		for (size_t j = 0; j < Table[i].size(); j++) { //word 
			cerr << "I=" << i << endl; 
			cerr << "J=" << j << endl; 
			cout << Table[i][j].getName() << endl; 
			Table[i][j].printVector();
		}
		cerr << "--------------" << endl;  
	}
}

// Function:
// Input: 
// Returns: 
// Does: 
//case sensitive check
void HashTable::caseSensitive(string &query, int &index, int &vectorPos)
{ 
	string name = Table[index][vectorPos].getName();

	for (size_t i = 0; i < query.length(); i++) {
		if (query[i] != name[i])
			cerr << "sensitivity == false"; 
		else {
			cerr << "S::Query Found" << " " << query << endl; 
			break; 
		}
	}

}

// Function: parse sensensitivty 
// Input: 
// Returns: 
// Does: returns sensit8ivity char 
char HashTable::parseSensitivity(string &sensitivity)
{
		if (sensitivity[0] == 64 && sensitivity[1] == 113)
			return 'q'; 
		else if (sensitivity[0] == 64 && sensitivity[1] == 105) //ascii of space  
			return 'i'; 
		//not found 
	return 'x';
}

// Function: parseWord 
// Input: string 
// Returns: string word 
// Does: removes spaces 
string HashTable::parseWord(string &inQuery)
{
	for (size_t i = 0; i < inQuery.length()-1; i++) 
		if (inQuery[i] == 32) 
			return inQuery.substr(i+1, inQuery.length()-1);

	return inQuery; 

}

// Function:
// Input: file to insert/ query 
// Returns: string word 
// Does: Makes file strings acceptable for insertion/query 
string HashTable::StringProcessing(string &inQuery)
{
	while (true)
		{
			string query = inQuery; 

			for (size_t i = 0; i < query.length()-1; i++) {
				if (isalnum(query[i])) 
					break; 
				else {
					query.erase(i,i+1);	
					i--; 
				}
			}
			for (size_t j = query.length()-1; j > 0; j--) { 
				if (isalnum(query[j]))
					break; 
				else {
					query.erase(j,j-1);
				}
			}
			return query;
			//cout << " this is new string size" << " " << query.length() << endl; 
		}
	return "Empty string"; 
}

// Function:construct directory 
// Input: string file to insert 
// Returns: 
// Does: constructs directory of words 
void HashTable::constructDirectory(string &file)
{
	directory.push_back(file); 
}

// Function:print vector 
// Input: 
// Returns: 
// Does: prints directory 
void HashTable::printVector()
{
	int size = directory.size();
	cout << "*Directory*vector elements:: " << endl; 
    for (int i = 0; i < size; i++) 
        cout << i << "::" << directory[i] << " " << endl; 
}

// Function: prints file lines 
// Input:  query, file 
// Returns: 
// Does: prints files 
void HashTable::printFileLine(string query, string &file)
{
	ifstream infile; 
	infile.open(file);

	if (!infile.is_open()) {
	    cerr << "Could not open " << " for reading\n";
	    exit(1); 
	}

	string fileword = " "; 
	string wholeLine = " "; 
	int lines_num = 0; 

    while (!infile.eof()) 
    {
    	getline(infile, wholeLine); 

    	istringstream ss(wholeLine);
    	while (ss >> fileword) {
    		if (fileword == query)
    			cout << "/" << file << ":" << lines_num << ":" << wholeLine << " " << endl;
    
    	} lines_num++;
    } 
}



// Function: run query 
// Input: word to query 
// Returns: 
// Does: querys words 
//insert case insenstive 

void HashTable::runQuery(string &inQuery)
{ 

	char sensitivity = parseSensitivity(inQuery); //case //pass into chain 
	string parsedWord = parseWord(inQuery); //removes space
	parsedWord = StringProcessing(parsedWord); // update word to final acceptable format
	string hashWord = makeInsensitive(parsedWord); //make insense for search 

	//cerr << "inQuery" << hashWord << endl; 

	if (sensitivity == 'i') {
		hashWord.erase(0,1);
		parsedWord.erase(0,1);
	}

	unsigned long index = calcHash(hashWord); //find hash 
	int vectorPos = find_chain_elem(parsedWord, index, sensitivity); //find chain 	

	if (vectorPos == -1 && sensitivity == 113) { // quits 
		cerr << "Quits" << endl; 
		return;
	}
	else if (vectorPos != -1 && sensitivity == 105) {//insensitive // not working**********
		vector<int> temp = Table[index][vectorPos].getVectorFiles();
		vectorPos = find_chain_elem(hashWord, index, sensitivity);
		//cout << "inQuery Found" << " " << Table[index][vectorPos].getName() << endl;  
		for (size_t i = 0; i < temp.size(); i++)
				printFileLine(Table[index][vectorPos].getName(), directory[temp[i]]); 	
	}	
	else if (vectorPos != -1)
	{
		vector<int> temp = Table[index][vectorPos].getVectorFiles();

		//cout << "S:Word found" << " " << Table[index][vectorPos].getName() << endl; 

		for (size_t i = 0; i < temp.size(); i++)
			printFileLine(Table[index][vectorPos].getName(), directory[temp[i]]); 	
	}
	else /*(vectorPos == -1 && sensitivity == 'x')*/ { // this is not right conditions 
		cerr << "word not found" << endl; 
		return;
	} 		
} 


