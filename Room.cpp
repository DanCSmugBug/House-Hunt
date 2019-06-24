/*
* File Name: House.h
* Author: Daniel Cole
* Date Created: 6/8/2019
* Date Last Updated: 6/16/2019
* Version: 1.0
* Description: The implementation file for the class Room
*
*/

#include "Room.h"


void Room::operator= (const Room &right)
{

	if (decorList != NULL)
	{
		delete[] this->decorList;
	}
	this->numOfDecor = right.numOfDecor;
	this->decorList = new Furniture[numOfDecor];
	for (int i = 0; i < numOfDecor; i++)
	{
		this->decorList[i] = right.decorList[i];
	}
	this->roomLoc = right.roomLoc;
	this->decorList = right.decorList;
	this->roomName = right.roomName;
	this->stairs = right.stairs;
}

Room::Room()
{
	numOfDecor = 0;
	decorList = NULL;
	roomName = "Storage Room";
	stairs = false;

}

Room::Room(const Room &a)
{
	if (decorList != NULL)
	{
		delete[] this->decorList;
	}
	this->numOfDecor = a.numOfDecor;
	this->decorList = new Furniture[numOfDecor];
	for (int i = 0; i < numOfDecor; i++)
	{
		this->decorList[i] = a.decorList[i];
	}
	this->roomLoc = a.roomLoc;
	this->decorList = a.decorList;
	this->roomName = a.roomName;
	this->stairs = a.stairs;
}

Room::Room(Location l, int n, Furniture* d, string r, bool s)
{

	this->numOfDecor = n;
	this->roomLoc = l;
	this->decorList = d;
	this->roomName = r;
	this->stairs = s;
}

Room::~Room()
{
	if (decorList != NULL)
	{
		delete[] decorList;
	}
	decorList = NULL;
}

Location Room::getRoomLoc()
{
	return roomLoc;
}

void Room::setRoomLoc(Location l)
{
	this->roomLoc = l;
}

int Room::getNumOfDecor()
{
	return numOfDecor;
}

void Room::setNumOfDecor(int n)
{
	this->numOfDecor = n;
}

Furniture& Room::getDecorList()
{
	return *decorList;
}

void Room::setDecorList(Furniture &d)
{
	*decorList = d;
}

Furniture& Room::getDecor(int i)
{
	return decorList[i];
}

string Room::getRoomName()
{
	return roomName;
}

void Room::setRoomName(string s)
{
	this->roomName = s;
}

bool Room::getStairs()
{
	return stairs;
}

void Room::setStairs(bool s)
{
	this->stairs = s;
}

//This function will print to screen a simple description of the room and it's contents
void Room::roomDescription()
{
	cout << "This room is a " << roomName << ". ";
	cout << "Inside the room you see ";
	if (numOfDecor == 0)	// If there is no furniture then the description should reflect this
	{
		cout << "nothing of note";
		if (stairs == true)
		{
			" except a set of stairs leading to a different floor"; // If there are stairs it should
		}	// be noted in the description.
		cout << "." << endl;
	}
	else
	{
		int counter = 0;
		while (counter < numOfDecor)  // Cycling through all the furniture using a while loop
		{
			if (numOfDecor - counter > 1) // using an if statement to ensure that there is a
										  // proper use of commas and periods in the printing.
			{
				cout << "a " << decorList[counter].getName();
				if (numOfDecor > 2) // printing a comma only if there is 3 or more.
				{
					cout << ", ";
				}
			}
			else
			{
				if (numOfDecor > 1) // printing an and for the final item if there was more than one item
				{
					cout << "and ";
				}
				cout << "a " << decorList[counter].getName() << ". ";
			}
			counter++;
		}
	}

}

