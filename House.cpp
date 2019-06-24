/*
* File Name: House.h
* Author: Daniel Cole
* Date Created: 6/8/2019
* Date Last Updated: 6/24/2019
* Version: 1.0
* Description: The implementation file for the class House.
* The class House handles a signficant portion of the games
* functions, from keeping track of all of the Locations of 
* the rooms and player, to helping the player navigate the
* house itself
*
*/

#include "House.h"

void House::operator=(const House &right)
{
	this->numOfRooms = right.numOfRooms;
	this->monsterLoc = right.monsterLoc;
	this->objectiveLoc = right.objectiveLoc;
	this->entrance = right.entrance;
	delete[] this->roomList;
	this->roomList = new Room[numOfRooms];
	for (int i = 0; i < numOfRooms; i++)
	{
		this->roomList[i] = right.roomList[i];
	}
	// It is unnecessary to reallocate and delete the old maps, since the new
	// maps should be the exact same dimensions. Instead they will just be overwritten.

	this->objectiveFound = right.objectiveFound;
	this->gameComplete = right.gameComplete;
	for (int i = 0; i < NUM_X; i++)
	{								
		for (int j = 0; j < NUM_Y; j++)
		{
			for (int k = 0; k < NUM_Z; k++)
			{
				this->houseMap[i][j][k] = right.houseMap[i][j][k];
				this->playerMap[i][j][k] = right.playerMap[i][j][k];
			}
		}
	}

	this->objectiveName = right.objectiveName;
	this->hour = right.hour;
	this->minute = right.minute;
	this->player = right.player;
}

House::House()
{
	numOfRooms = 10;
	roomList = new Room[numOfRooms];
	objectiveFound = false;
	gameComplete = false;
	objectiveName = "mother's necklace";
	hour = 9;
	minute = 0;
	houseMap = new int**[NUM_X];
	playerMap = new int**[NUM_X];
	for (int i = 0; i < NUM_X; i++)
	{
		houseMap[i] = new int*[NUM_Y];
		playerMap[i] = new int*[NUM_Y];
		for (int j = 0; j < NUM_Y; j++)
		{
			houseMap[i][j] = new int[NUM_Z];
			playerMap[i][j] = new int[NUM_Z];
		}
	}

	for (int i = 0; i < NUM_X; i++)	// Creating blank maps
	{								
		for (int j = 0; j < NUM_Y; j++)
		{
			for (int k = 0; k < NUM_Z; k++)
			{
				houseMap[i][j][k] = 0;
				playerMap[i][j][k] = 0;
			}
		}
	}
}

House::House(const House &a)
{
	this->numOfRooms = a.numOfRooms;
	this->monsterLoc = a.monsterLoc;
	this->objectiveLoc = a.objectiveLoc;
	this->entrance = a.entrance;
	this->roomList = new Room[numOfRooms];
	for (int i = 0; i < numOfRooms; i++)
	{
		this->roomList[i] = a.roomList[i];
	}

	this->objectiveFound = a.objectiveFound;
	this->gameComplete = a.gameComplete;
	houseMap = new int**[NUM_X];	// Allocating memory for the map 3d arrays
	playerMap = new int**[NUM_X];	// The size of these arrays are constant
	for (int i = 0; i < NUM_X; i++)	// across all maps, so it is unnecessary
	{								// to make them any other size.
		houseMap[i] = new int*[NUM_Y];
		playerMap[i] = new int*[NUM_Y];
		for (int j = 0; j < NUM_Y; j++)
		{
			houseMap[i][j] = new int[NUM_Z];
			playerMap[i][j] = new int[NUM_Z];
		}
	}

	for (int i = 0; i < NUM_X; i++)	// copying contents of House a into the new
	{								// House
		for (int j = 0; j < NUM_Y; j++)
		{
			for (int k = 0; k < NUM_Z; k++)
			{
				this->houseMap[i][j][k] = a.houseMap[i][j][k];
				this->playerMap[i][j][k] = a.playerMap[i][j][k];
			}
		}
	}

	this->objectiveName = a.objectiveName;
	this->hour = a.hour;
	this->minute = a.minute;
	this->player = a.player;
}

House::House(int n, Location m, Location o, Location e, Room* r, bool oF, bool gC, int*** hM, int*** pM, string oN, int hr, int min, GameCharacter p)
{
	this->numOfRooms = n;
	this->monsterLoc = m;
	this->objectiveLoc = o;
	this->entrance = e;
	this->roomList = r;
	this->objectiveFound = oF;
	this->gameComplete = gC;
	this->houseMap = hM;
	this->playerMap = pM;
	this->objectiveName = oN;
	this->hour = hr;
	this->minute = min;
	this->player = p;
}

House::~House()
{
	delete[] roomList;
	roomList = NULL;
	
	for (int i = 0; i < NUM_X; i++)	// cycling through and deleting each part of the the 3D integer arrays
	{
		for (int j = 0; j < NUM_Y; j++)
		{
			delete[] houseMap[i][j];
			delete[] playerMap[i][j];
		}
		delete[] houseMap[i];
		delete[] playerMap[i];
	}
	delete[] houseMap;
	delete[] playerMap;
	houseMap = NULL;
	playerMap = NULL;

}

int House::getNumOfRooms()
{
	return numOfRooms;
}

void House::setNumOfRooms(int n)
{
	this->numOfRooms = n;
}

Location House::getMonLoc()
{
	return monsterLoc;
}

void House::setMonLoc(Location m)
{
	this->monsterLoc = m;
}

Location House::getObjLoc()
{
	return objectiveLoc;
}

void House::setObjLoc(Location o)
{
	this->objectiveLoc = o;
}

Location House::getEntrance()
{
	return entrance;
}

void House::setEntrance(Location e)
{
	this->entrance = e;
}

Room* House::getRoomList()
{
	return roomList;
}

void House::setRoomList(Room &r)
{
	*this->roomList = r;
}

void House::setObjectiveName(string s)
{
	this->objectiveName = s;
}

string House::getObjectiveName()
{
	return objectiveName;
}

bool House::getObjectiveFound()
{
	return objectiveFound;
}

