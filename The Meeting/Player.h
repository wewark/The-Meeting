#pragma once
#include "Agent.h"
#include <string>
using namespace std;

class Player : public Agent
{
private:
	bool won;
	bool quit;

public:
	Player(string name, Room *startingRoom);
	~Player();
	bool act();
	void playerEscaped();
	bool gameOn();
	bool playerWon();
	char nextMove() { return 0; };
	void startMoving() {};
};

