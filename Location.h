#pragma once
/*
* File Name: Location.h
* Author: Daniel Cole
* Date Created: 5/18/2019
* Date Last Updated: 6/15/2019
* Version: 1.0
* Description: The header file for the class Location, which
* defines the functions and variables that deal with the location
* of all dynamic objects in the game. The location is determined
* by the x, y, and z integers.
*
*/

class Location {
private:
	int x;
	int y;
	int z;
public:
	Location();
	Location(int nX, int nY, int nZ);
	Location(const Location &a);
	void operator= (const Location &right);
	friend bool operator== (Location left, Location right);
	void setX(int i);
	void setY(int i);
	void setZ(int i);
	void setCoordinates(int x, int y, int z);
	int getX();
	int getY();
	int getZ();
};