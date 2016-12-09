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
	return false;
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