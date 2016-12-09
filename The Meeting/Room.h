#pragma once
#include <iostream>
#include <string>
using namespace std;

class Room;

string operator ! (string&);
istream &operator >> (istream &, Room *&);
ostream &operator << (ostream &, const Room *);

class Room
{
private:
	string name;
	string description;
	Room *north;
	Room *south;
	Room *east;
	Room *west;
	string type;

public:
	Room(string name, string description);
	Room(string name, string description, string type);
	~Room();
	string getName() const;
	string getDescription() const;
	void link(Room *r, string direction);
	const Room *getLinked(string direction);
	void printLinked();
	void linkTo(Room &r, string direction);

	friend istream &operator >> (istream &, Room *&);
	friend ostream &operator << (ostream &, const Room *);
};

