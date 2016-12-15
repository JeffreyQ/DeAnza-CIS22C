/*
* Name:		Jeffrey Qiu
* Class:		CIS 22C
Date:		08/05/2016
* Instructor:	Professor Eftekhari
* File Name:	Room.h
*
* Description:	This is the header file for the Room class.
*
*/



#ifndef ROOM_H
#define ROOM_H



class Room
{

private:
	bool northDoor;		// north door
	bool eastDoor;		// east door
	bool southDoor;		// south door
	bool westDoor;		// west door
	bool visited;		// Indicate whether this room is visited by BFS/DFS algorithm
	bool path;			// Indicate whether this room is on the solution path
	int setRep;			// representative of the set in a disjoint sets
	int roomNo;

public:
	Room();
	Room(int roomNum, int rep);

	bool isVisited();	// get visited
	void visit();		// set visited
	void unvisit();		// unset visited
	bool isPath();		// get path
	void setPath();		// set path
	void resetPath();	// unset path
	void setRoom(int roomNum, int rep);		// initialize a new room
	int getRoom();		// return room number
	int getRoomRep();	// get representative node of the set this Room is a part of
	void setRoomRep(int repIdx);	// set the representative node of this room
	bool openDoor(char direction);	// switch case to open any N/E/S/W door
	bool isDoorOpen(char direction);// switch case to get status of any N/E/S/W door
};




#endif
