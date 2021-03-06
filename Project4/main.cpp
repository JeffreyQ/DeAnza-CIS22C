/*
* Name:		Jeffrey Qiu
* Class:		CIS 22C
* Date:		08/05/2016
* Instructor:	Professor Eftekhari
* File Name:	main.cpp
*
* Description:	This is the client file for Assignment 4.

For this final programming project I implemented the Disjoint Sets, Stack, Queue, and Graph
data structures to create a program that solves mazes that are either generated randomly or
generated by hand following a certain format as specified in the assignment specifications.
To solve the maze we populate our graph with data that indicates which of our rooms in the
maze are neighbors to one another, and then use BFS and DFS algorithms to find the shortest
path from the start room to finish room. 

*/



#include "DisjointSets.h"
#include "Graph.h"
#include <string>
#include <assert.h>
using namespace std;


void mazeFromFile(std::string);
void mazeFromRandom();



int main(int argc, char** argv)
{
	std::string fname = "maze.txt";
	srand(time(NULL));		// initialize the random seed

	if (argc > 1) {
		fname = argv[1];
		mazeFromFile(fname);
	}
	else {
		mazeFromRandom();
	}

	return 0;
}




void mazeFromFile(std::string fname)
{
	int mazeDim = 0;
	int totalRooms = 0;

	ifstream in(fname.c_str());
	assert(in);
	in >> mazeDim;
	totalRooms = mazeDim * mazeDim;

	std::cout << std::endl;
	std::cout << "There are a total of " << totalRooms << " rooms." << std::endl;

	DisjointSets djs(mazeDim);
	Graph adjList(mazeDim);
	djs.inputMaze(mazeDim, in);
	djs.buildGraph(adjList, mazeDim);

	std::cout << std::endl;
	djs.printMaze();
	std::cout << std::endl;

	std::cout << std::endl;
	djs.BFS(adjList);
	std::cout << "X denotes the path:" << std::endl;
	djs.printMaze();

	std::cout << std::endl;

	std::cout << std::endl;
	djs.DFS(adjList);
	std::cout << "X denotes the path:" << std::endl;
	djs.printMaze();

	std::cout << std::endl;

}




void mazeFromRandom()
{
	int mazeDim = 0;

	std::cout << std::endl;
	std::cout << "Enter size of maze (greater than 1): ";
	std::cin >> mazeDim;

	if (mazeDim < 2) {
		std::cout << "Error: must be greater than 1." << std::endl;
		return;
	}



	std::cout << std::endl;

	DisjointSets djs(mazeDim);
	Graph adjList(mazeDim);
	djs.genMaze(adjList);

	std::cout << std::endl;
	djs.printMaze();
	std::cout << std::endl;

	std::cout << std::endl;
	djs.BFS(adjList);
	std::cout << "X denotes the path:" << std::endl;
	djs.printMaze();

	std::cout << std::endl;

	std::cout << std::endl;
	djs.DFS(adjList);
	std::cout << "X denotes the path:" << std::endl;
	djs.printMaze();

	std::cout << std::endl;
}






