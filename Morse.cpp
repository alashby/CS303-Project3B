#include "Morse.h"

using namespace std;

Morse::Morse(ifstream& file) {
	char letter; // alphabetical letter morse code is representing
	string line;
	binary_tree.push_back(' '); // spaces are spaces
	while (getline(file, line)) {
		letter = line[0]; // first char of each line is the letter
		// starting at root, traverse tree (vector) to find node (index) to place letter
		int parent = 0; 
		for (int i = 1; i < line.size(); i++)
		{
			if (line[i] == '.') // dots traverse to left child
				parent = 2 * parent + 1;
			if (line[i] == '_') // dashes traverse to right child
				parent = 2 * parent + 2;
		}
		if (parent > binary_tree.size()) // resize vector to be able to intake letter at found index
			binary_tree.resize(parent + 1);
		binary_tree[parent] = letter;
	}
}