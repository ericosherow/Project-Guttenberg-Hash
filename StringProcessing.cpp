#include <iostream>
#include <stdio.h>
#include <ctype.h>

//#include "FSTree.h"
//#include "Dirnode.h"

using namespace std; 

int main ()
{
	while (true)
	{
		string query; 

		cout << endl; 
		cin >> query; 

		for (int i = 0; i < query.length()-1; i++) {
			if (isalnum(query[i])) 
				break; 
			else {
				query.erase(i,i+1);	
				i--; 
			}
		}
		for (int j = query.length()-1; j > 0; j--) { 
			if (isalnum(query[j]))
				break; 
			else {
				query.erase(j,j-1);
			}
		}
		cout << query  << endl;  
		//cout << " this is new string size" << " " << query.length() << endl; 

	}

	return 0; 
}