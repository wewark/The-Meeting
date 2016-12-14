#include "Room.h"

Room::Room()
{
	name = "";
	description = "";
	block = false;

	// Linked to nothing
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}

Room::Room(string name, string description) {

	this->name = name;
	this->description = description;
	type = "room";

	// Linked to nothing
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}

Room::Room(string name, string description, string type) {

	this->name = name;
	this->description = description;
	this->type = type;

	// Linked to nothing
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}

Room::~Room()
{
}

string Room::getName() const {
	return name;
}

string Room::getDescription() const {
	return description;
}

void Room::printMap(Room** room)
{
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
			if (room[i][j].isBlock())
				cout << '#';
			else if (room[i][j].occupantsSize == 0)
				cout << ' ';
			else if (room[i][j].occupants[0]->getName() == "Player1")
				cout << 'X';
			else
				cout << room[i][j].occupants[0]->nextMove();
		cout << endl;
	}
}

void Room::makeBlock()
{
	block = true;
}

bool Room::isBlock()
{
	return block;
}

// Link room to another room, one way
void Room::link(Room *r, string direction) {
	if (direction == "north")
		north = r;
	else if (direction == "south")
		south = r;
	else if (direction == "east")
		east = r;
	else if (direction == "west")
		west = r;
}

// Get room linked in a certain direction
Room *Room::getLinked(string direction) {
	if (direction == "north")
		return north;
	else if (direction == "south")
		return south;
	else if (direction == "east")
		return east;
	else if (direction == "west")
		return west;
	else return NULL;
}

// Print the name of the room linked in each direction
void Room::printLinked() {
	cout << "You can go:" << endl;
	if (north != NULL)
		cout << "North" << endl;
	if (south != NULL)
		cout << "South" << endl;
	if (east != NULL)
		cout << "East" << endl;
	if (west != NULL)
		cout << "West" << endl;
	cout << "or wait" << endl;
}

void Room::enter(Agent *a)
{
	occupants[occupantsSize++] = a;
}

void Room::leave(Agent *a)
{
	for (int i = 0; i < occupantsSize; i++)
		if (occupants[i]->getName() == a->getName())
		{
			for (int j = i + 1; j < occupantsSize; j++)
				occupants[j - 1] = occupants[j];
			break;
		}
	occupantsSize--;
}

int Room::getSize()
{
	return occupantsSize;
}
