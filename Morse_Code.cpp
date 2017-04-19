// Al Ashby
// Jade Sissel
// CS303
// Project 3-B

#include "Morse_Code.h"

Morse_Code::Morse_Code(ifstream& file)
{
	// Creating new, unfilled tree
	root = new tree;
	root->letter = '~';
	root->dotdash = "";
	root->Left = nullptr;		// no nodes
	root->Right = nullptr;
	
	// Filling tree and map (asciiToDot)
	string line;
	while (getline(file, line)) {
		for (int i = 1; i < line.size(); i++)
			asciiToDot[line[0]] += line[i];
		makeTree(line[0]);
	}
}



string Morse_Code::decode(string code)
{	
	string DECODED; // result

	string ltr;
	stringstream str(code);
	// Read in each string while stopping at spaces or new lines
	while (getline(str, ltr, ' ') || getline(str, ltr, '\n')) {
		tree **ptr = &root;

		// Read in each character from string
		for (int i = 0; i < ltr.size(); i++)
		{
			// dots traverse to the left child in the subtree
			if (ltr[i] == '.')
				ptr = &((*ptr)->Left);
			// dashes traverse to the right child in the subtree
			else if (ltr[i] == '_' || ltr[i] == '-')
				ptr = &((*ptr)->Right);
			else
				Expression_Error("Code not in proper dot-dash form.");
		}
		DECODED += (*ptr)->letter;
	}

	return DECODED;
}


string Morse_Code::encode(string str)
{
	string ENCODED;
	// Read character one at a time
	for (int i = 0; i < str.length(); i++)
	{
		// Using iterator to find the character in the map (in its lowercase form)
		map<char, string>::const_iterator it = asciiToDot.find(tolower(str[i]));
		// If the character is found, add it to the output string
		if (it != asciiToDot.end())
			ENCODED += it->second + " ";
		else if (it == asciiToDot.end() && str[i] != ' ')
			Expression_Error("Symbol not found in given morse code library.");
	}
	return ENCODED;
}


// Creates tree for each character as decoding from a tree is faster than iterating through map
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
	

}
