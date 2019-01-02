

 # Filename: AVLTree.cpp
 #  # Contains: Makefile for lab session about AVL Trees for COMP15
 # Part of: Lab assignment "AVL Trees" for Comp 15 Fall 2018
 #  #
 

CXX      = clang++
CXXFLAGS = -g3 -std=c++11 -Wall -Wextra -O2
LDFLAGS  = -g3


gerp: gerp.o Guttenberg.o HashTable.o Word.o DirNode.o FSTree.o
	${CXX} ${LDFLAGS} -o gerp gerp.o Guttenberg.o HashTable.o Word.o DirNode.o FSTree.o


test-words: test-words.o HashTable.o Word.o
	${CXX} ${LDFLAGS} -o test-words test-words.o HashTable.o Word.o

gerp.o: 		gerp.cpp Guttenberg.h
Guttenberg.o: 	Guttenberg.cpp Guttenberg.h HashTable.h Word.h DirNode.h FSTree.h
HashTable.o: 	HashTable.cpp HashTable.h Word.h
Word.o: 		Word.cpp Word.h 
test-words.o: 	test-words.cpp HashTable.h Word.h


clean:
	rm -rf lab *.o *.dSYM

provide:
	provide comp15 proj2 main.cpp AVLTree.cpp AVLTree.h 
	        pretty_print.cpp README Makefile
