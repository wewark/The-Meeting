#pragma once
#include "Agent.h"
using namespace std;

class Monster : public Agent
{
public:
	Monster(string name, Room *startingRoom) : Agent(name, startingRoom) { };
	~Monster();
	bool act();
};

