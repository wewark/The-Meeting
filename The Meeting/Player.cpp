#include "Player.h"

Player::Player(string name, Room * startingRoom) : Agent(name, startingRoom)
{
	won = false;
	quit = false;
}

Player::~Player()
{
}

bool Player::act()
{
	currentRoom->printLinked();
	string response;
	cin >> response;
	while (
		!(response == "north" || response == "south" ||
			response == "east" || response == "west" ||
			response == "wait")
		|| (response == "north" || response == "south" ||
			response == "east" || response == "west")
		&& currentRoom->getLinked(response) == NULL)
	{
		cout << "Wrong choice! Try again" << endl;
		cin >> response;
	}
	if (response == "north" || response == "south" ||
		response == "east" || response == "west")
	{
		currentRoom->leave(this);
		currentRoom = currentRoom->getLinked(response);
		currentRoom->enter(this);
	}
	if (currentRoom->getSize() > 1)
		return false;
	return true;
}

void Player::playerEscaped() {
	won = true;
}

bool Player::gameOn() {
	return !(won || quit);
}

bool Player::playerWon() {
	return won;
}