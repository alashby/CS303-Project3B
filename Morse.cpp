#include "Morse.h"
#include <map>

using namespace std;

Morse::Morse(ifstream& file) {
	string letter; // alphabetical letter morse code is representing
	string line;
	while (getline(file, line)) {
		letter = line[0]; // first char of each line is the letter
		// starting at root, traverse tree (vector) to find node (index) to place letter
		for (int i = 1; i < line.size(); i++)
		{
			morse_list[line[0]] += line[i];
		}
	};
}