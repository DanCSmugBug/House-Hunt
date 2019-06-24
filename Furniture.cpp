/*
* File Name: Furniture.cpp
* Author: Daniel Cole
* Date Created: 6/8/2019
* Date Last Updated: 6/8/2019
* Version: 1.0
* Description: The implementation file for the class Furniture
*
*/

#include "Furniture.h"

void Furniture::operator= (const Furniture &right)
{
	this->amountOfLoot = right.amountOfLoot;
	this->searched = right.searched;
	this->name = right.name;
}

Furniture::Furniture()
{
	amountOfLoot = 0;
	searched = false;
	name = "table";
}

Furniture::~Furniture()
{

}

Furniture::Furniture(const Furniture &a)
{
	this->amountOfLoot = a.amountOfLoot;
	this->searched = a.searched;
	this->name = a.name;
}

Furniture::Furniture(int l, bool s, string n)
{
	this->amountOfLoot = l;
	this->searched = s;
	this->name = n;
}

int Furniture::getLootAmount()
{
	return amountOfLoot;
}

void Furniture::setLootAmount(int l)
{
	this->amountOfLoot = l;
}

bool Furniture::wasSearched()
{
	return searched;
}

void Furniture::setSearched(bool s)
{
	this->searched = s;
}

string Furniture::getName()
{
	return name;
}

void Furniture::setName(string n)
{
	this->name = n;
}