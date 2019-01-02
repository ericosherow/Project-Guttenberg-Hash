#include <iostream>
#include <string>
#include "FSTree.h"
#include "DirNode.h"

using namespace std; 

void traversal(DirNode *root, string cur_data);

int main (int argc, char *argv[])
{
	FSTree *tree = new FSTree(argv[1]);

	cout << argv[1] << endl; 

	traversal(tree->getRoot(), tree->getRoot()->getName()); 

	return 0; 
}


void traversal(DirNode *root, string cur_data) //root has been set
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
			cout << file << endl; 
		}
	}
	cout << cur_data << endl; 
}

