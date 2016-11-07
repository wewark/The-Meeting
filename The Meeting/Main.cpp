#include <iostream>
#include <string>
#include "Room.h"
using namespace std;

int main() {
	while (true)
	{
		// initialize the map
		Room bedroom1(
			"A Bedroom",
			"desc"
		);
		Room balcony1(
			"A Balcony",
			"desc"
		);
		Room toilet1(
			"A Toilet",
			"desc"
		);
		Room livingroom(
			"A Living Room",
			"desc"
		);
		Room balcony2(
			"A Balcony",
			"desc"
		);
		Room bedroom2(
			"A Bedroom",
			"desc"
		);
		Room toilet2(
			"A Toilet",
			"desc"
		);
		Room hall(
			"A Hall",
			"desc"
		);
		Room stairs(
			"Stairs",
			"desc"
		);

		// Linking rooms
		bedroom1.linkTo(balcony1, "south");
		bedroom1.linkTo(toilet1, "west");
		bedroom1.linkTo(livingroom, "north");
		livingroom.linkTo(balcony2, "east");
		livingroom.linkTo(hall, "west");
		livingroom.linkTo(bedroom2, "north");
		hall.linkTo(toilet1, "south");
		hall.linkTo(stairs, "west");
		bedroom2.linkTo(toilet2, "east");

		
		// Start from bedroom1
		Room *currentRoom = &bedroom1;
		Room temp = *currentRoom;

		while (true)
		{
			cout << *currentRoom;
			//temp = *currentRoom;
			cin >> *currentRoom;
		}
	}
	return 0;
}