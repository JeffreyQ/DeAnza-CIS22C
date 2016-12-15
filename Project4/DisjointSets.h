/*
* Name:		Jeffrey Qiu
* Class:		CIS 22C
* Date:		08/05/2016
* Instructor:	Professor Eftekhari
* File Name:	DisjointSets.h
*
* Description:	This is the header file for the DisjointSets class.
*/

/*
*   * A maze is a 2 dimension matrix
*
*         0   1   2   3   4   5
*      -+------------------------
*      0| r0  r1  r2  r3  r4  r5
*      1| r6  r7  r8  r9  r10 r11
*      2| r12 r13 r14 r15 r16 r17
*      3| r18 r19 r20 r21 r22 r23
*      4| r24 r25 r26 r27 r28 r29
*      5| r30 r31 r32 r33 r34 r35
*
*   maze with dimension size of 6
*
*
*/

#ifndef DISJOINT_SETS_H
#define DISJOINT_SETS_H


#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <math.h>
#include <fstream>
#include "Room.h"
#include "Graph.h"
using namespace std;


class DisjointSets
{

private:
	std::vector<Room> rooms;	// Vector that stores the Rooms of our maze
	int mazeDim;		// dimension of the maze
	int randNum(int mod);	// random pseudorandom number generator seeded on time()
	int randomNeighbor(int& room1, int& room2);	// establishes a random pair of adjacent rooms to be neighbors
	void swap(int& x, int& y);

public:
	DisjointSets(int dim);	// Initialize each set within the disjoint sets
	int find(int roomIdx);	// Returns the representative of this Room's set
	void unionSets(int roomRep1, int roomRep2);		// Merges two sets within the disjoint sets
	void printSets();	//	Debugging tool to print each room # and respective representative #
	void printSolution();	
	void printMaze();		//	Print maze and flag all rooms that are on the solution path
	void outputMaze();		//	Print the map in the format as specified in the program specifications
	void printMazePath();	//	Print only the solution path
	void genMaze(Graph& adjList);	// open doors between neighbors and set weight in Graph to 1 for randomly generated mazes
	void inputMaze(int dim, ifstream& in);	// create a maze based on input read from a file formatted according to program specifications
	void buildGraph(Graph& g, int dim);		// set weight in Graph to 1 for mazes inputted from file
	void BFS(Graph& g);				// Breadth First Search algorithm to traverse our graph and flag rooms on solution path
	void resetRooms(int dim);		// reset rooms to default state
	void DFS(Graph& g);				// Depth First Search algorithm to traverse our graph and flag rooms on solution path
	void printStack(std::stack<Room> s);
};



#endif