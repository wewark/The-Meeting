#include <iostream>
#include <string>
#include <Windows.h>

#include "Agent.h"
#include "Room.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

int main() {
	Room room[11][11];
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

	// Autolink rooms using the map
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
		{
			if (map[i][j] == '#')
				room[i][j].makeBlock();
			else
			{
				if (i > 0 && map[i - 1][j] == '.')
					room[i][j].link(&room[i - 1][j], "west");
				if (i < 10 && map[i + 1][j] == '.')
					room[i][j].link(&room[i + 1][j], "east");
				if (j > 0 && map[i][j - 1] == '.')
					room[i][j].link(&room[i - 1][j], "north");
				if (j < 10 && map[i][j + 1] == '.')
					room[i][j].link(&room[i + 1][j], "south");
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
		"east","east","east","east","east","east"
	};

	Agent* m1 = new Monster("Monster1", &room[5][9], path1, 12);
	Agent* m2 = new Monster("Monster2", &room[3][1], path2_1, 6);
	Agent* player = new Player("Player1", &room[10][5]);
	Agent **agents = new Agent*[3]{ player, m1,m2 };

	cin.get();
	return 0;
}