void House::setObjectiveFound(bool oF)
{
	this->objectiveFound = oF;
}

bool House::getGameComplete()
{
	return gameComplete;
}

void House::setGameComplete(bool gC)
{
	this->gameComplete = gC;
}

void House::generateObjectiveName()
{
	int oName;	// Randomly generating an integer that will be used to determine the object the player is searching for
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> num(1, 10);
	oName = num(generator);

	if (oName == 1)
	{
		objectiveName = "mother's necklace";
	}
	else if (oName == 2)
	{
		objectiveName = "grandfather's watch";
	}
	else if (oName == 3)
	{
		objectiveName = "last photo of your father";
	}
	else if (oName == 4)
	{
		objectiveName = "love letter from your crush";
	}
	else if (oName == 5)
	{
		objectiveName = "pet hamster";
	}
	else if (oName == 6)
	{
		objectiveName = "grandmother's mysterious key";
	}
	else if (oName == 7)
	{
		objectiveName = "brother's favorite toy car";
	}
	else if (oName == 8)
	{
		objectiveName = "bracelet that sister made you";
	}
	else if (oName == 9)
	{
		objectiveName = "ultra rare trading card";
	}
	else
	{
		objectiveName = "amulet containing a fragment of your soul";
	}
}

void House::printTime()
{
	cout << "The current time is " << hour << ":";
	if (minute < 10)
	{
		cout << "0";
	}
	cout << minute << " PM." << endl;
}

void House::setTime(int h, int m)
{
	this->hour = h;
	this->minute = m;
}

int House::getHour()
{
	return hour;
}

int House::getMin()
{
	return minute;
}

GameCharacter House::getPlayer()
{
	return player;
}

void House::setPlayer(GameCharacter p)
{
	this->player = p;
}

/* Function: makeHouse
 * Description: This function is one of the most complex functions in the game, dynamically
 * creating an array of connected rooms that is able to be navigated without issue. The
 * function is optimized such that it can handle a variable integer size of rooms in the house between 5 and 50.
 * (This number is arbitrary, in theory it can handle more, but doing so would increase the size
 * of the house to an obscene degree, and would also create issues with the generation method)
 * This function also places the entrance, monster location, and objective location.
 * The dimensions of the house cannot extend past the coordinates declared as constants in the class definition
 */


