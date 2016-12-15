/*
* Name:			Jeffrey Qiu
* Class:		CIS 22C
* Date:			08/05/2016
* Instructor:	Professor Eftekhari
* File Name:	Room.cpp
*
* Description:	This is the implementation file for the Room class.
*
*/


#include "Room.h"



Room::Room()
{
	northDoor = false;
	eastDoor = false;
	southDoor = false;
	westDoor = false;
	visited = false;
	path = false;

	setRep = -1;
	roomNo = -1;
}



Room::Room(int roomNum, int rep) {
	northDoor = false;
	eastDoor = false;
	southDoor = false;
	westDoor = false;
	visited = false;
	path = false;

	setRep = rep;
	roomNo = roomNum;
}



bool Room::isVisited() {
	return visited;
}



void Room::visit() {
	visited = true;
}



void Room::unvisit() {
	visited = false;
}



bool Room::isPath() {
	return path;
}



void Room::setPath() {
	path = true;
}



void Room::resetPath() {
	path = false;
}



void Room::setRoom(int roomNum, int rep) {
	northDoor = false;
	eastDoor = false;
	southDoor = false;
	westDoor = false;
	visited = false;
	path = false;

	setRep = rep;
	roomNo = roomNum;
}



int Room::getRoom() {
	return roomNo;
}



int Room::getRoomRep() {
	return setRep;
}



void Room::setRoomRep(int repIdx) {
	setRep = repIdx;
}



bool Room::openDoor(char direction) {
	bool ret = true;
	switch (direction) {
	case 'n':
		northDoor = true;
		break;
	case 'e':
		eastDoor = true;
		break;
	case 's':
		southDoor = true;
		break;
	case 'w':
		westDoor = true;
		break;
	default:
		ret = false;
		break;
	}

	return ret;
}



bool Room::isDoorOpen(char direction) {
	bool ret;
	switch (direction) {
	case 'n':
		ret = northDoor;
		break;
	case 'e':
		ret = eastDoor;
		break;
	case 's':
		ret = southDoor;
		break;
	case 'w':
		ret = westDoor;
		break;
	default:
		ret = false;
		break;
	}

	return ret;
}
