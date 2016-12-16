#include <iostream>
#include <string>
#include <Windows.h>

#include "Agent.h"
#include "Room.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

int main() {
	bool exitGame = false;
	while (!exitGame)
	{
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
				room[i][j].setNum(i * 11 + j);
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
			path2[] = {
			"east","east","east","east","east","east",
			"west","west","west","west","west","west",
			"north","north",
			"east","east","east","east",
		};

		Agent* m1 = new Monster("Monster1", &room[5][9], path1, 12);
		Agent* m2 = new Monster("Monster2", &room[3][1], path2, 18);
		Agent* player = new Player("Player1", &room[10][5]);
		Agent **agents = new Agent*[3]{ player, m1,m2 };

		bool end = false;
		string warning = "That's a map of the maze.\n\nX -> You\n# -> Wall\n  -> Space\n? -> Unknown";
		while (!end)
		{
			system("cls");
			Room::printMap(room);
			if (warning != "")
			{
				cout << endl << warning << endl << endl;
				warning = "";
			}

			for (int i = 0; i < 3 && !end; i++)
			{
				if (!agents[i]->act())
					end = true;
			}

			if (end)
			{
				system("cls");
				Room::printMap(room);
				string response;
				if (Player::playerWon())
					cout << "\nYou Escaped\nGOOD JOB!!" << endl;
				else
					cout << "\nYou got eaten" << endl;
				cout << "\nAgain or quit?" << endl;
				cin >> response;
				if (response != "again")
					exitGame = true;
			}

			// All the next is only related to the game story
			// Monster1 starts moving after you see it
			if (player->getCurrentRoom()->getNum() == 63 &&
				m1->getCurrentRoom()->getNum() == 64)
			{
				warning = "That's a monster, wait for it to go away.\nThe letter on the monster defines the direction it's going at.";
				m1->startMoving();
			}

			// Monster2 starts moving when you see it
			if (player->getCurrentRoom()->getNum() == 35 &&
				m2->getCurrentRoom()->getNum() == 34)
			{
				warning = "That one is coming at me!";
				m2->startMoving();
			}

			// Monster2 stops moving at a certain cell
			if (m2->getCurrentRoom()->getNum() == 16)
				m2->stopMoving();

			// Step on a certain cell and magic happens
			if (player->getCurrentRoom()->getNum() == 78 &&
				room[4][5].isBlock())
			{
				warning = "A great sound. Like the sound of a big stone moving.\nMaybe that have awaken the sleeping monster.";
				room[4][5].unBlock();
				room[4][5].link(&room[3][5], "north");
				room[3][5].link(&room[4][5], "south");
				room[4][5].link(&room[5][5], "south");
				room[5][5].link(&room[4][5], "north");
				m2->startMoving();
				m2->startChasing();
			}

			// Monster2 sleeps
			if (room[4][5].isBlock() &&
				m2->getCurrentRoom()->getNum() == 16 &&
				player->getCurrentRoom()->getNum() == 15)
			{
				warning = "It's sleeping. It won't move.";
			}

			// Monster2 starts chasing once you get close to it
			if (!room[4][5].isBlock() &&
				m2->getCurrentRoom()->getNum() == 16 &&
				player->getCurrentRoom()->getNum() == 14)
			{
				warning = "It looks angry. It's CHASING ME!!\nBut I am not sure. Better wait and see what it will do";
				m2->startMoving();
			}
		}
	}
	return 0;
}