void House::makeHouse()
{
	delete[] roomList;
	roomList = new Room[numOfRooms];
	int roomCounter = 0;	// used to track place in roomList

	int firstSize;		// In this section, I'm determining the number of rooms in each floor of the
	int secondSize;		// house. If there are 10 or less rooms, then there will only be the first floor.
	int cellarSize;		// If there is more than 20 floors, then there will be both a cellar and a second floor.
	int firstCounter = 0;	// trackers for the number of rooms on each floor
	int secondCounter = 0;
	int cellarCounter = 0;

	bool monsterPlaced = false;	// flags to make sure only one of the monster and objective are placed.
	bool objectivePlaced = false;
	bool canPlaceObj = true; // This flag is to ensure the objective doesn't get locked behind the monster
	
	if (numOfRooms > 12 && numOfRooms <= 24)
	{
		firstSize = (numOfRooms / 2) + 2;
		secondSize = numOfRooms - firstSize;
		cellarSize = 0;
	}
	else if (numOfRooms > 24)
	{
		firstSize = numOfRooms / 2;
		secondSize = numOfRooms / 3;
		cellarSize = numOfRooms - firstSize - secondSize;
	}
	else
	{
		firstSize = numOfRooms;
		cellarSize = 0;
		secondSize = 0;
	}

	Location currentRoom;	// Creating a Location variable to set the Location of whatever Room
	currentRoom.setCoordinates(0, 5, 1);  // is currently being worked on.
	// The y is set to 5 to give a little space for the later rooms to expand downward from the entrance hall.

	roomList[0].setRoomName("Entrance Hall");  //Creating the Entrance Hall, the starting room.
	roomList[0].setRoomLoc(currentRoom);
	entrance = currentRoom;
	player.setLoc(currentRoom); //placing Player into the Entrance Hall.
	firstCounter++;
	roomCounter++;
	houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 10;	// updating both maps
	playerMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 10;  // This will be the only update
	// for playerMap until the game begins and the player begins navigating the house.

	// Begin by generating first floor hallway
	int counter = 1;
	while (counter < firstSize / 4)
	{
		currentRoom.setX(currentRoom.getX() + 1); //stretch the hallway across the X axis
		roomList[roomCounter].makeRoom(currentRoom, false, player.getLootLuck());
		counter++;
		roomCounter++;
		firstCounter++;
		houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 1;
	}

	// Generate stair well for both first and second floor if there is one.
	if (secondSize > 0)
	{
		currentRoom.setX(currentRoom.getX() + 1);
		roomList[roomCounter].makeRoom(currentRoom, true, player.getLootLuck());
		roomCounter++;
		firstCounter++;
		houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 2;

		currentRoom.setZ(currentRoom.getZ() + 1);
		roomList[roomCounter].makeRoom(currentRoom, true, player.getLootLuck());
		roomCounter++;
		secondCounter++;
		houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 2;
		// Generate stair well for cellar if it exists
		if (cellarSize > 0)
		{
			currentRoom.setZ(currentRoom.getZ() - 2);
			roomList[roomCounter].makeRoom(currentRoom, true, player.getLootLuck());
			roomCounter++;
			secondCounter++;
			houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 2;
		}
	}

	// reverting back to entrance hall to begin generation of first floor
	currentRoom = roomList[0].getRoomLoc();


	
	// Generating rooms until the first floor is filled  out
	while (firstCounter < firstSize)
	{


		bool directionUp = true; // flag for if the branch of rooms is being added above or below the hallway
		bool fullAdd = false;    // flag for if a large branch should be added at the end of the hall or not

								 // checking to see if it is the last section hallway, if so then these branch sizes will be larger than normal.
		if (houseMap[currentRoom.getX() + 1][currentRoom.getY()][currentRoom.getZ()] == 0 && firstCounter + 2 < firstSize)
		{
			fullAdd = true;
		}

		// This loop helps produce a branch on both sides of the hallway, up and down
		for (int i = 0; i < 2; i ++)
		{

			int branchSize;	// Generating how many rooms should branch off of a single path of the hallway
			random_device rd;
			mt19937 generator(rd());
			uniform_int_distribution<int> num(1, 4);
			branchSize = num(generator);

			if (fullAdd) // making branch sizes larger than normal in emergency case
			{
				branchSize = 4;
			}

			// This loop goes through and inserts each room until the branch is complete or the first floor is filled
			for (int b = 0; b < branchSize && firstCounter < firstSize; b++)
			{
				if (directionUp)
				{
					currentRoom.setY(currentRoom.getY() + 1);
				}
				else
				{
					currentRoom.setY(currentRoom.getY() - 1);
				}

				roomList[roomCounter].makeRoom(currentRoom, false, player.getLootLuck());
				houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 1;
				roomCounter++;
				firstCounter++;

				if (!objectivePlaced && canPlaceObj)
				{
					int oNum;   // Generating a number to see if the objective gets placed.
								// It becomes more likely to be placed the more rooms exist.
					uniform_int_distribution<int> num(roomCounter, numOfRooms);
					oNum = num(generator);
					if (oNum == numOfRooms)
					{
						objectiveLoc = currentRoom;
						objectivePlaced = true;
						houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 4;
					}
				}

				else if (!monsterPlaced && roomCounter > numOfRooms / 2)
				{
					// this secondary if statement ensures that the last rooms won't be placed behind the monster
					// (thus locking the objective from being placed)
					if (objectivePlaced || numOfRooms - roomCounter > branchSize)
					{
						int mNum;   // Generating a number to see if the monster gets placed.
									// It becomes more likely to be placed the more rooms exist.
						uniform_int_distribution<int> num(roomCounter, numOfRooms);
						mNum = num(generator);
						if (mNum == numOfRooms)
						{
							monsterLoc = currentRoom;
							monsterPlaced = true;
							canPlaceObj = false;	// ensures that the ojective won't get pinned in room behind monster
							houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 3;
						}
					}

				}
				// Based on this code, it is conceivable that the monster doesn't get placed if it comes down to the
				// last room being made and both the monster and objective still haven't been placed. This is
				// acceptable, as if it is the case the game is still playable and the threat of the monster
				// "arriving from the woods" still exists.
			}
			currentRoom.setY(5); // Returning to hall
			directionUp = false; // trigger the adding room to lower section of hall
		}

		canPlaceObj = true;
		currentRoom.setX(currentRoom.getX() + 1); // iterating to next section of hallway/or the stair well

	}
	


	// Second Floor Generation
	if (secondSize > 0)
	{
		// Generating hallway for second floor
		Location secondIndex;
		currentRoom = roomList[0].getRoomLoc(); // starting from first floor
		counter = 0;							// using counter to iterate through
		while (!roomList[counter].getStairs())  // moving through the hallway to the stairs
		{
			counter++;
		}
		currentRoom = roomList[counter].getRoomLoc(); // setting currentRoom to 1st floor stairs
		currentRoom.setZ(2);
		secondIndex = currentRoom;	// setting the second floor stair well as the index for the floor

		counter = 0;		// again using counter to iterate through second floor and make hallway
		while (counter < secondSize / 5)	// this hallway is shorter, but the branches will be larger
		{
			currentRoom.setX(currentRoom.getX() - 1); //stretch the hallway backwards across the x axis
			roomList[roomCounter].makeRoom(currentRoom, false, player.getLootLuck());
			counter++;
			roomCounter++;
			secondCounter++;
			houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 1;
		}

		currentRoom = secondIndex;	// Reverting to second floor stair well to begin generation of rooms
		

		// Effectively doing the same generation method as with the first floor, just with a few different tweaks
		// to some of the numbers and values. Much of the variables that share the same names share the same purpose
		// comments will show differences in code
		while (secondCounter < secondSize)
		{


			bool directionUp = true;
			bool fullAdd = false;

			// In this case, it's similar as the evaluation in the first floor generating method, except it goes from right to left
			// because it's moving from left to right, it's important to ensure that if it is a hallway at x position 0
			// that it is the last one, else it might go f
			if (currentRoom.getX() == 0)
			{
				fullAdd = true;
			}
			else if (houseMap[currentRoom.getX() - 1][currentRoom.getY()][currentRoom.getZ()] == 0 && secondCounter + 2 < secondSize)
			{
				fullAdd = true;
			}

			for (int i = 0; i < 2; i++)
			{

				int branchSize;	// Generating how many rooms should branch off of a single path of the hallway
				random_device rd;	// In this case, the proportion of the floor size to rooms in a branch is 
				mt19937 generator(rd()); // bigger than on the first floor
				uniform_int_distribution<int> num(2, 4);
				branchSize = num(generator);

				if (fullAdd)
				{
					branchSize = 4;
				}

				for (int b = 0; b < branchSize && secondCounter < secondSize; b++)
				{
					if (directionUp)
					{
						currentRoom.setY(currentRoom.getY() + 1);
					}
					else
					{
						currentRoom.setY(currentRoom.getY() - 1);
					}

					roomList[roomCounter].makeRoom(currentRoom, false, player.getLootLuck());
					houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 1;
					roomCounter++;
					secondCounter++;

					if (!objectivePlaced && canPlaceObj)
					{
						int oNum;
						uniform_int_distribution<int> num(roomCounter, numOfRooms);
						oNum = num(generator);
						if (oNum == numOfRooms)
						{
							objectiveLoc = currentRoom;
							objectivePlaced = true;
							houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 4;
						}
					}
					else if (!monsterPlaced && roomCounter > numOfRooms / 2)
					{
						int mNum; 
						uniform_int_distribution<int> num(roomCounter, numOfRooms);
						mNum = num(generator);
						if (mNum == numOfRooms)
						{
							monsterLoc = currentRoom;
							monsterPlaced = true;
							canPlaceObj = false;
							houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 3;
						}
					}
				}
				currentRoom.setY(5); // Returning to hall
				directionUp = false;
			}
			canPlaceObj = true;
			currentRoom.setX(currentRoom.getX() - 1);

		}
	}

	if (cellarSize > 0)
	{
		// Generating hallway for cellar
		Location cellarIndex;
		// Going through the first floor to get to the cellar stair well much like with the
		// second floor generation
		currentRoom = roomList[0].getRoomLoc();
		counter = 0;
		while (!roomList[counter].getStairs())  // moving through the hallway to the stairs
		{
			counter++;
		}
		currentRoom = roomList[counter].getRoomLoc(); // setting currentRoom to 1st floor stairs
		currentRoom.setZ(0);		
		cellarIndex = currentRoom;	// setting the cellar stair well as the index for the floor

		counter = 0;		// using counter to iterate through cellar and make the hallway
		while (counter < cellarSize / 6)	// this hallway is the shortest, but the branches will be the largest
		{
			currentRoom.setX(currentRoom.getX() - 1); //stretch the hallway backwards across the x axis
			roomList[roomCounter].makeRoom(currentRoom, false, player.getLootLuck());
			counter++;
			roomCounter++;
			cellarCounter++;
			houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 1;
		}

		currentRoom = cellarIndex;	// Reverting to cellar stair well to begin generation of rooms

		// Again this cellar generation is much like the second floor generation, just with a couple of tweaks
		while (cellarCounter < cellarSize)
		{


			bool directionUp = true;
			bool fullAdd = false;

			// It's unlikely (pretty much impossible) that the cellar hall will ever stretch to 0 x, but just in case I left this
			// catch there
			if (currentRoom.getX() == 0)
			{
				fullAdd = true;
			}
			else if (houseMap[currentRoom.getX() - 1][currentRoom.getY()][currentRoom.getZ()] == 0 && cellarCounter + 2 < cellarSize)
			{
				fullAdd = true;
			}

			for (int i = 0; i < 2; i++)
			{

				int branchSize;
				random_device rd;
				mt19937 generator(rd());
				uniform_int_distribution<int> num(3, 4);
				branchSize = num(generator);

				if (fullAdd)
				{
					branchSize = 4;
				}

				for (int b = 0; b < branchSize && cellarCounter < cellarSize; b++)
				{
					if (directionUp)
					{
						currentRoom.setY(currentRoom.getY() + 1);
					}
					else
					{
						currentRoom.setY(currentRoom.getY() - 1);
					}

					roomList[roomCounter].makeRoom(currentRoom, false, player.getLootLuck());
					houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 1;
					roomCounter++;
					cellarCounter++;

					if (!objectivePlaced && canPlaceObj)
					{
						int oNum;
						uniform_int_distribution<int> num(roomCounter, numOfRooms);
						oNum = num(generator);
						if (oNum == numOfRooms)
						{
							objectiveLoc = currentRoom;
							objectivePlaced = true;
							houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 4;
						}
					}
					else if (!monsterPlaced && roomCounter > numOfRooms / 2)
					{
						int mNum;
						uniform_int_distribution<int> num(roomCounter, numOfRooms);
						mNum = num(generator);
						if (mNum == numOfRooms)
						{
							monsterLoc = currentRoom;
							monsterPlaced = true;
							canPlaceObj = false;
							houseMap[currentRoom.getX()][currentRoom.getY()][currentRoom.getZ()] = 3;
						}
					}
				}
				currentRoom.setY(5); // Returning to hall
				directionUp = false;
			}
			canPlaceObj = true;
			currentRoom.setX(currentRoom.getX() - 1);

		}
	}
}


