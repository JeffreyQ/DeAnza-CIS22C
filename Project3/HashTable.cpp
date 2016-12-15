/*
* Name:		Jeffrey Qiu
* SID: 		20277789
* Class:	CIS 22C
* Date:		07/30/2016
* Instructor:	Professor Eftekhari
* File Name:	HashTable.cpp
*/


#include "HashTable.h"



// We implement our hash table with a vector of string lists each initialized with an empty list.
// This constructor also covers the default no-arg constructor.
HashTable::HashTable(size_t tableSize = INITIAL_TABLE_SIZE)
{
	std::list<std::string> strList = {};
	for (int i = 0; i <= tableSize; i++)
		hashTable.push_back(strList);
}



bool HashTable::contains(const std::string& key) const
{
	auto& whichList = hashTable[myhash(key)];
	bool contains = (find(begin(whichList), end(whichList), key) != end(whichList));

	return contains;
}



void HashTable::makeEmpty()
{
	for (auto& thisList : hashTable)
		thisList.clear();

	currentSize = 0;
}



bool HashTable::insert(const std::string& key)
{
	size_t hashVal = myhash(key);

	std::list<std::string>& whichList = hashTable[hashVal];
	if (find(begin(whichList), end(whichList), key) != end(whichList))
		return false;
	whichList.push_back(key);

	if (++currentSize > hashTable.size())
		rehash();

	return true;
}



bool HashTable::remove(const std::string& key)
{
	auto& whichList = hashTable[myhash(key)];
	auto itr = find(begin(whichList), end(whichList), key);

	if (itr == end(whichList))
		return false;

	whichList.erase(itr);
	--currentSize;
	return true;
}



void HashTable::printStats()
{
	size_t minChainLen = ULONG_MAX;
	size_t maxChainLen = 0;
	size_t totalChainLen = 0;
	size_t numChains = 0;
	double meanChainLen;

	std::vector<std::list<std::string>>::const_iterator it;
	for (it = hashTable.begin(); it != hashTable.end(); ++it) {

		int listLen = (*it).size();

		if (listLen > 0) {
			totalChainLen += listLen;
			numChains++;

			if (listLen < minChainLen)
				minChainLen = listLen;
			else if (listLen > maxChainLen)
				maxChainLen = listLen;

		}
	}

	meanChainLen = (double)totalChainLen / (double)numChains;


	std::cout << "Minimum Chain Length:" << "\t" << minChainLen << "\n";
	std::cout << "Maximum Chain Length:" << "\t" << maxChainLen << "\n";
	std::cout << "Mean Chain Length:" << "\t" << meanChainLen << "\n";
	std::cout << "\n";
}



void HashTable::rehash()
{
	std::vector<std::list<std::string>> oldLists = hashTable;

	// Create new double-sized empty table
	int newSize = nextPrime(2 * hashTable.size());
	hashTable.resize(newSize);
	currentSize = newSize;
	makeEmpty();

	currentSize = 0;
	for (auto& thisList : oldLists) {
		for (auto& x : thisList) {
			insert(std::move(x));
		}
	}


}



size_t HashTable::myhash(const std::string& key) const
{
	size_t hashVal = 0;

	for (char ch : key)
		hashVal = 37 * hashVal + ch;

	size_t hashNum = hashVal % hashTable.size();

	return hashNum;
}



bool HashTable::isPrime(int x)
{

	for (std::size_t i = 3; true; i += 2)
	{
		std::size_t q = x / i;
		if (q < i)
			return true;
		if (x == q * i)
			return false;
	}
	return true;
}



int HashTable::nextPrime(int x)
{

	if (x <= 2)
		return 2;
	if (!(x & 1))
		x++;
	while (!isPrime(x)) {
		x += 2;
	}
	return x;
}