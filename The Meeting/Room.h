#pragma once
#include <iostream>
#include <string>
#include "Agent.h"
using namespace std;

class Room;
class Agent;
#define MAX_SIZE 2
#define MAP_SIZE 11

class Room
{
protected:
	string name;
	string description;
	int roomNum;
	Room *north;
	Room *south;
	Room *east;
	Room *west;
	string type;
	bool block;
	Agent* occupants[MAX_SIZE];
	int occupantsSize = 0;

public:
	Room();
	Room(string name, string description);
	Room(string name, string description, string type);
	~Room();
	string getName() const;
	string getDescription() const;
	void setNum(int n);
	int getNum() const;
	static void printMap(Room** room);
	void makeBlock();
	void unBlock();
	bool isBlock();
	void link(Room *r, string direction);
	Room *getLinked(string direction);
	void printLinked();
	void enter(Agent *a);
	void leave(Agent *a);
	int getOccupantsSize();
};