/* This function handles all game initiation functions, such as running the character creation process,
 * displaying intro text, giving game information, generating the house, and so on.
 */
void House::gameStart()
{

	// creating relevant player and objective information
	player.characterCreation();
	generateObjectiveName();

	int playerChoice = 0;
	cout << player.getName() << ", you're looking for your " << objectiveName << " which you saw a large" << endl;
	cout << "shadowy figure take into the strange house at the end of the old forest road." << endl;
	cout << "You're trying to remember... how large was that?" << endl;
	cout << "1: Fairly small" << endl;
	cout << "2: Moderately large" << endl;
	cout << "3: Monsterously giant" << endl;
	cout << "4: I can't remember" << endl;

	while (playerChoice < 1 || playerChoice > 4)
	{
		cout << "Enter the number of your choice. " << endl;
		try  // Getting input and validating it
		{
			playerChoice = houseInputCheck.getGoodInt();
		}
		catch (string exceptionStr)
		{
			cout << exceptionStr;
		}
	}

	// integers used for generating the number of rooms
	int rNum, sizeMin, sizeMax;
	// Starting clock now for changes to go into effect later
	clockStart();
	if (playerChoice == 1)
	{
		sizeMin = 8;
		sizeMax = 16;
	}
	else if (playerChoice == 2)
	{
		sizeMin = 18;
		sizeMax = 30;
		hour = hour - 1;	// Arrive an hour earlier if you are exploring a moderately large house
	}
	else if (playerChoice == 3)
	{
		sizeMin = 31;
		sizeMax = 50;
		hour = hour - 3;	// arrive three hours earlier if you are exploring a giant house
	}
	else
	{
		sizeMin = 8;
		sizeMax = 50;
	}

	// generating the number of rooms in the house
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> num(sizeMin, sizeMax);

	rNum = num(generator);
	numOfRooms = rNum;

	// Go through and wipe the maps of house. This is necessary for all subsequent playthroughs
	for (int i = 0; i < NUM_X; i++)
	{
		for (int j = 0; j < NUM_Y; j++)
		{
			for (int k = 0; k < NUM_Z; k++)
			{
				this->houseMap[i][j][k] = 0;
				this->playerMap[i][j][k] = 0;
			}
		}
	}

	// generating house and starting the clock
	makeHouse();
	cout << "You arrive at the dark house at " << getHour() << ":" << getMin() << "0 PM." << endl;
	cout << "A cold wind blows across back, chilling you to the bone, as you step up the creaky" << endl;
	cout << "wooden porch steps. Your hand touches the weathered brass door knob, and you pull it open.." << endl;
	cout << "                                  ...and the house welcomes you..." << endl;
}