// This function generates all of a room's furniture's names and loot amounts
// The luck variable is used for players with good loot luck
void Room::generateFurniture(int luck)
{
	if (decorList != NULL)
	{
		delete[] decorList;
	}
	decorList = new Furniture[numOfDecor];
	int decorType, lootType;
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> dT(1, 32);	// random generator for furniture name
	uniform_int_distribution<int> someOrNone(1, 5);	//random generator for how much loot is inside the furniture
	uniform_int_distribution<int> goodFind(1, 20);
	uniform_int_distribution<int> greatFind(21, 50);

	for (int i = 0; i < numOfDecor; i++)
	{
		decorType = dT(generator);	// generating furniture name
		lootType = someOrNone(generator);	// generating what grade of valuables are inside

		// Creating the different names of furniture
		if (decorType < 3)
		{
			decorList[i].setName("wooden table");
		}
		else if (decorType == 4)
		{
			decorList[i].setName("wooden desk");
		}
		else if (decorType == 5)
		{
			decorList[i].setName("small book shelf");
		}
		else if (decorType == 6)
		{
			decorList[i].setName("bed");
		}
		else if (decorType == 7)
		{
			decorList[i].setName("dresser");
		}
		else if (decorType == 8)
		{
			decorList[i].setName("barrel");
		}
		else if (decorType == 9)
		{
			decorList[i].setName("crate");
		}
		else if (decorType == 10)
		{
			decorList[i].setName("small wooden chest");
			lootType = 4;	// Certain objects, like chests, should always contain goodies!!
		}
		else if (decorType == 11)
		{
			decorList[i].setName("large wooden chest");
			lootType = 5;
		}
		else if (decorType == 12)
		{
			decorList[i].setName("ornate jewelry box");
			lootType = 5;
		}
		else if (decorType == 13)
		{
			decorList[i].setName("large book shelf");
		}
		else if (decorType == 14)
		{
			decorList[i].setName("waste bin");
		}
		else if (decorType == 15)
		{
			decorList[i].setName("sack of rotten flour");
		}
		else if (decorType == 16)
		{
			decorList[i].setName("bloodstained box");
		}
		else if (decorType == 17)
		{
			decorList[i].setName("strange jack-in-the-box");
		}
		else if (decorType == 18)
		{
			decorList[i].setName("smiling marionnette");
		}
		else if (decorType == 19)
		{
			decorList[i].setName("crib");
		}
		else if (decorType == 20)
		{
			decorList[i].setName("bucket containing strange liquid");
		}
		else if (decorType == 21)
		{
			decorList[i].setName("wooden cabinet");
		}
		else if (decorType == 22)
		{
			decorList[i].setName("toy chest");
		}
		else if (decorType == 23)
		{
			decorList[i].setName("laundry basket");
		}
		else if (decorType == 24)
		{
			decorList[i].setName("night stand");
		}
		else if (decorType == 25)
		{
			decorList[i].setName("coffee table");
		}
		else if (decorType == 26)
		{
			decorList[i].setName("pile of old bones");
		}
		else if (decorType == 27)
		{
			decorList[i].setName("old briefcase");
		}
		else if (decorType == 28)
		{
			decorList[i].setName("grade school backpack with fresh bloodstains");
		}
		else if (decorType == 29)
		{
			decorList[i].setName("tool box");
		}
		else if (decorType == 30)
		{
			decorList[i].setName("pile of wallets");
			lootType = 5;
		}
		else
		{
			decorList[i].setName("pile of shredded clothes");
		}


		if (lootType < 3)	// 40% chance furniture won't contain anything
		{
			decorList[i].setLootAmount(0);
			if (lootType == 2)
			{	// If player has good loot luck, then they will get a little something 20% of time
				decorList[i].setLootAmount(luck / 2);
			}
		}
		else if (lootType < 5)	// 40% chance furniture will contain a modest amount of gold
		{
			decorList[i].setLootAmount(goodFind(generator) + luck);
		}
		else // 20% chance furniture will contain a large amount of gold.
		{
			decorList[i].setLootAmount(greatFind(generator) + (luck * 2));
		}
		decorList[i].setSearched(false);
	}
}

