#include "BST.h"

BST::BST()
{
	this->pRoot = nullptr;
	
	char letter = '\0';
	string morse = "";
	
	fstream input("MorseTable.txt");

	do 
	{
		// reset variables to default
		letter = '\0';
		morse = "";

		// read in data from line in file
		input >> letter;
		input >> morse;

		// insert new data into the BST
		insert(letter, morse);


	} while (letter != '\0' && morse != "");
	// Ran into issue where file would stream would never "close" and the loop continued. Used this new conditional
	// to make sure it would only run while 

	input.close();
}

BST::~BST()
{
	deleteTree(this->pRoot);
}

void BST::insert(char letter, string morse)
{
	insert(pRoot, letter, morse);
}

void BST::printBST()
{
	printBST(pRoot);
}

string BST::searchBST(char target)
{
	string morse = "";

	target = toupper(target);
	morse = searchBST(this->pRoot, target);

	return morse;
}

void BST::convertText()
{
	char letter = '\0';
	string morse = "";
	
	fstream input("Convert.txt");

	do
	{
		letter = '\0';
		morse = "";

		input >> letter;

		if (letter != '\0')
		{
			morse = searchBST(letter);
			cout << morse << " ";
		}
	} while (letter != '\0');

	putchar('\n');

	input.close();
}

void BST::runApp()
{

}

void BST::insert(BSTNode *&pRoot, char letter, string morse)
{
	// checking against the problem of the file being at the end yet still running the loop
	if (letter != '\0' && morse != "")
	{

		// if there is no node
		if (pRoot == nullptr)
		{
			// create a new node with the data and add it to the position
			pRoot = new BSTNode(letter, morse);
		}
		else
		{
			// if the data is less than the existing data in the node
			if (pRoot->getLetter() > letter)
			{
				// recursively call the function with the left node
				insert(pRoot->getpLeft(), letter, morse);
			}
			// if the data is greater than the existing data in the node
			else if (pRoot->getLetter() < letter)
			{
				// recursively call the function with the right node
				insert(pRoot->getpRight(), letter, morse);
			}
		}
	}
}

//void BST::insert(BSTNode *pRoot, char letter, string morse)
//{
//	insert(&pRoot, letter, morse);
//}

void BST::deleteTree(BSTNode *pTree)
{
	if (pTree->getpLeft() == nullptr && pTree->getpRight() == nullptr)
	{
		delete pTree;
	}
	else if (pTree->getpLeft() != nullptr)
	{
		deleteTree(pTree->getpLeft());
	}
	else if (pTree->getpRight() != nullptr)
	{
		deleteTree(pTree->getpRight());
	}
}

void BST::printBST(BSTNode *pRoot)
{
	if (pRoot != nullptr)
	{
		// if it is possible to go left
		if (pRoot->getpLeft() != nullptr)
		{
			// continue along the tree through the left node
			printBST(pRoot->getpLeft());
		}

		// once we have traversed as far left as we can, print out the letter of the current node
		cout << pRoot->getLetter() << " ";

		// if it is possible to go right
		if (pRoot->getpRight() != nullptr)
		{
			// continue along the tree through the right node
			printBST(pRoot->getpRight());
		}
	}
}

string BST::searchBST(BSTNode *&pRoot, char target)
{
	string morse = "";

	// if we find the letter we are looking for
	if (pRoot->getLetter() == target)
	{
		morse = pRoot->getMorse();
	}

	// if our target is less than the current node's letter
	else if (pRoot->getLetter() > target)
	{
		// continue down to the left node of the tree
		morse = searchBST(pRoot->getpLeft(), target);
	}

	// if our target is greater than the current node's letter
	else if (pRoot->getLetter() < target)
	{
		// continue down to the right node of the tree
		morse = searchBST(pRoot->getpRight(), target);
	}
	else
	{
		cout << "Letter not found.";
	}
	return morse;
}
