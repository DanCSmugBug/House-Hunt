#pragma once
/*
* File Name: GameCharacter.h
* Author: Daniel Cole
* Date Created: 5/18/2019
* Date Last Updated: 6/24/2019
* Version: 1.0
* Description: The header file for the class GameCharacter, which
* defines the common functions and variables for the player in the 
* game.
* 
*/

#include <string>
#include <iostream>
#include "Location.h"
#include "inVerify.h"

using namespace std;

class GameCharacter
{
private:
	Location characterLoc;
	string characterName;
	int loot;
	bool itemSense;
	int listeningTalent;
	bool earlyBird;
	int lootLuck;
	inVerify playerInputCheck;

public:
	GameCharacter();
	Location getLoc();
	void setLoc(Location l);
	string getName();
	void setName(string n);
	int getLootAmount();
	void setLootAmount(int l);
	void increaseLootAmount(int l);
	void decreaseLootAmount(int l);
	bool getItemSense();
	int getListeningTalent();
	bool getEarlyBird();
	int getLootLuck();
	void characterCreation();
};