void Room::makeRoom(Location rL, bool stairs, int lootL)
{
	setRoomLoc(rL);
										   // Stairwell case
	if (stairs == true)
	{
		setRoomName("stair well");
		setNumOfDecor(0);
		setStairs(true);
	}

	// Hallway case
	else if (getRoomLoc().getY() == 5) // if the Y is 5 then it is a hallway.
	{
		setRoomName("hallway");
		setNumOfDecor(0);
	}

	// Cellar case
	else if (getRoomLoc().getZ() == 0) // if the Z is 0, then it must be in the cellar.
	{	// The cellar has a separate set of rooms that it could be.
		int rNum, fNum;
		random_device rd;		// Randomly selecting what the cellar room could be
		mt19937 generator(rd());
		uniform_int_distribution<int> num(1, 7);
		uniform_int_distribution<int> decorNum(1, 3);

		rNum = num(generator);
		fNum = decorNum(generator);

		if (rNum < 4)	// Cellar rooms are most commonly storage rooms
		{
			setRoomName("dusty storage room");
			setNumOfDecor(fNum);
			generateFurniture(lootL);
		}
		else if (rNum == 4)
		{
			setRoomName("workshop");
			setNumOfDecor(fNum);
			generateFurniture(lootL);

		}
		else if (rNum == 5)
		{
			setRoomName("boiler room");
			if (fNum > 1)	// Less furniture than normal in boiler room
			{
				fNum = fNum / 2;
			}
			setNumOfDecor(fNum);
			generateFurniture(lootL);
		}
		else if (rNum == 6)
		{
			setRoomName("vault");
			setNumOfDecor(fNum + 1); // more furniture than normal in vault
			generateFurniture(lootL);
		}
		else
		{
			setRoomName("ritual room");	//spooky ritual room has custom furniture
			setNumOfDecor(1);
			generateFurniture(lootL);
			getDecor(0).setName("bloody altar");
		}
	}

	// Case for both first and second floor
	else
	{
		int rNum, fNum;
		random_device rd;		// Randomly selecting what the cellar room could be
		mt19937 generator(rd());
		uniform_int_distribution<int> num(1, 18);
		uniform_int_distribution<int> decorNum(1, 4);

		rNum = num(generator);
		fNum = decorNum(generator);
		if (rNum < 3)
		{
			setRoomName("bedroom");
			setNumOfDecor(fNum);
			generateFurniture(lootL);
		}
		else if (rNum == 3)
		{
			setRoomName("master bedroom");
			setNumOfDecor(fNum + 1);
			generateFurniture(lootL);
		}
		else if (rNum == 4 || rNum == 5)
		{
			setRoomName("closet");
			setNumOfDecor(1);
			generateFurniture(lootL);
		}
		else if (rNum == 6 || rNum == 7)
		{
			setRoomName("bathroom");
			setNumOfDecor(2);
			generateFurniture(lootL);
			getDecor(0).setName("filthy bathtub");
			getDecor(1).setName("filthy toilet");
		}
		else if (rNum == 8)
		{
			setRoomName("dining room");
			setNumOfDecor(fNum);
			generateFurniture(lootL);
		}
		else if (rNum == 9)
		{
			setRoomName("kitchen");
			setNumOfDecor(fNum);
			generateFurniture(lootL);
		}
		else if (rNum == 10)
		{
			setRoomName("study");
			setNumOfDecor(fNum + 1);
			generateFurniture(lootL);
		}
		else if (rNum == 11)
		{
			setRoomName("wash room");
			if (fNum > 1)	// Less furniture than normal in wash room
			{
				fNum = fNum / 2;
			}
			setNumOfDecor(fNum);
			generateFurniture(lootL);
			getDecor(0).setName("old washing machine");
		}
		else if (rNum == 12)
		{
			setRoomName("music room");
			setNumOfDecor(fNum);
			generateFurniture(lootL);
			getDecor(0).setName("grand piano");
		}
		else if (rNum == 13)
		{
			setRoomName("smoking parlor");
			setNumOfDecor(fNum);
			generateFurniture(lootL);

		}
		else if (rNum == 14)
		{
			setRoomName("lounge");
			setNumOfDecor(fNum);
			generateFurniture(lootL);

		}
		else if (rNum == 15)
		{
			setRoomName("art gallery");
			setNumOfDecor(fNum);
			generateFurniture(lootL);

		}
		else if (rNum == 16)
		{
			setRoomName("sewing room");
			setNumOfDecor(fNum);
			generateFurniture(lootL);
		}
		else if (rNum == 17)
		{
			setRoomName("servant's quarters");
			setNumOfDecor(fNum);
			generateFurniture(lootL);

		}
		else
		{
			setRoomName("laboratory");
			setNumOfDecor(fNum);
			generateFurniture(lootL);
			getDecor(0).setName("corpse of mysterious creature");

		}

	}

}