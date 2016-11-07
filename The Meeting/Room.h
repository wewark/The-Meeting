#pragma once
#include <iostream>
#include <string>
using namespace std;

class Room;

string operator ! (string&);
istream &operator >> (istream &, Room &);
ostream &operator << (ostream &, const Room &);

class Room
{
private:
	string name;
	string description;
	Room *north;
	Room *south;
	Room *east;
	Room *west;
public:
	Room(string name, string description);
	~Room();
	string getName() const {
		return name;
	}
	string getDescription() const {
		return description;
	}
	void link(Room *r, string direction);
	Room *getLinked(string direction);
	void printLinked();
	void linkTo(Room &r, string direction);

	friend istream &operator >> (istream &, Room &);
};

