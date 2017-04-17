#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "Binary_Search_Tree.h"
#include "Binary_Tree.h"

using namespace std;

class Morse {
public:
	Morse(ifstream& file);
	//string encode(string msg) { return ""; }
	//string decode(string msg) { return ""; }
private:
	map<char, string> morse_list;
};