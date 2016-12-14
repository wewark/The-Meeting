#include <iostream>
#include <string>
#include <Windows.h>

#include "Agent.h"
#include "Room.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

int main() {
	string map[11] = {
		"#####.#####",
		"#.........#",
		"#.#########",
		"#.........#",
		"#.#######.#",
		"#...#.#...#",
		"###.#.#.#.#",
		"#.#...#.#.#",
		"#.#.###.#.#",
		"#...#...#.#",
		"#####.#####"
	};
	Room** room = new Room*[MAP_SIZE];
	for (int i = 0; i < MAP_SIZE; i++)
		room[i] = new Room[MAP_SIZE];

	// Autolink rooms using the map
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (map[i][j] == '#')
				room[i][j].makeBlock();
			else
			{
				if (i > 0 && map[i - 1][j] == '.')
					room[i][j].link(&room[i - 1][j], "north");
				if (i < 10 && map[i + 1][j] == '.')
					room[i][j].link(&room[i + 1][j], "south");
				if (j > 0 && map[i][j - 1] == '.')
					room[i][j].link(&room[i][j - 1], "west");
				if (j < 10 && map[i][j + 1] == '.')
					room[i][j].link(&room[i][j + 1], "east");
			}
		}

	// Define paths for the monsters
	string
		path1[] = {
		"south","south","south","south",
		"north","north","north","north","north","north",
		"south","south"
	},
		path2_1[] = {
		"east","east","east","east","east","east",
		"west","west","west","west","west","west"
	};

	Agent* m1 = new Monster("Monster1", &room[5][9], path1, 12);
	Agent* m2 = new Monster("Monster2", &room[3][1], path2_1, 12);
	Agent* player = new Player("Player1", &room[10][5]);
	Agent **agents = new Agent*[3]{ player, m1,m2 };

	m1->startMoving();
	m2->startMoving();
	bool end = false;
	while (!end)
	{
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			Room::printMap(room);
			if (!agents[i]->act())
				end = true;
		}
	}
	return 0;
}