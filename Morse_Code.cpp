/*
Morse_Code.cpp file
*/

#include "Morse_Code.h"

Morse_Code::Morse_Code(ifstream& file)
{
	treeMade = false;
	root = new tree;
	root->letter = '~';
	root->dotdash = "";
	root->Left = nullptr;		// no nodes
	root->Right = nullptr;
	
	string line;
	while (getline(file, line)) {
		for (int i = 1; i < line.size(); i++)
			asciiToDot[line[0]] += line[i];
		makeTree(line[0]);
	}
}

char Morse_Code::getLetter(string code)
//read in code, search through map to find key(code) and return letter
{
	map<string, char>::const_iterator it= dotToAscii.find(code);
	if (it != dotToAscii.end())
	{
		return it->second;
	}
	else
		return NULL;
}


//read in string
//step through string one "character" at a time, the delim will be a space or end line
//traverse binary tree by going to left child at '.' and right child at '-' or '_'
//using tree rather than map as it is quicker
string Morse_Code::decode(string code)
{	
	string decode; // result

	string ltr;
	stringstream str(code);
	while (getline(str, ltr, ' ') || getline(str, ltr, '\n')) {
		tree **ptr = &root;

		for (int i = 0; i < ltr.size(); i++)
		{
			if (ltr[i] == '.')
				ptr = &((*ptr)->Left);
			if (ltr[i] == '_' || ltr[i] == '-')
				ptr = &((*ptr)->Right);
		}
		decode += (*ptr)->letter;
	}

	return decode;
}


string Morse_Code::encode(string str)
{
	//read in string
	//step through one character at a time
	//characters will only be letters, string in will be single word only
	//send first character to getCode
	//returned code character will be added to new string
	//space needs to be added to new string after each character return
	//repeat until string is empty
	string TempString;
	string ENCODED;
	for (int i = 0; i < str.length(); i++)
	{
		map<char, string>::const_iterator it = asciiToDot.find(tolower(str[i]));
		if (it != asciiToDot.end())
		{
			ENCODED += it->second + " ";
		}
		else
			return "";
	}
	return ENCODED;
}


// creates tree for each character as decoding from a tree is faster than iterating through map
void Morse_Code::makeTree(char key){
	tree **currTree = &root;				// Pointer to a pointer to root
	for (int i=0; i <= asciiToDot[key].length(); i++){
		if (asciiToDot[key][i] == '.'){			// dot = Navigate left
			if ((*currTree)->Left == nullptr){		// if node DNE
				(*currTree)->Left = new tree;		// make it as empty node
				currTree = &((*currTree)->Left);	// advance to dummy node
			}
			else {
				currTree = &((*currTree)->Left);	// node exists lets go
			}
		}
		else if (asciiToDot[key][i] == '-' || asciiToDot[key][i] == '_'){ // dash = navigate right
			if ((*currTree)->Right == nullptr){
				(*currTree)->Right = new tree;
				currTree = &((*currTree)->Right); 
			}
			else {
				currTree = &((*currTree)->Right);
			}
		}
	}
	
	(*currTree)->dotdash = asciiToDot[key]; // found the correct location
	(*currTree)->letter = key;		// set dots and letters
	
	if (asciiToDot.size() > 25){
		treeMade = true;				// Use this to keep other functions disabled
										// until tree is populated
	}
}
