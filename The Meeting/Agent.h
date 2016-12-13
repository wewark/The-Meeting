#pragma once
#include "Room.h"
using namespace std;

class Room;

class Agent
{
protected:
	Room *currentRoom;
	string name;
public:
	virtual bool act() = 0;
	Agent();
	Agent(string name, Room *startingRoom);
	~Agent();
	string getName() { return name; }
	bool move(string direction);
};

