#include "Morse_Code.h"

using namespace std;

void main() {
	ifstream inputfile;
	inputfile.open("morse.txt");
	Morse_Code morse_code(inputfile);
	string morse = "- . ... -";
	string ascii = "test";
	cout << morse_code.decode(morse) << endl;
	cout << morse_code.encode(ascii) << endl;

	inputfile.close();
	system("pause");
}