/*
* Name:		Jeffrey Qiu
* SID: 		20277789
* Class:	CIS 22C
* Date:		07/30/2016
* Instructor:	Professor Eftekhari
* File Name:	HashTable.h
*/


#ifndef HASH_TABLE_H
#define HASH_TABLE_H


#include <string>
#include <vector>
#include <list>
#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>


const int INITIAL_TABLE_SIZE = 101;


class HashTable
{
public:
	HashTable(size_t tableSize);

	bool contains(const std::string& x) const;

	void makeEmpty();
	bool insert(const std::string& x);
	bool remove(const std::string& x);
	void printStats();

private:
	std::vector<std::list<std::string>> hashTable;
	int currentSize;

	void rehash();
	size_t myhash(const std::string& x) const;

	bool isPrime(int number);
	int nextPrime(int a);
};





#endif