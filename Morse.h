#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Morse {
public:
	Morse(ifstream& file);
	//string encode(string msg) { return ""; }
	//string decode(string msg) { return ""; }
private:
	vector<char> binary_tree;
};