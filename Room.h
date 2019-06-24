#pragma once
/*
* File Name: House.h
* Author: Daniel Cole
* Date Created: 6/8/2019
* Date Last Updated: 6/16/2019
* Version: 1.0
* Description: The header file for the class Room, which
* defines the common functions and variables of each individual
* room in the house, including what is in them.
*
*/

#include "Location.h"
#include "Furniture.h"
#include <string>
#include <iostream>
#include <random>

using namespace std;

class Room
{
private:
	Location roomLoc;
	int numOfDecor;
	Furniture* decorList;
	string roomName;
	bool stairs;

public:
	void operator= (const Room &right);
	Room();
	Room(const Room &a);
	Room(Location l, int n, Furniture* d, string r, bool s);
	~Room();
	Location getRoomLoc();
	void setRoomLoc(Location l);
	int getNumOfDecor();
	void setNumOfDecor(int n);
	Furniture& getDecorList();
	void setDecorList(Furniture &d);
	Furniture& getDecor(int i);
	string getRoomName();
	void setRoomName(string s);
	bool getStairs();
	void setStairs(bool s);
	void roomDescription();
	void generateFurniture(int luck);
	void makeRoom(Location rL, bool stairs, int lootL);


};