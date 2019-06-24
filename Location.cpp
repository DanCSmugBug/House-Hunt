/*
* File Name: Location.cpp
* Author: Daniel Cole
* Date Created: 6/4/2019
* Date Last Updated: 6/15/2019
* Version: 1.0
* Description: The implementation file for the class Location.
* All of the functions and constructors deal solely with the 
* returning and setting of the integers x, y, and z
*
*/

#include "Location.h"

// Constructor for Location, sets everything to point 0
Location::Location()
{
	x = 0;
	y = 0;
	z = 0;
}

Location::Location(int nX, int nY, int nZ)
{
	x = nX;
	y = nY;
	z = nZ;
}

Location::Location(const Location &a)
{
	this->x = a.x;
	this->y = a.y;
	this->z = a.z;
}

void Location::operator= (const Location &right)
{
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;
}


void Location::setX(int i)
{
	x = i;
}

void Location::setY(int i)
{
	y = i;
}

void Location::setZ(int i)
{
	z = i;
}

void Location::setCoordinates(int nX, int nY, int nZ)
{
	this->x = nX;
	this->y = nY;
	this->z = nZ;
}

int Location::getX()
{
	return x;
}

int Location::getY()
{
	return y;
}

int Location::getZ()
{
	return z;
}

bool operator==(Location left, Location right)
{
	bool equal = false;
	if (left.getX() == right.getX() && left.getY() == right.getY() && left.getZ() == right.getZ())
	{
		equal = true;
	}
	return equal;
}
