#include <iostream>
#include <string>
#include "Agent.h"
#include "Room.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

int main() {
	Room y("d", "d");
	Agent* m1 = new Monster("name1", &y);
	Agent* m2 = new Monster("name2", &y);
	Agent* player = new Player("pname", &y);
	Agent **agents = new Agent*[3];
	agents[0] = player;
	agents[1] = m1;
	agents[2] = m2;

	cin.get();

	/*
	while (true)
	{
		// Setting new player
		Player player1;
		Room::setPlayer(player1);

		// Game intro
		system("cls");
		cout << endl << "You wake up on a bed in a house you don't know. You look around there is no one in the house. You don't remember anything. But you have a strong feeling that you've forgot something important You keep looking around trying to remember anything..." << endl;
		system("pause");
		system("cls");
		cout << endl << "You feel your phone in your pocket vibrating, it's a message from John, your interviewer. It says \"Today at " << player1.getDeadlineTime() << "\" You suddenly remember everything..." << endl;
		system("pause");
		system("cls");
		cout << endl << "You have an interview at Monsters Inc. at " << player1.getDeadlineTime() << ". It's " << player1.getTime() << " now. Hurry up you don't have much time left." << endl;
		system("pause");
		system("cls");
		cout << endl << "You can only go north, south, east or west." << endl;
		system("pause");
		system("cls");

		// Initialize the map
		Room bedroom1(
			"A Bedroom",
			"You're in a bedroom, only a small lamp is on. The bed is white and looks messy, above it is a portrait of a middle-aged man who seems to be a soldier. The rest of the room furniture is all covered in dust.\n\nTo the north you can see a door leading to a living room, to the south there is a balcony, at your east is a wall with the picture of the soldier on it and at your west is a bathroom."
		);
		Room balcony1(
			"A Balcony",
			"It's an empty balcony. You can see the street. It's midday and normal people in the street.\n\nThe balcony's fence surround you at your east, south and west. At your north is the bedroom.",
			"balcony"
		);
		Room toilet1(
			"A Toilet",
			"White light, a bath, a shower, a tap. Nothing looks wrong about this bathroom.\n\nTo the north you can see a hall. The east leads to a bedroom. There is nothing at your south or west."
		);
		Room livingroom(
			"A Living Room",
			"Looks like there is no one in this house, everything is turned off except for some small lights. There is a couch, a TV with nothing connected to it, and a bunch of pictures on the walls.\n\nThere is a balcony at you east, your west leads to a hall and two bedrooms, one at your north and another at your south."
		);
		Room balcony2(
			"A Balcony",
			"It's an empty balcony. You can see the street. It's midday and normal people in the street.\n\nThe balcony's fence surround you at your east, south and north. At your west is the living room.",
			"balcony"
		);
		Room bedroom2(
			"A Bedroom",
			"This bedroom looks just like the other bedroom. One bed in the middle of the room. To your east is a bathroom, the south leads to the living room, to your west is a wall that is so clean and to the north is another wall.",
			"bedroom2"
		);
		Room toilet2(
			"A Toilet",
			"White light, a bath, a shower, a tap. Nothing looks wrong about this bathroom. Nothing to the north. The west leads to a bedroom. There is nothing at your south or east."
		);
		Room hall(
			"A Hall",
			"This hall leads from the living room to the door of the house. At your north is a door, it seems to lead to the kitchen, at your south is a toilet, your east leads to the living room and at your west is the door of the house.",
			"hall"
		);
		Room stairs(
			"Stairs",
			"desc",
			"end"
		);
		Room darkRoom(
			"A Dark Room",
			"It's very dark. You can't see anything.",
			"secret"
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
		bedroom2.linkTo(darkRoom, "west");


		// Start from bedroom1
		Room *currentRoom = &bedroom1;

		while (player1.gameOn())
		{
			cout << currentRoom;
			cin >> currentRoom;
		}

		if (player1.quitted())
			break;

		if (player1.playerWon())
		{
			cout << "You've finally got out of the house and it's " << player1.getTime() << ", it took you " << player1.getPassedMins() << " mins" << endl << "Good Job!" << endl;
		}
		else
			cout << "It's already " << player1.getTime() << ", you just missed the meeting. You've lost your job." << endl;

		string response;
		cout << "again or quit?" << endl;
		cin >> response;

		if (response != "again")
			break;
	}
	*/
	return 0;
}