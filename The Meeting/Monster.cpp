#include "Monster.h"


Monster::Monster(string name, Room * startingRoom) : Agent(name, startingRoom)
{
}

Monster::Monster(string name, Room * startingRoom, string * path, int pathSz) : Agent(name, startingRoom)
{
	this->pathSz = pathSz;
	this->path = new string[pathSz];
	for (int i = 0; i < pathSz; i++)
		this->path[i] = path[i];
	pathStep = 0;
}

Monster::~Monster()
{
}

bool Monster::act()
{
	if (moving && move(path[pathStep]))
	{
		pathStep = (pathStep + 1) % pathSz;
		if (currentRoom->getSize() > 1)
			return false;
	}
	return true;
}

void Monster::startMoving()
{
	moving = true;
}

char Monster::nextMove()
{
	if (path[pathStep] == "north")
		return 'N';
	else if (path[pathStep] == "south")
		return 'S';
	else if (path[pathStep] == "east")
		return 'E';
	else if (path[pathStep] == "west")
		return 'W';
	return 'F';
}
