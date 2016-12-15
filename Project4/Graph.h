/*
* Name:		Jeffrey Qiu
* Class:		CIS 22C
* Date:		08/05/2016
* Instructor:	Professor Eftekhari
* File Name:	Graph.h
*
* Description:	This is the header file for the Graph class.
*/



#ifndef GRAPH_H 
#define GRAPH_H


#include <iostream>


using namespace std;




class Graph	// This data structure serves as an adjacency matrix storing weights between neighbors
{

private:
	int** adjArr; 	// 2-d array to store weights between all rooms, with 1 indicating neighbors, and >1 indicating non-neighbor
	int arrDim;		// array dimension size

public:
	Graph(int dim);		// initialize all nodes as non-neighbors with weight of dim * dim
	bool setNeighbors(int neighbor1, int neighbor2);	// if two nodes are neighbors then record weight as 1
	bool isNeighbor(int neighbor1, int neighbor2);		// return true if both are neighbors, false otherwise
	void printGraph();
};



#endif
