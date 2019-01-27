#include "BSTNode.h"

BSTNode::BSTNode()
{
	this->mEnglishLetter = '\0';
	this->mMorseCode = "";
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

BSTNode::BSTNode(char letter, string morse)
{
	this->mEnglishLetter = letter;
	this->mMorseCode = morse;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

BSTNode::~BSTNode()
{

}

char BSTNode::getLetter()
{
	return this->mEnglishLetter;
}

string BSTNode::getMorse()
{
	return this->mMorseCode;
}

BSTNode*& BSTNode::getpLeft()
{
	return this->mpLeft;
}

BSTNode*& BSTNode::getpRight()
{
	return this->mpRight;
}

bool BSTNode::setLetter(char newLetter)
{
	bool success = false;
	
	this->mEnglishLetter = newLetter;

	if (this->mEnglishLetter == newLetter) success = true;

	return success;
}

bool BSTNode::setMorse(string newMorse)
{
	bool success = false;

	this->mMorseCode = newMorse;

	if (this->mMorseCode == newMorse) success = true;

	return success;
}

bool BSTNode::setpLeft(BSTNode *newpLeft)
{
	bool success = false;

	this->mpLeft = newpLeft;

	if (this->mpLeft == newpLeft) success = true;

	return success;
}

bool BSTNode::setpRight(BSTNode *newpRight)
{
	bool success = false;

	this->mpRight = newpRight;

	if (this->mpRight == newpRight) success = true;

	return success;
}

