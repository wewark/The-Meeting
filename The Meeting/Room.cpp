#include "Room.h"


Room::Room(string name, string description) {
	this->name = name;
	this->description = description;

	// Linked to nothing
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}

Room::~Room()
{
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

// Link 2 rooms, both ways
void Room::linkTo(Room &r, string direction) {

	// Link this room to the other one
	link(&r, direction);

	// Link the other room to this one
	r.link(this, !direction);
}

string operator ! (string &direction) {
	if (direction == "north")
	{
		return "south";
	}
	else if (direction == "south")
	{
		return "north";
	}
	else if (direction == "east")
	{
		return "west";
	}
	else if (direction == "west")
	{
		return "east";
	}
	else return "Direction error";
}

istream &operator >> (istream &strm, Room &currentRoom) {

	// Print linked rooms
	currentRoom.printLinked();
	
	string response;
	cout << "Go: ";
	strm >> response;
	if (response == "north")
	{
		// If the direction leads no nothing (the direction pointer is pointing at NULL)
		if (currentRoom.north == NULL)
			cout << "You hit a wall!!" << endl;
		// Else change the current room to be the other room
		else
			currentRoom = *currentRoom.north;
	}
	else if (response == "south")
	{
		if (currentRoom.south == NULL)
			cout << "You hit a wall!!" << endl;
		else
			currentRoom = *currentRoom.south;
	}
	else if (response == "east")
	{
		if (currentRoom.east == NULL)
			cout << "You hit a wall!!" << endl;
		else
			currentRoom = *currentRoom.east;
	}
	else if (response == "west")
	{
		if (currentRoom.west == NULL)
			cout << "You hit a wall!!" << endl;
		else
			currentRoom = *currentRoom.west;
	}
	return strm;
}

ostream &operator << (ostream &strm, const Room &currentRoom) {
	strm << currentRoom.getName() << endl;
	strm << currentRoom.getDescription() << endl << endl;
	return strm;
}