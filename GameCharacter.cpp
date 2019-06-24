/*
* File Name: GameCharacter.cpp
* Author: Daniel Cole
* Date Created: 6/4/2019
* Date Last Updated: 6/24/2019
* Version: 1.0
* Description: The implementation file for the class GameCharacter.
*
*/

#include "GameCharacter.h"

GameCharacter::GameCharacter()
{
	characterName = "Nick";
	loot = 0;
	itemSense = false;
	listeningTalent = 1;
	earlyBird = false;
	lootLuck = 0;
}

Location GameCharacter::getLoc()
{
	return characterLoc;
}

void GameCharacter::setLoc(Location l)
{
	characterLoc = l;
}

string GameCharacter::getName()
{
	return characterName;
}

void GameCharacter::setName(string n)
{
	characterName = n;
}

int GameCharacter::getLootAmount()
{
	return loot;
}

void GameCharacter::setLootAmount(int l)
{
	loot = l;
}

void GameCharacter::increaseLootAmount(int l)
{
	loot = loot + l;
}

void GameCharacter::decreaseLootAmount(int l)
{
	loot = loot - l;
}

bool GameCharacter::getItemSense()
{
	return itemSense;
}

int GameCharacter::getListeningTalent()
{
	return listeningTalent;
}

bool GameCharacter::getEarlyBird()
{
	return earlyBird;
}

int GameCharacter::getLootLuck()
{
	return lootLuck;
}

// This function gives the player a chance to name their character and prints out
// all the different options for "talents", from which they can only choose one.
// In addition to the four core talents, there is a hidden fifth "talentless"
// feature that the player can activate if they input 0 when prompted to pick a talent.
void GameCharacter::characterCreation()
{
	int talentChoice = 6;
	bool nameDone = false; // used for name verification loop
	cout << endl;
	cout << "What is your name?" << endl;
	while (!nameDone)
	{
		try // Getting and validating the character name
		{
			characterName = playerInputCheck.getGoodStr();
			nameDone = true;
		}
		catch (string exceptionStr)
		{
			cout << exceptionStr;
		}
	}
	cout << endl;
	cout << characterName << ", throughout your childhood you've gained a useful talent. " << endl;
	cout << "What would this talent be? Enter the number of the talent. " << endl;
	cout << "1: You have a keen sense for misplaced objects, and you'll be able to know if the item you're searching" << endl;
	cout << "   for is in the room as soon as you enter it." << endl;
	cout << "2: You are very perceptive, able to hear things most can't. While in the house, you'll be able to use" << endl;
	cout << "   your keen hearing to detect the sleeping monster's location when you are much farther away from it." << endl;
	cout << "3: You are very proactive, able to get to doing things long before others have even started. With this" << endl;
	cout << "   ability, you will be able to begin searching the house an hour early." << endl;
	cout << "4: You have always been very fortunate when it comes to money, seemingly always finding a spectacular" << endl;
	cout << "   amount in the oddest of places. With this ability, you will gain more gold pieces when searching the" << endl;
	cout << "   houses various pieces of furniture." << endl;
	while (talentChoice < 0 || talentChoice > 4)
	{
		cout << "Please enter the number of the choice you want: ";
		try // Getting and validating the character name
		{
			talentChoice = playerInputCheck.getGoodInt();
		}
		catch (string exceptionStr)
		{
			cout << exceptionStr;
		}
	}
	if (talentChoice == 0)
	{
		cout << "You are talentless, without any of the gifts of those who would have a good chance of surviving this house." << endl;
		cout << "Best of luck, " << characterName << ", you unfortunate soul." << endl;
	}
	else if (talentChoice == 1)
	{
		cout << "Your ability to detect the item you search will no doubt aid you in your quest." << endl;
		cout << "Best of luck, " << characterName << endl;
		itemSense = true;
	}
	else if (talentChoice == 2)
	{
		cout << "Your ability to better hear the monster will no doubt aid you in your quest." << endl;
		cout << "Best of luck, " << characterName << endl;
		listeningTalent = 3;
	}
	else if (talentChoice == 3)
	{
		cout << "Your ability to get started early will no doubt aid you in your quest." << endl;
		cout << "Best of luck, " << characterName << endl;
		earlyBird = true;
	}
	else
	{
		cout << "Your good fortune will no doubt bestow great rewards, assuming you escape the house alive." << endl;
		cout << "Best of luck, " << characterName << endl;
		lootLuck = 5;
	}
	cout << endl;
}