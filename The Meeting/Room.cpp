#include "Room.h"

int Room::secretCounter = 0;
Player *Room::player = NULL;

Room::Room(string name, string description) {

	this->name = name;
	this->description = description;
	type = "room";

	secretCounter = 0;

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

	secretCounter = 0;

	// Linked to nothing
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}

Room::~Room()
{
}

void Room::setPlayer(Player &player1) {
	player = &player1;
}

string Room::getName() const {
	return name;
}

string Room::getDescription() const {
	return description;
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
const Room *Room::getLinked(string direction) {

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

istream &operator >> (istream &strm, Room *&currentRoom) {

	// Print linked rooms
	//currentRoom.printLinked();

	string response;
	cout << "Go: ";
	strm >> response;
	system("cls");

	if (response == "quit")
	{
		Room::player->quitGame();
	}
	else if (response == "north")
	{
		// If the direction leads no nothing (the direction pointer is pointing at NULL)
		if (currentRoom->north == NULL)
		{
			if (currentRoom->type == "balcony")
				cout << "No, man. You're gonna die if you jump off the balcony." << endl;
			
			else if (currentRoom->type == "secret")
				cout << "Darkness!!" << endl;

			else if (currentRoom->type == "hall")
				cout << "The door is locked." << endl;

			else
				cout << "You hit a wall!!" << endl;
		}

		// Else change the current room to be the other room
		else
			currentRoom = currentRoom->north;

		// Increment time passed by 1 min
		(*Room::player)++;
	}

	else if (response == "south")
	{
		if (currentRoom->south == NULL)
		{
			if (currentRoom->type == "balcony")
				cout << "No, man. You're gonna die if you jump off the balcony." << endl;

			else if (currentRoom->type == "secret")
				cout << "Darkness!!" << endl;

			else
				cout << "You hit a wall!!" << endl;
		}
		else
			currentRoom = currentRoom->south;

		// Increment time passed by 1 min
		(*Room::player)++;
	}

	else if (response == "east")
	{
		if (currentRoom->east == NULL)
		{
			if (currentRoom->type == "balcony")
				cout << "No, man. You're gonna die if you jump off the balcony." << endl;

			else
				cout << "You hit a wall!!" << endl;
		}
		else
			currentRoom = currentRoom->east;

		// Increment time passed by 1 min
		(*Room::player)++;
	}

	else if (response == "west")
	{
		if (currentRoom->west == NULL)
		{
			if (currentRoom->type == "balcony")
				cout << "No, man. You're gonna die if you jump off the balcony." << endl;

			else if (currentRoom->type == "secret")
				cout << "Darkness!!" << endl;

			else
				cout << "You hit a wall!!" << endl;
		}

		// The door of the house
		else if (currentRoom->type == "hall")
		{
			if (!Room::player->hasKey())
				cout << "The door of the house is locked!!" << endl;

			else if (Room::player->hasKey())
				Room::player->playerEscaped();
		}

		// The wall leading to the secret room
		else if (currentRoom->type == "bedroom2")
		{
			if (Room::secretCounter == 0)
			{
				cout << "You touched the wall, but a strange thing happend, the wall moved a little bit." << endl;
				Room::secretCounter++;
			}
			else if (Room::secretCounter == 1)
			{
				cout << "The wall moved alittle bit more, it seems to be rotating around its center. It's so heavy." << endl;
				Room::secretCounter++;
			}
			else if (Room::secretCounter == 2)
			{
				cout << "OMG It's moving by itself now, rotating around its center. A very dark room appeared behind it." << endl << "There is a key in the dark room on the floor, you picked that key up." << endl;
				Room::player->takeKey();
				Room::secretCounter++;
				currentRoom = currentRoom->west;
			}
			else
				currentRoom = currentRoom->west;
		}

		else
			currentRoom = currentRoom->west;

		// Increment time passed by 1 min
		(*Room::player)++;
	}

	else
		cout << "Wrong command, you can only go north, south, east or west." << endl;
	return strm;
}

ostream &operator << (ostream &strm, const Room *currentRoom) {
	strm << endl << currentRoom->getName() << endl << endl;
	strm << "Time: " << Room::player->getTime() << endl;
	strm << currentRoom->getDescription() << endl << endl;
	return strm;
}
