#include "Player.h"
#include <ctime>

int Player::deadline = 60;

Player::Player()
{
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);
	hour = ltm.tm_hour;
	min = ltm.tm_min;
	passedMins = 0;
	won = false;
	key = false;
	quit = false;
}

Player::~Player()
{
}

void Player::operator ++ (int) {
	passedMins++;
	min++;
	hour += min / 60;
	min %= 60;
	hour %= 24;
}

bool Player::tooLate() {
	if (passedMins <= deadline)
		return false;
	return true;
}

string Player::getTime() {
	string hrs = to_string(hour % 12);
	string mins = to_string(min);

	string ampm = "AM";
	if ((hour + 1) % 24 >= 12)
		ampm = "PM";
	if (hrs.length() == 1)
		hrs = "0" + hrs;
	if (mins.length() == 1)
		mins = "0" + mins;

	return hrs + ":" + mins + " " + ampm;
}

string Player::getDeadlineTime() {
	string hrs = to_string((hour + 1) % 12);
	string mins = to_string(min);

	string ampm = "AM";
	if ((hour + 1) % 24 >= 12)
		ampm = "PM";
	if (hrs.length() == 1)
		hrs = "0" + hrs;
	if (mins.length() == 1)
		mins = "0" + mins;

	return hrs + ":" + mins + " " + ampm;
}

void Player::playerEscaped() {
	won = true;
}

bool Player::gameOn() {
	return !(won || tooLate() || quit);
}

void Player::takeKey() {
	key = true;
}

bool Player::hasKey() {
	return key;
}

bool Player::playerWon() {
	return won;
}

int Player::getPassedMins() {
	return passedMins;
}

void Player::quitGame() {
	quit = true;
}

bool Player::quitted() {
	return quit;
}