// This function consists of the whole game, starting things off with gameStart() and repeating the gameTurn()
// function until the gameComplete flag is set to true. Afterwards, it runs the gameEnd() function
bool House::gameRun()
{
	bool done = false;
	cout << "                                House Hunt                                               " << endl;
	cout << "                                                                                         " << endl;
	cout << "                                _______||__                                              " << endl;
	cout << "                               /           \\                                             " << endl;
	cout << "                              /             \\                                            " << endl;
	cout << "                              |  []     []  |                                            " << endl;
	cout << "                              |     ___     |                                            " << endl;
	cout << "                              |     | |     |                                            " << endl;
	cout << "                                    / \\                                                  " << endl;
	cout << "                                   /   \\                                                 " << endl;
	cout << "                                  /     \\                                                " << endl;
	cout << "                                                                                         " << endl;

	int playerSelection = 0;
	while (playerSelection < 1 || playerSelection > 3)
	{
		cout << "Welcome to House Hunt..." << endl;
		cout << "What would you like to do...?" << endl;
		cout << "1: Enter the house..." << endl;
		cout << "2: Read the basic game rules" << endl;
		cout << "3: Exit" << endl;
		try // Getting input and validating it
		{
			playerSelection = houseInputCheck.getGoodInt();
		}
		catch (string exceptionStr)
		{
			cout << exceptionStr;
		}
	}
	if (playerSelection == 1)
	{
		gameStart();
		while (!gameComplete)
		{
			gameTurn();
		}
		gameEnd();
	}
	else if (playerSelection == 2)
	{
		cout << "House Hunt is a time based exploration game in which you must explore a randomly generated " << endl;
		cout << "house that a abnormal and dangerous creature lives. You are looking for a lost precious item" << endl;
		cout << "That you know is somewhere in the house." << endl;
		cout << "The Objective: Find your precious item, get as much gold as possible, and escape the house alive" << endl;
		cout << "before time runs out. Don't run into the monster." << endl;
		cout << "You can spend your turns moving from room to room, searching the furniture in the house for loot," << endl;
		cout << "searching rooms for your amulet, or listening to see if you can figure out where the monster is." << endl;
		cout << "The monster is asleep, so he'll only wake up if you enter the same room as it. Be careful!" << endl;
		cout << "When the clock strikes midnight, the monster awakens, and if you are still in his domain, you're as" << endl;
		cout << "good as dead! Get out before then." << endl;
		cout << endl;
	}
	else
	{
		cout << "Very well... come back soon... the house will wait..." << endl;
		done = true;
	}
	return done;
}

// This function handles a lot of the final tasks, printing the results, and so on.
void House::gameEnd()
{
	//evaluating if it is a game winning scenario
	if (objectiveFound && !isKilled() && !clockEnd())
	{
		cout << "You quickly run back down the narrow dirt road through the darkened woods, safely having" << endl;
		cout << "survived the house and it's horrid monster. Clutched in your hands is your " << objectiveName << endl;
		cout << "and in your back pack is your loot from that wretched house." << endl;
		if (player.getLootAmount() >= 250)
		{
			cout << "You walk away with a grand total of " << player.getLootAmount() << " gold pieces! You're rich!" << endl;
		}
		else if (player.getLootAmount() < 250 && player.getLootAmount() >= 100)
		{
			cout << "You managed to collect a total of " << player.getLootAmount() << " gold pieces. You won't have" << endl;
			cout << "any money worries for a long time!" << endl;
		}
		else if (player.getLootAmount() < 100 && player.getLootAmount() > 0)
		{
			cout << "You found a total of " << player.getLootAmount() << " gold pieces. Nice job!" << endl;
		}
		else
		{
			cout << "You didn't get any gold, but you got what you were looking for and that's all that matters." << endl;
			cout << "... besides... best not to take a single penny from that cursed house..." << endl;
		}
	}
	else if (!objectiveFound && !isKilled() && !clockEnd())
	{
		cout << "You run down the narrow dirt road that led you to that house. Once you reach the paved road that the trail" << endl;
		cout << "to, you stop and catch your breath, leaning against a dead birch tree. You couldn't imagine a terror greater" << endl;
		cout << "than being in that house. Cars with their bright headlights illuminating you and the tree line as they pass you" << endl;
		cout << "and you catch yourself staring back down the dark forest road you just ran from. A gust of cold wind " << endl;
		cout << "howls through the trees, pushing out dead leaves against your face. Maybe you will go back to get your " << endl;
		cout << objectiveName << " another day..." << endl;
		cout << "       ... or maybe you won't..." << endl;
	}
	else if (clockEnd())
	{
		cout << "From somewhere within the house you hear a grandfather clock's deep ringing pierce through the silence." << endl;
		cout << "You ran out of time. You begin to make your way to the front entrance, but before you make it, a tall, " << endl;
		cout << "spindly grey figure emerges from a doorframe ahead of you. It's piercing red eyes gazing down at you, " << endl;
		cout << "it's claws with dried blood twitching eagerly. It steps forward..." << endl;
		cout << endl;
		cout << endl;
		cout << "You didn't want to die like this." << endl;
	}
	else
	{
		cout << "Opening the door, you enter the room. As you enter, you stumble over something... A large grey body on the ground." << endl;
		cout << "Your eyes slowly drag across the form as you make out inhuman legs... torso... claws... and a ghastly face with " << endl;
		cout << "red eyes, staring deeply into yours. It stands up, and you fall on your back and let out a scream. " << endl;
		cout << "Your final thought being that you wonder if anyone heard you... " << endl;
	}
	cout << endl;
	cout << "Press any key to continue..." << endl;
	cin.get();
	gameComplete = false;
	objectiveFound = false;
}

