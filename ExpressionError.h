// Al Ashby
// Jade Sissel
// CS303
// Project 3-B

#pragma once
#include <stdexcept>
using namespace std;

class Expression_Error : public invalid_argument {
public:
	Expression_Error(string msg) : invalid_argument(msg) {}
};