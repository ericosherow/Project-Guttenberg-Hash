#include <iostream>
#include <vector> 
#include "Word.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

using namespace std; 

class HashTable{

public : 

	HashTable(); 

	~HashTable(); 

	void insertWord(string &inWord, int &filepos);

	unsigned long calcHash(string &key); 

	int get_num_insertions(); 

	int get_unique_insertions();

	int get_table_size();

	int find_chain_elem(string &inWord, unsigned long &index, char sensitivity);

	void caseSensitive(string &query, int &index, int &vectorPos);

	string makeInsensitive(string &inWord); 

	char parseSensitivity(string &sensitivity);

	string query(string &query);

	string StringProcessing(string &query); 

	string parseWord(string &inQuery); 

	void runQuery(string &query);

	void constructDirectory(string &file);

	void printFileLine(string query, string &file);

	int longestvector(); 

	void vectorsort(); 

	int vectorFind(string hashWord, unsigned long index); 

	//int HighestAVGvector(); 

	void printVector();

	void print(); 

private : 

	vector<Word> *Table; // array that holds chains and words 

	vector<string> directory; // array that holds directory of files 

	unordered_set<string> setty;

	int amountInsertions; //total insert 

	int uniqueInsertions; //unique words inserted 

	int table_size; 
};
#endif 