// This function is standard function called while the game runs, printing the 
// relevant information and prompting the player as need be.
void House::gameTurn()
{
	// Drawing player map
	mapDraw();
	//testEnvironment();
	bool roomFound = false;
	int counter = 0;
	int index = 0;

	// Find the correct room
	while (!roomFound)
	{
		if (roomList[counter].getRoomLoc() == player.getLoc())
		{
			roomFound = true;
			index = counter;
		}
		counter++;
	}
	// Describe Room
	roomList[index].roomDescription();

	// Activates if player with itemSense talent enters room with the objective in it
	if (player.getItemSense() && roomList[index].getRoomLoc() == objectiveLoc && !objectiveFound)
	{
		cout << "As you enter this room, you feel it. You are sure that your " << objectiveName << " is here!" << endl;
	}

	// Preparations for prompt phase
	bool promptOver = false;	// flag to indicate when prompt phase ends
	int options;
	int playerChoice = 0;
	options = roomList[index].getNumOfDecor() + 3;

	// This prompt phase ends if time is out or the player moves to a different room.
	while (!promptOver)
	{
		cout << endl;
		// Printing the time
		printTime();
		// Printing of possible options phase
		cout << player.getName() << ", what would you like to do?" << endl;
		for (int i = 1; i <= options; i++)
		{

			if (i <= roomList[index].getNumOfDecor())
			{
				cout << i << " Search the " << roomList[index].getDecor(i - 1).getName() << ".";
				
			}
			else if (i == options - 2)
			{
				cout << i << " Listen carefully for a bit. ";
			}
			else if (i == options - 1)
			{
				cout << i << " Search the room for your " << objectiveName;
			}
			else
			{
				cout << i << " Move to a different room. ";
			}
			cout << endl;
		}
		cout << endl;

		bool decisionPhase = true;	// used to determine when the player decision phase is over
		// Player Decision phase
		while (decisionPhase)
		{
			while (playerChoice < 1 || playerChoice > options)
			{
				cout << "Please type the number of the option you want to select and press enter." << endl;
				try
				{
					playerChoice = houseInputCheck.getGoodInt();
				}
				catch (string exceptionStr)
				{
					cout << exceptionStr;
				}
			}
			// Searching something
			// I decided to not make a separate function for this since if an object is searched that's
			// already been searched, time isn't wasted. Maybe I'll go back and change the implementation
			// of this later, but the current implementation is a quick and easy one.
			if (playerChoice <= roomList[index].getNumOfDecor())
			{
				if (roomList[index].getDecor(playerChoice - 1).wasSearched())
				{	// This choice does not trigger the end of the decision phase and does not use any time.
					cout << "Actually, that seems to already be searched. " << endl;
				}
				else
				{
					cout << "You spend some time searching it... " << endl;
					if (roomList[index].getDecor(playerChoice - 1).getLootAmount() == 0)
					{
						cout << "You don't find anything of value." << endl;
					}
					else
					{
						cout << "You find a total of " << roomList[index].getDecor(playerChoice - 1).getLootAmount();
						cout << " gold pieces. ";
						if (roomList[index].getDecor(playerChoice - 1).getLootAmount() > 25)
						{	// In case of a large amount gold obtained, print a more positive message
							cout << "What a boon! ";
						}
						cout << "You pocket it." << endl;
					}
					roomList[index].getDecor(playerChoice - 1).setSearched(true);
					player.increaseLootAmount(roomList[index].getDecor(playerChoice - 1).getLootAmount());
					decisionPhase = false;	// Exiting decision phase loop
					clockUpdate();	// Updating time
					promptOver = clockEnd();	// evaluating if game is over yet
				}
			}
			// Listening
			else if (playerChoice == options - 2)
			{
				listen(index);
				decisionPhase = false;
				clockUpdate();
				promptOver = clockEnd();
			}
			// Looking for your objective
			else if (playerChoice == options - 1)
			{
				objectiveSearch(index);
				decisionPhase = false;
				clockUpdate();
				promptOver = clockEnd();
			}
			// Moving
			else
			{
				decisionPhase = playerMovement(index);
				// If the game isn't over because the players haven't left the house and if 
				// the decisionPhase is over because the player moved then the time will move forward.
				if (!gameComplete && !decisionPhase)
				{
					clockUpdate();
					promptOver = clockEnd();
				}
				if (!decisionPhase)
				{
					promptOver = true;
				}
			}
			// resetting player choice to 0 to  get ready for a new decisionPhase w 
			playerChoice = 0;
		}
	}
	if (isKilled())
	{
		gameComplete = isKilled();
	}
}

