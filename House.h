#pragma once
/*
* File Name: House.h
* Author: Daniel Cole
* Date Created: 6/8/2019
* Date Last Updated: 6/24/2019
* Version: 1.0
* Description: The header file for the class House, which
* defines the common functions and variables of the entire
* environment the game takes place in.
*
*/

#include "Location.h"
#include "Room.h"
#include "GameCharacter.h"
#include <random>
#include <iostream>
#include "inVerify.h"

using namespace std;

class House 
{
private:
	const int NUM_X = 10;	// creating the constants that make up the 3D grid array
	const int NUM_Y = 10;
	const int NUM_Z = 3;
	int numOfRooms;
	Location monsterLoc;
	Location objectiveLoc;
	Location entrance;
	Room* roomList;
	bool objectiveFound;
	bool gameComplete;
	
	/* Note about the 3d integer arrays that represent the "maps":
	 * It is assumed that the integer values are representative of what is at that position
	 * on the map. 0 represents nothing, 1 represents a room, 2 represents a stair well,
	 * 3 represents a monster location, 4 represents the objective location, 5 represents 
	 * the entrance hall, and adding 5 to any of the previous values (so values 6 through 10)
	 * represents the player on one of those respective locations.
	 */
	int*** houseMap;	// used for keeping track of the layout of rooms
	int*** playerMap;	// used to keep track of the rooms the player has visited to draw the map
	string objectiveName;
	int hour;
	int minute;
	GameCharacter player;
	inVerify houseInputCheck;
public:
	void operator=(const House &right);
	House();
	House(const House &a);
	House(int n, Location m, Location o, Location e, Room* r, bool oF, bool gC, int*** hM, int*** pM, string oN, int hr, int min, GameCharacter p);
	~House();
	int getNumOfRooms();
	void setNumOfRooms(int n);
	Location getMonLoc();
	void setMonLoc(Location m);
	Location getObjLoc();
	void setObjLoc(Location o);
	Location getEntrance();
	void setEntrance(Location e);
	Room* getRoomList();
	void setRoomList(Room &r);
	void setObjectiveName(string s);
	string getObjectiveName();
	bool getObjectiveFound();
	void setObjectiveFound(bool oF);
	bool getGameComplete();
	void setGameComplete(bool gC);
	void generateObjectiveName();
	void printTime();
	void setTime(int h, int m);
	int getHour();
	int getMin();
	GameCharacter getPlayer();
	void setPlayer(GameCharacter p);
	void makeHouse();
	void gameStart();
	bool gameRun();
	void gameEnd();
	void gameTurn();
	bool playerMovement(int roomIndex);
	void listen(int roomIndex);
	void objectiveSearch(int roomIndex);
	bool isKilled();
	void clockStart();
	void clockUpdate();
	bool clockEnd();
	void mapDraw();

};