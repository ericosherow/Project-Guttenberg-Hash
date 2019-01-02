/*
 * Filename: main.cpp
 * Contains: Driver for gerp 
 * 
 */

#include <iostream>
#include <vector>
#include "HashTable.h"
#include "Word.h"

using namespace std;

void testWords();

void testHash(); 

int main() 
{
    //testWords(); 

    testHash(); 

    return 0;
}

void testHash()
{
    HashTable hashyboi; 

    hashyboi.insertWord("SWAG", "/we/in/this/gang/g");

    hashyboi.insertWord("SWAG", "/fuck/the/system/");

    hashyboi.insertWord("SWAG", "/fuck/the/system/");

    hashyboi.insertWord("STUFF", "/AKKSDJ;KFJ/"); // chained to swag
                                                //*****fix double inserts whole line into vector

    //hashyboi.insertWord("STUFF", "/ZZZZZZZZKFJ/");

    hashyboi.insertWord("JOHN", "/stuff/"); 

    hashyboi.insertWord("AARON", "/XXXXXX/"); 

    hashyboi.insertWord("PETE", "/PPPPPPP/"); 

    hashyboi.insertWord("ANDERSON", "/KKKKK/"); 

    hashyboi.insertWord("A", "/ttttt/"); 

    hashyboi.insertWord("B", "/XXXXXX/"); 

    hashyboi.insertWord("C", "/PPPPPPP/"); 

    hashyboi.insertWord("D", "/KKKKK/"); 



   int amount = hashyboi.get_unique_insertions(); 

    cout << "amount of uniqueinsertions:" << amount << endl; 

    hashyboi.print(); 

    hashyboi.runQuery("@insensitive SwAg"); 
}

void testWords()
{

    Word word("JOHN", "/comp/15/thevoid/die/"); 

    string wordName = word.getName(); 

    int amount = word.getAmount();

    cout << "wordName"  << " " <<  wordName << "::" << endl; 
    
    cout << "wordAmount" << " " << amount << " " << endl; 

    
    word.insertFilePos("swaggy/p/");

    word.insertFilePos("/a.out/cool/"); 

    word.insertFilePos("/we/in/this/");

    // word.insertFilePos("NUGGET"); 

    // word.insertFilePos("CHICK");

    // word.insertFilePos("/KJ;ALKSJD;/"); 

    // word.insertFilePos("/KKKKKKKKKKKK/");

    // word.insertFilePos("AAAAA"); 

    // word.insertFilePos("BBBBBBBBB");

    // word.insertFilePos("/CCCCCCCCC/"); 

    // word.insertFilePos("/DDDDDDDDDDD/");

    word.printVector();

    int vector_size = word.VectorSize(); 

    cout << "vector_size == " << vector_size << endl; 
}