// This function prompts the player with where they can move, and then allows them to move to a new
// room or stay where they are. A boolean is returned based on if they decided to act and move somewhere
// else or stay where they currently are. This bool will be used to determine if the prompt and decision
// phase are over in gameTurn function.
bool House::playerMovement(int roomIndex)
{
	// These integers will be used to track the current room (r)
	int rX, rY, rZ;
	int counter = 1; // keeps track of the numbers of each option
	bool stairwell = roomList[roomIndex].getStairs();
	bool playerStay = false;
	// these ints represent if each direction is a movement option, and if so, what option it is.
	int north = -1, south = -1, east = -1, west = -1, up = -1, down = -1, frontDoor = -1;
	rX = roomList[roomIndex].getRoomLoc().getX();
	rY = roomList[roomIndex].getRoomLoc().getY();
	rZ = roomList[roomIndex].getRoomLoc().getZ();
	// Each if statement evaluates if there is something, and in case of vertical movement,
	// if you are in a stairwell
	if (rZ + 1 < NUM_Z && houseMap[rX][rY][rZ + 1] > 0 && stairwell) // up evaulation
	{
		cout << counter << ": You can go up the stairs to the next floor." << endl;
		up = counter;
		counter++;
	}
	if (rZ - 1 >= 0 && houseMap[rX][rY][rZ - 1] > 0 && stairwell) // down evaluation
	{
		cout << counter << ": You can go down the stairs to the next floor." << endl;
		down = counter;
		counter++;
	}
	if (rX + 1 < NUM_X && houseMap[rX + 1][rY][rZ] > 0) // east evaluation
	{
		cout << counter << ": You can go into a room to the east." << endl;
		east = counter;
		counter++;
	}
	if (rX - 1 >= 0 && houseMap[rX - 1][rY][rZ] > 0) // west evaluation
	{
		cout << counter << ": You can go into a room to the west." << endl;
		west = counter;
		counter++;
	}
	if (rY + 1 < NUM_Y && houseMap[rX][rY + 1][rZ] > 0) // north evaluation
	{
		cout << counter << ": You can go into a room to the north." << endl;
		north = counter;
		counter++;
	}
	if (rY >= 0 && houseMap[rX][rY - 1][rZ] > 0) // south evaluation
	{
		cout << counter << ": You can go into a room to the south." << endl;
		south = counter;
		counter++;
	}
	if (houseMap[rX][rY][rZ] == 10)
	{
		cout << counter << ": You can leave the house through the front door." << endl;
		frontDoor = counter;
		counter++;
	}
	
	cout << endl;
	int playerDecision = -1;
	// while loop for player movement decision
	while (playerDecision < 0 || playerDecision >= counter)
	{
		cout << "Enter the number of the option you want. Enter a 0 to stay in your current room." << endl;
		try
		{
			playerDecision = houseInputCheck.getGoodInt();
		}
		catch (string exceptionStr)
		{
			cout << exceptionStr;
		}
	}
	// Determing the results of the outcome
	if (playerDecision == 0)
	{
		playerStay = true;
		cout << "You decide to stay put." << endl;
	}
	else
	{
		if (playerDecision == up)
		{
			cout << "You decide to head up the stairs." << endl;
			// Update both maps
			playerMap[rX][rY][rZ + 1] = 7;
			playerMap[rX][rY][rZ] = 2;
			houseMap[rX][rY][rZ + 1] = 7;
			houseMap[rX][rY][rZ] = 2;
			// Set player's internal Location coordinates
			Location temp(rX, rY, rZ + 1);
			player.setLoc(temp);
		}
		else if (playerDecision == down)
		{
			cout << "You decide to head down the stairs." << endl;
			// Update both maps
			playerMap[rX][rY][rZ - 1] = 7;
			playerMap[rX][rY][rZ] = 2;
			houseMap[rX][rY][rZ - 1] = 7;
			houseMap[rX][rY][rZ] = 2;
			// Set player's internal Location coordinates
			Location temp(rX, rY, rZ - 1);
			player.setLoc(temp);
		}
		else if (playerDecision == east)
		{
			cout << "You decide to head into the room to the east." << endl;
			// Update both maps
			playerMap[rX + 1][rY][rZ] = houseMap[rX + 1][rY][rZ] + 5;
			playerMap[rX][rY][rZ] = playerMap[rX][rY][rZ] - 5;
			houseMap[rX + 1][rY][rZ] = houseMap[rX + 1][rY][rZ] + 5;
			houseMap[rX][rY][rZ] = houseMap[rX][rY][rZ] - 5;
			// Set player's internal Location coordinates
			Location temp(rX + 1, rY, rZ);
			player.setLoc(temp);
		}
		else if (playerDecision == west)
		{
			cout << "You decide to head into the room to the west." << endl;
			// Update both maps
			playerMap[rX - 1][rY][rZ] = houseMap[rX - 1][rY][rZ] + 5;
			playerMap[rX][rY][rZ] = playerMap[rX][rY][rZ] - 5;
			houseMap[rX - 1][rY][rZ] = houseMap[rX - 1][rY][rZ] + 5;
			houseMap[rX][rY][rZ] = houseMap[rX][rY][rZ] - 5;
			// Set player's internal Location coordinates
			Location temp(rX - 1, rY, rZ);
			player.setLoc(temp);
		}
		else if (playerDecision == north)
		{
			cout << "You decide to head into the room to the north." << endl;
			// Update both maps
			playerMap[rX][rY + 1][rZ] = houseMap[rX][rY + 1][rZ] + 5;
			playerMap[rX][rY][rZ] = playerMap[rX][rY][rZ] - 5;
			houseMap[rX][rY + 1][rZ] = houseMap[rX][rY + 1][rZ] + 5;
			houseMap[rX][rY][rZ] = houseMap[rX][rY][rZ] - 5;
			// Set player's internal Location coordinates
			Location temp(rX, rY + 1, rZ);
			player.setLoc(temp);
		}
		else if (playerDecision == south)
		{
			cout << "You decide to head into the room to the south." << endl;
			// Update both maps
			playerMap[rX][rY - 1][rZ] = houseMap[rX][rY - 1][rZ] + 5;
			playerMap[rX][rY][rZ] = playerMap[rX][rY][rZ] - 5;
			houseMap[rX][rY - 1][rZ] = houseMap[rX][rY - 1][rZ] + 5;
			houseMap[rX][rY][rZ] = houseMap[rX][rY][rZ] - 5;
			// Set player's internal Location coordinates
			Location temp(rX, rY - 1, rZ);
			player.setLoc(temp);
		}
		else
		{
			if (objectiveFound)
			{
				cout << "You grab the handle of the front door and quickly exit the house." << endl;
				cout << "Clutched in your hands is your " << objectiveName << ", safe and secure. " << endl;
			}
			else
			{
				cout << "You creak open the front door, and exit, defeated, but alive..." << endl;
			}
			gameComplete = true;
		}
	}

	return playerStay;
}


