// Al Ashby
// Jade Sissel
// CS303
// Project 3-B

#include "Morse_Code.h"

using namespace std;

void main() {
	ifstream inputfile;
	inputfile.open("morse.txt");
	Morse_Code morse_code(inputfile);
	string morse = "_ .... . __._ .._ .. _._. _._ _... ._. ___ .__ _. .._. ___ _.._ .___ .._ __ .__. . _.. ___ ..._ . ._. _ .... . ._.. ._ __.. _.__ _.. ___ __.";
	string ascii = "the quick brown fox jumped over the lazy dog";
	cout << morse_code.decode(morse) << endl;
	cout << morse_code.encode(ascii) << endl;

	inputfile.close();
	system("pause");
}