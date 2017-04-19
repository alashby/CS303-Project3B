// Al Ashby
// Jade Sissel
// CS303
// Project 3-B

#ifndef _Morse_Code
#define _Morse_Code

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include <sstream>
#include "ExpressionError.h"


using namespace std;

struct tree {
	tree() { Left = nullptr; Right = nullptr; }
	char letter;
	string dotdash;
	tree *Left, *Right;
};

class Morse_Code{
public:
	/*Reads in a file with the format "[symbol][dot-dash form]" 
	separated by new lines to create a tree and map for encoding and decoding morse code.
	@param file File to read the symbols and code from
	*/
	Morse_Code(ifstream& file);

	/*Reads a string of dot-dash morse code (either using - or _ as dashes) and translates it
	into its ascii form.
	@param code String of .'s, -'s, _'s, and/or spaces to be decodes
	@return The morse code now decoded as ascii
	@throw Expression_Error if code contains chars that are not '.', '-', '_', or whitespace
	*/
	string decode(string code); //dot dash to letter

	/*Reads a string of ascii characters and translates it into dot-dash morse code.
	@param str String to be encoded
	@return The string now encoded as dot-dash morse code
	@throw Expression_Error if string contains symbols that are not whitespace and were not given a dot-dash
	form by the given file
	*/
	string encode(string str); //letter to dash dot

private:
	/*Takes the key (letter) for a symbol found in the map asciiToDot and adds it to a binary tree.
	Each char in the value (morse code) is evaluated so that when a . is present, it will traverse the 
	left child path and when a - or _ is present, it will traverse the right child path. When there are no
	more characters to be evaluated, it designates the map key and value in that node of the tree.
	@param key The symbol to be added to the tree
	*/
	void makeTree(char key); // also populates maps


	// Data

	// Stores symbol (key) and dot-dash form (value) for encode function
	map<char, string> asciiToDot;

	// Main root of the morse code tree
	tree *root;

};

#endif /* Morse_Code.hpp */