/* ~Program Output~ Generated from maze file (a.out maze.txt)


There are a total of 25 rooms.


0000011111222223333344444
0  +   ++---++---++---++---+
0  |   ||        ||        |
0  +   ++---++   ++---++   +
1  +   ++---++   ++---++   +
1  |   ||             ||   |
1  +   ++---++---++   ++   +
2  +   ++---++---++   ++   +
2  |                       |
2  +---++---++   ++   ++   +
3  +---++---++   ++   ++   +
3  |        ||   ||   ||   |
3  +---++   ++   ++   ++---+
4  +---++   ++   ++   ++---+
4  |             ||        |
4  +---++---++---++---++   +
0000011111222223333344444


Rooms visited by BFS: 0 5 10 11 12 17 13 22 8 18 14 21 7 23 9 19 16 20 2 6 24
This is the path (in reverse): 24 23 18 13 12 11 10 5 0
X denotes the path:

0000011111222223333344444
0  +   ++---++---++---++---+
0  | X ||        ||        |
0  +   ++---++   ++---++   +
1  +   ++---++   ++---++   +
1  | X ||             ||   |
1  +   ++---++---++   ++   +
2  +   ++---++---++   ++   +
2  | X    X    X    X      |
2  +---++---++   ++   ++   +
3  +---++---++   ++   ++   +
3  |        ||   || X ||   |
3  +---++   ++   ++   ++---+
4  +---++   ++   ++   ++---+
4  |             || X    X |
4  +---++---++---++---++   +
0000011111222223333344444


Rooms visited by DFS: 0 5 10 11 12 13 14 19 9 4 3 18 23 24
This is the path (in reverse): 24 23 18 13 12 11 10 5 0
X denotes the path:

0000011111222223333344444
0  +   ++---++---++---++---+
0  | X ||        ||        |
0  +   ++---++   ++---++   +
1  +   ++---++   ++---++   +
1  | X ||             ||   |
1  +   ++---++---++   ++   +
2  +   ++---++---++   ++   +
2  | X    X    X    X      |
2  +---++---++   ++   ++   +
3  +---++---++   ++   ++   +
3  |        ||   || X ||   |
3  +---++   ++   ++   ++---+
4  +---++   ++   ++   ++---+
4  |             || X    X |
4  +---++---++---++---++   +
0000011111222223333344444


*/



/* ~Program Output~ Generated without maze file (a.out)


Enter size of maze (greater than 1): 5



0000011111222223333344444
0  +   ++---++---++---++---+
0  |   ||        ||        |
0  +   ++---++   ++   ++---+
1  +   ++---++   ++   ++---+
1  |                       |
1  +   ++   ++---++---++---+
2  +   ++   ++---++---++---+
2  |   ||   ||        ||   |
2  +   ++   ++---++   ++   +
3  +   ++   ++---++   ++   +
3  |   ||   ||   ||        |
3  +   ++   ++   ++---++   +
4  +   ++   ++   ++---++   +
4  |   ||                  |
4  +---++---++---++---++   +
0000011111222223333344444


Rooms visited by BFS: 0 5 10 6 15 11 7 20 16 2 8 21 1 3 9 22 4 17 23 24
This is the path (in reverse): 24 23 22 21 16 11 6 5 0
X denotes the path:

0000011111222223333344444
0  +   ++---++---++---++---+
0  | X ||        ||        |
0  +   ++---++   ++   ++---+
1  +   ++---++   ++   ++---+
1  | X    X                |
1  +   ++   ++---++---++---+
2  +   ++   ++---++---++---+
2  |   || X ||        ||   |
2  +   ++   ++---++   ++   +
3  +   ++   ++---++   ++   +
3  |   || X ||   ||        |
3  +   ++   ++   ++---++   +
4  +   ++   ++   ++---++   +
4  |   || X    X    X    X |
4  +---++---++---++---++   +
0000011111222223333344444


Rooms visited by DFS: 0 5 6 7 8 9 3 4 2 1 11 16 21 22 23 24
This is the path (in reverse): 24 23 22 21 16 11 6 5 0
X denotes the path:

0000011111222223333344444
0  +   ++---++---++---++---+
0  | X ||        ||        |
0  +   ++---++   ++   ++---+
1  +   ++---++   ++   ++---+
1  | X    X                |
1  +   ++   ++---++---++---+
2  +   ++   ++---++---++---+
2  |   || X ||        ||   |
2  +   ++   ++---++   ++   +
3  +   ++   ++---++   ++   +
3  |   || X ||   ||        |
3  +   ++   ++   ++---++   +
4  +   ++   ++   ++---++   +
4  |   || X    X    X    X |
4  +---++---++---++---++   +
0000011111222223333344444

*/



