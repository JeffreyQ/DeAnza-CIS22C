/*
* Name:		Jeffrey Qiu
* SID: 		20277789
* Class:	CIS 22C
* Date:		07/30/2016
* Instructor:	Professor Eftekhari
* File Name:	main.cpp
*/

#include "HashTable.h"
#include <fstream>
#include <cassert>



int main()
{
	std::string inputStr;
	int numWords;

	
	std::ifstream in("dictionary.txt");
	assert(in);
	in >> numWords;
	std::cout << "There are a total of " << numWords << " words in the dictionary." << std::endl;

	std::cout << "Building dictionary ...";
	HashTable dictionary(numWords);
	std::cout << ".";

	for (int i = 0; i < numWords; i++) {
		in >> inputStr;
		dictionary.insert(inputStr);

		if ((i % 10000) == 0)	// Displaying in progress to end user
			std::cout << ".";
	}
	std::cout << std::endl;
	dictionary.printStats();

	std::ifstream in2("document.txt");
	assert(in2);

	std::cout << "Our dictionary does not contain the following: " << std::endl;
	while (!in2.eof()) {
		in2 >> inputStr;

		if (!dictionary.contains(inputStr)) {
			std::cout << inputStr << std::endl;
		}
	}

	std::cout << "\n" << "Press any key to quit." << std::endl;
	std::cin.get();
	return 0;
}






/* -- Program Output -- Executed on linux; compiled by g++ v4.9.1 (incl. C++11)

Building dictionary ......................................................................
Minimum Chain Length:   1
Maximum Chain Length:   7
Mean Chain Length:      1.2571

Our dictionary does not contain the following:
jhgfd
bazoogla
pikachu
pokemon

Press any key to quit.

*/