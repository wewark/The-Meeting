#include "Agent.h"


Agent::Agent()
{
}

Agent::Agent(string name, Room *startingRoom)
{
	this->name = name;
	currentRoom = startingRoom;
}

Agent::~Agent()
{
}