/* ~Program Output~ Generated without maze file (a.out)

Enter size of maze (greater than 1): 7



00000111112222233333444445555566666
0  +   ++---++---++---++---++---++---+
0  |             ||                  |
0  +---++---++   ++   ++---++---++---+
1  +---++---++   ++   ++---++---++---+
1  |             ||   ||             |
1  +---++   ++---++   ++   ++---++   +
2  +---++   ++---++   ++   ++---++   +
2  |             ||        ||        |
2  +   ++---++   ++   ++---++---++   +
3  +   ++---++   ++   ++---++---++   +
3  |   ||             ||             |
3  +---++---++   ++   ++---++   ++---+
4  +---++---++   ++   ++---++   ++---+
4  |   ||   ||   ||   ||   ||        |
4  +---++   ++---++   ++   ++   ++   +
5  +---++   ++---++   ++   ++   ++   +
5  |                  ||        ||   |
5  +---++   ++---++   ++   ++   ++   +
6  +---++   ++---++   ++   ++   ++   +
6  |             ||   ||   ||   ||   |
6  +---++---++---++---++---++---++   +
00000111112222233333444445555566666


Rooms visited by BFS: 0 1 2 9 8 15 7 16 14 23 21 30 24 22 17 31 10 18 38 3 11 45 37 4 12 36 5 13 29 43 35 6 20 44 42 27 19 26 33 25 40 34 47 39 41 32 46 48
This is the path (in reverse): 48 41 34 33 26 27 20 13 12 11 18 17 24 23 16 15 8 9 2 1 0
X denotes the path:

00000111112222233333444445555566666
0  +   ++---++---++---++---++---++---+
0  | X    X    X ||                  |
0  +---++---++   ++   ++---++---++---+
1  +---++---++   ++   ++---++---++---+
1  |      X    X ||   || X    X    X |
1  +---++   ++---++   ++   ++---++   +
2  +---++   ++---++   ++   ++---++   +
2  |      X    X || X    X ||      X |
2  +   ++---++   ++   ++---++---++   +
3  +   ++---++   ++   ++---++---++   +
3  |   ||      X    X ||      X    X |
3  +---++---++   ++   ++---++   ++---+
4  +---++---++   ++   ++---++   ++---+
4  |   ||   ||   ||   ||   || X    X |
4  +---++   ++---++   ++   ++   ++   +
5  +---++   ++---++   ++   ++   ++   +
5  |                  ||        || X |
5  +---++   ++---++   ++   ++   ++   +
6  +---++   ++---++   ++   ++   ++   +
6  |             ||   ||   ||   || X |
6  +---++---++---++---++---++---++   +
00000111112222233333444445555566666


Rooms visited by DFS: 0 1 2 9 8 7 15 14 21 16 23 22 24 31 38 37 36 35 43 42 44 29 45 17 18 11 12 13 20 19 27 26 25 33 34 41 48
This is the path (in reverse): 48 41 34 33 26 27 20 13 12 11 18 17 24 23 16 15 8 9 2 1 0
X denotes the path:

00000111112222233333444445555566666
0  +   ++---++---++---++---++---++---+
0  | X    X    X ||                  |
0  +---++---++   ++   ++---++---++---+
1  +---++---++   ++   ++---++---++---+
1  |      X    X ||   || X    X    X |
1  +---++   ++---++   ++   ++---++   +
2  +---++   ++---++   ++   ++---++   +
2  |      X    X || X    X ||      X |
2  +   ++---++   ++   ++---++---++   +
3  +   ++---++   ++   ++---++---++   +
3  |   ||      X    X ||      X    X |
3  +---++---++   ++   ++---++   ++---+
4  +---++---++   ++   ++---++   ++---+
4  |   ||   ||   ||   ||   || X    X |
4  +---++   ++---++   ++   ++   ++   +
5  +---++   ++---++   ++   ++   ++   +
5  |                  ||        || X |
5  +---++   ++---++   ++   ++   ++   +
6  +---++   ++---++   ++   ++   ++   +
6  |             ||   ||   ||   || X |
6  +---++---++---++---++---++---++   +
00000111112222233333444445555566666

*/




