#pragma once
/*
* File Name: Furniture.h
* Author: Daniel Cole
* Date Created: 6/8/2019
* Date Last Updated: 6/8/2019
* Version: 1.0
* Description: The header file for the class furniture, which
* defines the common functions and variables the furniture of
* the game features.
*
*/

#include <string>

using namespace std;

class Furniture
{
private:
	int amountOfLoot;
	bool searched;
	string name;
public:
	void operator= (const Furniture &right);
	Furniture();
	~Furniture();
	Furniture(const Furniture &a);
	Furniture(int l, bool s, string n);
	int getLootAmount();
	void setLootAmount(int l);
	bool wasSearched();
	void setSearched(bool s);
	string getName();
	void setName(string n);
};