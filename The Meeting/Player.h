#pragma once
#include <string>
using namespace std;

class Player
{
private:
	int hour;
	int min;
	static int deadline;
	int passedMins;
	bool won;
	bool key;
	bool quit;

public:
	Player();
	~Player();
	void operator ++ (int);
	bool tooLate();
	void playerEscaped();
	string getTime();
	string getDeadlineTime();
	bool gameOn();
	void takeKey();
	bool hasKey();
	bool playerWon();
	int getPassedMins();
	void quitGame();
	bool quitted();
};

