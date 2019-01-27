#include "BSTNode.h"

class BST
{

public:
	// constructor
	BST();
	// destructor
	~BST();

	// insert
	void insert(char letter, string morse);

	// print
	void printBST();

	// search
	string searchBST(char target);

	// convert
	void convertText();

	// run app
	void runApp();

private:

	// private insert
	void insert(BSTNode *&pRoot, char letter, string morse);

	// helper insert?? just an attempt // didn't work
	// void insert(BSTNode *pRoot, char letter, string morse);

	// delete tree (to be called in destructor)
	void deleteTree(BSTNode *pRoot);

	// private print
	void printBST(BSTNode *pRoot);

	// private search
	string searchBST(BSTNode *&pRoot, char target);

	// tree root
	BSTNode *pRoot;

};

