#include "Room.h"

Room::Room()
{
	name = "";
	description = "";
	block = false;
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

void Room::makeBlock()
{
	block = true;
}

// Link room to another room, one way
void Room::link(Room *r, string direction) {

	if (direction == "north")
	{
		north = r;
	}
	else if (direction == "south")
	{
		south = r;
	}
	else if (direction == "east")
	{
		east = r;
	}
	else if (direction == "west")
	{
		west = r;
	}
}

// Get room linked in a certain direction
Room *Room::getLinked(string direction) {

	if (direction == "north")
	{
		return north;
	}
	else if (direction == "south")
	{
		return south;
	}
	else if (direction == "east")
	{
		return east;
	}
	else if (direction == "west")
	{
		return west;
	}
	else return NULL;
}

// Print the name of the room linked in each direction
void Room::printLinked() {
	cout << "North:\t" << (north == NULL ? "A wall" : north->getName()) << endl;
	cout << "South:\t" << (south == NULL ? "A wall" : south->getName()) << endl;
	cout << "East:\t" << (east == NULL ? "A wall" : east->getName()) << endl;
	cout << "West:\t" << (west == NULL ? "A wall" : west->getName()) << endl;
}

void Room::enter(Agent *a)
{
	occupants[size++] = a;
}

void Room::leave(Agent *a)
{
	for (int i = 0; i < size; i++)
		if (occupants[i]->getName() == a->getName())
		{
			for (int j = i + 1; j < size; j++)
				occupants[j - 1] = occupants[j];
		}
	size--;
}

int Room::getSize()
{
	return size;
}
