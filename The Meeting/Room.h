#pragma once
#include <iostream>
#include <string>
#include "Agent.h"
using namespace std;

class Room;
class Agent;
const int MAX_SIZE = 2;

class Room
{
protected:
	string name;
	string description;
	Room *north;
	Room *south;
	Room *east;
	Room *west;
	string type;
	bool block;
	Agent* occupants[MAX_SIZE];
	int size = 0;

public:
	Room();
	Room(string name, string description);
	Room(string name, string description, string type);
	~Room();
	string getName() const;
	string getDescription() const;
	void makeBlock();
	void link(Room *r, string direction);
	Room *getLinked(string direction);
	void printLinked();
	void enter(Agent *a);
	void leave(Agent *a);
	int getSize();
};

