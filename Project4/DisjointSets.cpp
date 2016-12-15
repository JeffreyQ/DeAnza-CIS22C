/*
* Name:			Jeffrey Qiu
* Class:		CIS 22C
* Date:			08/05/2016
* Instructor:	Professor Eftekhari
* File Name:	DisjointSets.cpp
*
* Description:	This is the implementation file for the DisjointSets class.
*
*/



#include "DisjointSets.h"



int DisjointSets::randNum(int mod) {
	int random = rand() % mod;

	return random;
}



int DisjointSets::randomNeighbor(int& room1, int& room2) {
	int r = randNum(mazeDim * mazeDim);
	int d = randNum(2);					// 0:horizontal neighbor, 1:veritcal neighbor
	room1 = r;
	if (d == 0) {
		if ((room1 % mazeDim) == 0) 	// room1 is on the west border
			room2 = room1++;
		else if ((room1 % mazeDim) == (mazeDim - 1)) 	// room1 is on the east border
			room2 = room1--;
		else
			room2 = room1++;
	}
	else {
		if ((room1 / mazeDim) == 0) 	// room1 is on the north border
			room2 = room1 + mazeDim;
		else if ((room1 / mazeDim) == (mazeDim - 1)) 	// room1 is on the south border
			room2 = room1 - mazeDim;
		else
			room2 = room1 + mazeDim;
	}

	if (room1 > room2)
		swap(room1, room2);

	return d;	// r being the direction for opening doors
}



void DisjointSets::swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}



DisjointSets::DisjointSets(int dim = 5) {
	mazeDim = dim;
	int totalRooms = mazeDim * mazeDim;

	if (mazeDim < 2)
		mazeDim = 5;

	for (int i = 0; i < totalRooms; i++) {
		Room r(i, i);
		rooms.push_back(r);		// Initializing each set of the disjoint sets
	}
}



int DisjointSets::find(int roomIdx) {
	int rep = rooms[roomIdx].getRoomRep();

	return rep;
}



void DisjointSets::unionSets(int roomRep1, int roomRep2) {	// roomRep1 and roomRep2 must be the representatives of their sets
	int totalRooms = mazeDim * mazeDim;
	for (int i = 0; i < totalRooms; i++) {
		if (roomRep2 == rooms[i].getRoomRep()) {
			rooms[i].setRoomRep(roomRep1);
		}
	}
}



void DisjointSets::printSets() {
	int totalRooms = mazeDim * mazeDim;
	for (int i = 0; i < totalRooms; i++) {
		std::cout << "Room # " << i << "; RepSet # " << rooms[i].getRoomRep() << std::endl;
	}
}



