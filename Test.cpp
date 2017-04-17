#include "Morse.h"
#include "Binary_Search_Tree.h"

using namespace std;

void main() {
	ifstream inputfile;
	inputfile.open("morse.txt");
	Morse morse_code(inputfile);

	inputfile.close();
}