#include <iostream>
#include "Guttenberg.h"

using namespace std; 

int main (int argc, char *argv[])
{
	Guttenberg HashTable; 

	string filename = argv[1];

	//cerr << "gutt" << endl; 
	
	HashTable.run(filename); 

	//cerr << "\n***Grep complete*****\n"; 

	return 0; 
}
