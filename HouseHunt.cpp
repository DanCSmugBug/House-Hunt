/*
 * File Name: HouseHunt.cpp
 * Author: Daniel Cole
 * Date Created: 5/18/2019
 * Date Last Updated: 6/17/2019
 * Version: 1.0
 * Description: A game in which you search for items in a house before
 * time runs out while avoiding waking up The Monster.
 *
 */
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <string>
#include <stdlib.h>
#include <crtdbg.h>
#include "Location.h"
#include "GameCharacter.h"
#include "House.h"
using namespace std;


int main()
{
	House gameHouse;

	bool exit = false;
    while (!exit)
	{
		exit = gameHouse.gameRun();
    }
    return 0;
}



// Current Bug List: 
// House generation system seems to work fine, at least for smaller houses
// monster seems to have gotten got placed without the objective
// Had one game scenario where attempting to move east caused a repeat of the player choice line
// Memory Leaks seemingly fixed