#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

class BSTNode
{

public:
	// constructor
	BSTNode();
	// copy constructor
	BSTNode(char letter, string morse);
	// destructor
	~BSTNode();

	// getters
	char getLetter();
	string getMorse();
	BSTNode *&getpLeft();
	BSTNode *&getpRight();

	// setters
	bool setLetter(char newLetter);
	bool setMorse(string newMorse);
	bool setpLeft(BSTNode *newpLeft);
	bool setpRight(BSTNode *newpRight);

private:
	char mEnglishLetter;
	string mMorseCode;
	BSTNode *mpLeft;
	BSTNode *mpRight;
};