void DisjointSets::printSolution() {
	for (int i = 0; i < mazeDim; i++) {
		// print the first row
		for (int j = 0; j < mazeDim; j++) {
			std::cout << " ";
			if (rooms[i*mazeDim + j].isDoorOpen('n'))
				std::cout << "X ";
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
		// print the second row
		for (int j = 0; j < mazeDim; j++) {
			if (rooms[i*mazeDim + j].isDoorOpen('w'))
				std::cout << "XX";
			else
				std::cout << " X";
			if (rooms[i*mazeDim + j].isDoorOpen('e'))
				std::cout << "X";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
		// print the third row
		for (int j = 0; j < mazeDim; j++) {
			std::cout << " ";
			if (rooms[i*mazeDim + j].isDoorOpen('s'))
				std::cout << "X ";
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}
}



void DisjointSets::printMaze() {
	// print the title row
	std::cout << std::endl;
	std::cout << "   ";
	for (int i = 0; i < mazeDim; i++) {
		std::cout << i;
		std::cout << i;
		std::cout << i;
		std::cout << i;
		std::cout << i;
	}
	std::cout << std::endl;

	for (int i = 0; i < mazeDim; i++) {
		// print the side title
		std::cout << i << "  ";

		// print the first row
		for (int j = 0; j < mazeDim; j++) {
			std::cout << "+";
			if (rooms[i*mazeDim + j].isDoorOpen('n'))
				std::cout << "   +";
			else
				std::cout << "---+";
		}
		std::cout << std::endl;
		// print the side title
		std::cout << i << "  ";
		// print the second row
		for (int j = 0; j < mazeDim; j++) {
			if (rooms[i*mazeDim + j].isDoorOpen('w'))
				std::cout << " ";
			else
				std::cout << "|";
			if (rooms[i*mazeDim + j].isPath())
				std::cout << " X ";
			else
				std::cout << "   ";

			if (rooms[i*mazeDim + j].isDoorOpen('e'))
				std::cout << " ";
			else
				std::cout << "|";
		}
		std::cout << std::endl;
		// print the side title
		std::cout << i << "  ";
		// print the third row
		for (int j = 0; j < mazeDim; j++) {
			std::cout << "+";
			if (rooms[i*mazeDim + j].isDoorOpen('s'))
				std::cout << "   +";
			else
				std::cout << "---+";
		}
		std::cout << std::endl;
	}
	// print the bottom title row
	std::cout << "   ";
	for (int i = 0; i < mazeDim; i++) {
		std::cout << i;
		std::cout << i;
		std::cout << i;
		std::cout << i;
		std::cout << i;
	}
	std::cout << std::endl;
}



void DisjointSets::outputMaze() {
	std::cout << mazeDim << std::endl;
	for (int i = 0; i < mazeDim * mazeDim; i++) {
		if (rooms[i].isDoorOpen('n'))
			std::cout << "0";
		else
			std::cout << "1";
		std::cout << " ";

		if (rooms[i].isDoorOpen('s'))
			std::cout << "0";
		else
			std::cout << "1";
		std::cout << " ";

		if (rooms[i].isDoorOpen('e'))
			std::cout << "0";
		else
			std::cout << "1";
		std::cout << " ";

		if (rooms[i].isDoorOpen('w'))
			std::cout << "0";
		else
			std::cout << "1";
		std::cout << std::endl;
	}

}



void DisjointSets::printMazePath() {
	for (int i = 0; i < mazeDim; i++) {
		// print the second row
		for (int j = 0; j < mazeDim; j++) {
			if (rooms[i*mazeDim + j].isPath())
				std::cout << "O";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}



void DisjointSets::genMaze(Graph& adjList) {
	int totalRooms = mazeDim * mazeDim;
	int neighbor1 = -1;
	int neighbor2 = -1;
	int loops = 0;		// loops counter to prevent excessively large mazes

	rooms[0].openDoor('n');					// open entry
	rooms[totalRooms - 1].openDoor('s');	// open exit

	while (find(0) != find(totalRooms - 1) && loops <= 50000) {
		int direction = randomNeighbor(neighbor1, neighbor2);
		if (find(neighbor1) != find(neighbor2)) {
			if (direction == 0) {
				rooms[neighbor1].openDoor('e');
				rooms[neighbor2].openDoor('w');
			}
			else {
				rooms[neighbor1].openDoor('s');
				rooms[neighbor2].openDoor('n');
			}
			adjList.setNeighbors(neighbor1, neighbor2);	//	Set neighbors weight on adjacency graph

			int rep1 = rooms[neighbor1].getRoomRep();
			int rep2 = rooms[neighbor2].getRoomRep();
			unionSets(rep1, rep2);
		}
		loops++;
	}

}



void DisjointSets::inputMaze(int dim, ifstream& in) {
	mazeDim = dim;
	int totalRooms = dim * dim;
	int door = -1;

	for (int i = 0; i < totalRooms; i++) {
		in >> door;
		if (door == 0)
			rooms[i].openDoor('n');
		in >> door;
		if (door == 0)
			rooms[i].openDoor('s');
		in >> door;
		if (door == 0)
			rooms[i].openDoor('e');
		in >> door;
		if (door == 0)
			rooms[i].openDoor('w');
	}
}



void DisjointSets::buildGraph(Graph& g, int dim) {
	int totalRooms = dim * dim;
	for (int i = 0; i < totalRooms; i++) {
		if (i % dim != dim - 1)
			if (rooms[i].isDoorOpen('e') && rooms[i + 1].isDoorOpen('w'))
				g.setNeighbors(i, i + 1);
		if (i <= totalRooms - dim)
			if (rooms[i].isDoorOpen('s') && rooms[i + dim].isDoorOpen('n'))
				g.setNeighbors(i, i + dim);
	}
}



void DisjointSets::BFS(Graph& g)
{
	resetRooms(mazeDim);
	std::cout << "Rooms visited by BFS: ";
	std::queue<Room> Q;
	std::stack<int> S;
	Q.push(rooms[0]);
	rooms[0].visit();

	while (!Q.empty())
	{
		Room r = Q.front();
		S.push(r.getRoom());
		std::cout << r.getRoom() << " ";
		Q.pop();
		int roomId = r.getRoom();
		int totalRooms = mazeDim * mazeDim;
		if ((int)roomId == (int)(totalRooms - 1))
			break;		//	path is found

		int adjRoomId;
		// case 1 north adjacent
		adjRoomId = roomId - mazeDim;
		if (g.isNeighbor(roomId, adjRoomId) && !rooms[adjRoomId].isVisited())
		{
			Q.push(rooms[adjRoomId]);
			rooms[adjRoomId].visit();
		}
		// case 2 south adjacent
		adjRoomId = roomId + mazeDim;
		if (g.isNeighbor(roomId, adjRoomId) && !rooms[adjRoomId].isVisited())
		{
			Q.push(rooms[adjRoomId]);
			rooms[adjRoomId].visit();
		}
		// case 3 east adjacent
		adjRoomId = roomId + 1;
		if (g.isNeighbor(roomId, adjRoomId) && !rooms[adjRoomId].isVisited())
		{
			Q.push(rooms[adjRoomId]);
			rooms[adjRoomId].visit();
		}
		// case 4 west adjacent
		adjRoomId = roomId - 1;
		if (g.isNeighbor(roomId, adjRoomId) && !rooms[adjRoomId].isVisited())
		{
			Q.push(rooms[adjRoomId]);
			rooms[adjRoomId].visit();
		}
	}
	std::cout << std::endl;
	std::cout << "This is the path (in reverse): ";
	int prev = S.top();
	std::cout << prev << " ";
	rooms[prev].setPath();
	S.pop();
	while (!S.empty())
	{
		int curr = S.top();
		if (g.isNeighbor(prev, curr))
		{
			rooms[curr].setPath();
			std::cout << curr << " ";
			prev = curr;
		}
		S.pop();

	}

	std::cout << std::endl;
}



void DisjointSets::resetRooms(int dim) {
	int totalRooms = dim * dim;

	for (int i = 0; i < totalRooms; i++) {
		rooms[i].unvisit();
		rooms[i].resetPath();
	}
}



void DisjointSets::DFS(Graph& g)
{
	resetRooms(mazeDim);
	std::cout << "Rooms visited by DFS: ";
	std::stack<Room> S;
	std::stack<int> sTemp;
	S.push(rooms[0]);
	rooms[0].visit();

	while (!S.empty())
	{
		Room r = S.top();
		sTemp.push(r.getRoom());
		std::cout << r.getRoom() << " ";
		S.pop();
		int roomId = r.getRoom();
		int totalRooms = mazeDim * mazeDim;
		if ((int)roomId == (int)(totalRooms - 1))
			break;		//	path is found

		int adjRoomId;
		// case 1 north adjacent
		adjRoomId = roomId - mazeDim;
		if (g.isNeighbor(roomId, adjRoomId) && !rooms[adjRoomId].isVisited())
		{
			S.push(rooms[adjRoomId]);
			rooms[adjRoomId].visit();
		}
		// case 2 south adjacent
		adjRoomId = roomId + mazeDim;
		if (g.isNeighbor(roomId, adjRoomId) && !rooms[adjRoomId].isVisited())
		{
			S.push(rooms[adjRoomId]);
			rooms[adjRoomId].visit();
		}
		// case 3 east adjacent
		adjRoomId = roomId + 1;
		if (g.isNeighbor(roomId, adjRoomId) && !rooms[adjRoomId].isVisited())
		{
			S.push(rooms[adjRoomId]);
			rooms[adjRoomId].visit();
		}
		// case 4 west adjacent
		adjRoomId = roomId - 1;
		if (g.isNeighbor(roomId, adjRoomId) && !rooms[adjRoomId].isVisited())
		{
			S.push(rooms[adjRoomId]);
			rooms[adjRoomId].visit();
		}
	}
	std::cout << std::endl;
	std::cout << "This is the path (in reverse): ";
	int prev = sTemp.top();
	std::cout << prev << " ";
	rooms[prev].setPath();
	sTemp.pop();
	while (!sTemp.empty())
	{
		int curr = sTemp.top();
		if (g.isNeighbor(prev, curr))
		{
			rooms[curr].setPath();
			std::cout << curr << " ";
			prev = curr;
		}
		sTemp.pop();

	}
	std::cout << std::endl;
}



void DisjointSets::printStack(std::stack<Room> s)
{
	std::cout << std::endl;
	std::cout << "Contents of the stack are: " << std::endl;
	while (!s.empty()) {
		Room r = s.top();
		std::cout << r.getRoom() << " ";
		s.pop();
	}
	std::cout << "Terminate here ";
	int i = 0;
	std::cin >> i;
	exit(0);
}