void House::listen(int roomIndex)
{
	cout << "You stop and carefully listen. The house creaks and groans as wind blows through it." << endl;
	// declaring the x, y, and z integers for the room in order to cleanly access the surrounding rooms through
	// the houseMap array.
	int rX, rY, rZ;
	// the mX, mY, and mZ integers represents the located monster's coordinates
	int mX, mY, mZ;
	int lTalent = player.getListeningTalent();
	bool monsterNearby = false;
	rX = roomList[roomIndex].getRoomLoc().getX();
	rY = roomList[roomIndex].getRoomLoc().getY();
	rZ = roomList[roomIndex].getRoomLoc().getZ();
	// These for loops will check the surrounding area, starting at a negative location and looking around it.
	for (int i = -lTalent; i <= lTalent; i++)
	{
		for (int j = -lTalent; j <= lTalent; j++)
		{
			// ensuring a legal check will be made before checking if monster is at location
			if (rX + i < NUM_X && rY + j < NUM_Y && rX + i >= 0 && rY >= 0)
			{
				if (houseMap[rX + i][rY + j][rZ] == 3)
				{
					monsterNearby = true;
					mX = rX + i;
					mY = rY + j;
					mZ = rZ;
				}
			}
		}
	}
	// Players who picked up the listening talent can hear the room directly above and below them
	if (player.getListeningTalent() > 1)
	{
		// checking if there is a floor above
		if (rZ + 1 < NUM_Z)
		{
			if (houseMap[rX][rY][rZ + 1] == 3)
			{
				monsterNearby = true;
				mX = rX;
				mY = rY;
				mZ = rZ + 1;
			}
		}
		// checking if there is a floor above
		if (rZ - 1 >= 0)
		{
			if (houseMap[rX][rY][rZ - 1] == 3)
			{
				monsterNearby = true;
				mX = rX;
				mY = rY;
				mZ = rZ - 1;
			}
		}
	}
	if (monsterNearby)
	{
		if (mZ > rZ)
		{
			cout << "You hear the shifting of floor boards above you. You think the monster is there." << endl;
		}
		else if (mZ < rZ)
		{
			cout << "You hear the groaning of something below you. You think the monster is there." << endl;
		}
		else if (mY < rY)
		{
			if (mY == rY - 1)
			{
				cout << "You hear a deep, snarling breath to the room south of you. You think the monster is right there!" << endl;
			}
			else
			{
				cout << "You hear something in one of the rooms south of you. You think the monster is somewhere around there." << endl;
			}
		}
		else if (mY > rY)
		{
			if (mY == rY + 1)
			{
				cout << "You hear a claw scrape the floor of the room to the north of you. You think the monster is over there!" << endl;
			}
			else
			{
				cout << "You hear something turn over in one of the rooms north of you. You think the monster is somewhere around there." << endl;
			}
		}
		else if (mX > rX)
		{
			if (mX == rX + 1)
			{
				cout << "You hear a deep growl in the room just east of you. You think the monster is just beyond the wall!" << endl;
			}
			else
			{
				cout << "You hear something turn over in one of the rooms east of you. You think the monster is somewhere around there." << endl;
			}
		}
		else
		{
			if (mX == rX - 1)
			{
				cout << "You hear a spine chilling hiss just west of you. You think the monster is just beyond the wall!" << endl;
			}
			else
			{
				cout << "You hear inhuman gurgling noises coming from one of the rooms west of you. You think the monster is somewhere around there." << endl;
			}
		}
	}
	else
	{
		cout << "You sit and listen, hearing all sorts of terrifying creaks, snaps, and rustling in the rooms around you." << endl;
		cout << "None of it seems to be the monster... you think." << endl;
	}
}

void House::objectiveSearch(int roomIndex)
{
	if (roomList[roomIndex].getRoomLoc() == objectiveLoc && !objectiveFound)
	{
		cout << "Scouring the room top to bottom, you manage to find your " << objectiveName << "!" << endl;
		cout << "You got what you came for! Now you can leave this manor!" << endl;
		objectiveFound = true;
	}
	else if (objectiveFound)
	{
		cout << "You already found your " << objectiveName << ". You just need to get out of the house!" << endl;
	}
	else
	{
		cout << "After carefully searching the room, you come to realize that your " << objectiveName << " isn't here." << endl;
	}
}

bool House::isKilled()
{
	bool killed = false;
	if (monsterLoc == player.getLoc())
	{
		killed = true;
		gameComplete = true;
	}
	return killed;
}

void House::clockStart()
{
	hour = 9;
	// if the player has the early bird talent, the clock starts an hour early
	if (player.getEarlyBird())
	{
		hour--;
	}
	minute = 0;
}

void House::clockUpdate()
{
	minute += 5;
	if (minute == 60)
	{
		minute = 0;
		hour++;
	}
}

bool House::clockEnd()
{
	bool gameEnd = false;
	if (hour >= 12)
	{
		gameEnd = true;
		gameComplete = true;
	}
	return gameEnd;
}


// This function prints out across the text box a map of the map that the player has
// already explored to the screen, with various letters representing different points
// of interest.
void House::mapDraw()
{
	// start by determining how far across the "maps" need to be printed.

	cout << endl;	// giving some space for the maps

	for (int i = NUM_Y - 1; i >=0 ; i--)	// handles vertical movement of map printing
	{
		cout << "  ";
		for (int j = 0; j < NUM_Z; j++)	// handles sections of map printing
		{
			cout << "  ";
			for (int k = 0; k < NUM_X ; k++)	// handles rows of map printing
			{
				if (playerMap[k][i][j] == 0)
				{
					// Doing evaluation to see if there is an undiscovered room in place
					bool questionPrint = false;
					if (houseMap[k][i][j] > 0)
					{
						if (k + 1 < NUM_X && playerMap[k + 1][i][j] > 0)
						{
							cout << "?";
							questionPrint = true;
						}
						else if (k - 1 >= 0 && playerMap[k - 1][i][j] > 0)
						{
							cout << "?";
							questionPrint = true;
						}
						else if (i + 1 < NUM_Y && playerMap[k][i + 1][j] > 0)
						{
							cout << "?";
							questionPrint = true;
						}
						else if (i - 1 < NUM_Y && playerMap[k][i - 1][j] > 0)
						{
							cout << "?";
							questionPrint = true;
						}
					}
					// If there was no question mark printed, print a space
					if(!questionPrint)
					{
						cout << " ";
					}
				}
				else if (playerMap[k][i][j] == 1 || !objectiveFound && playerMap[k][i][j] == 4)
				{
					cout << "R";
				}
				else if (playerMap[k][i][j] == 2)
				{
					cout << "S";
				}
				else if (playerMap[k][i][j] == 3)
				{
					cout << "M";
				}
				else if (playerMap[k][i][j] == 4 && objectiveFound)
				{
					cout << "O";
				}
				else if (playerMap[k][i][j] == 5)
				{
					cout << "E";
				}
				else
				{
					cout << "P";
				}
			}
			cout << "  ";
		}

		cout << endl;
	}
	
	cout << endl;
	// Printing out titles for the names of areas.
	cout << "      Cellar    ";
	cout << "  First Floor ";
	cout << "  Second Floor  ";
	cout << endl;
}
