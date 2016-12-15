/*
* Name:		Jeffrey Qiu
* SID: 		20277789
* Class:	CIS 22C
* Date:		07/26/2016
* Instructor:	Professor Eftekhari
* File Name:	ClientApp.cpp
*/



//#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include "SearchTree.h"
#include "Entry.h"

using namespace std;


void buildTrees(void);
int testTrees(void);
vector<string> split(const string&, char);


const int MAX_NUM_TREES = 100;
const int DEFAULT_VALUE = 0;



int main(int argc, const char * argv[])
{
	//	testTrees();
	buildTrees();

	return 0;
}



void buildTrees()
{
	char delim = ' ';
	string inputStr;
	int numTrees;
	size_t lastOffset = 0;

	ifstream in("input.txt");
	assert(in);


	// get num trees from first line
	getline(in, inputStr);
	sscanf(inputStr.c_str(), "%d", &numTrees);

	// loop numTrees times 
	for (int i = 0; i < numTrees; i++) {
		// build trees

		typedef SearchTree<Entry<int, int> > ST;
		ST mySearch;

		int numNodes;
		int key;
		getline(in, inputStr);	// get next line

		vector<string> tokens = split(inputStr, delim); //	tokenize BST info
		numNodes = tokens.size() - 1; //	first element indicates numNodes

		vector<string>::iterator it;
		it = tokens.begin();
		advance(it, 1);
		for (it; it != tokens.end(); ++it) {
			sscanf((*it).c_str(), "%d", &key);
			mySearch.insert(key, DEFAULT_VALUE);
		}


		cout << endl;
		cout << "Tree " << i + 1 << ": " << endl << endl;
		mySearch.getTree().printTraversals();
		cout << endl;

		cout << "Balanced Tree " << i + 1 << ": " << endl << endl;
		mySearch.balance();
		cout << endl;
	}
}



vector<string> split(const string& s, char delim)
{
	stringstream ss;
	ss << s;
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}



int testTrees()
{
	// insert code here...

	typedef SearchTree<Entry<int, int> > ST;
	ST mySearch;

	mySearch.insert(10, 234);
	mySearch.insert(9, 1200);
	mySearch.insert(8, 1400);
	mySearch.insert(7, 1600);
	mySearch.insert(6, 1900);
	mySearch.insert(5, 2900);
	mySearch.insert(4, 2900);
	mySearch.insert(3, 2900);
	mySearch.insert(2, 2900);
	mySearch.insert(1, 2900);

	/*
	cout << "total number of items:   " << mySearch.size() << endl;
	ST::Iterator itr = mySearch.begin();
	while (!(itr == mySearch.end())) {  // inorder visit
	cout << (*itr).key() << endl;
	//        cout<< (*itr).value() <<endl;
	++itr;
	}
	*/
	cout << endl;
	cout << "Tree 1: " << endl << endl;
	mySearch.getTree().printTraversals();
	cout << endl;

	cout << "Balanced Tree 1: " << endl << endl;
	mySearch.balance();
	cout << endl;

	return 0;
}
