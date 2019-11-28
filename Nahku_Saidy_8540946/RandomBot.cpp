#include "stdafx.h"
#include "RandomBot.h"
#include <random>


int RandomBot::getNextTileReq(const std::array<std::array<int, 6>, 7>& grid)
{
	int column = 0;
	bool flag_free_space;
	std::random_device rd;

	do {
		flag_free_space = false;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, 6);

		column = dist(gen);

		if (grid.at(column).at(5) == 0) {
			break;
		}

		for (int i = 0; i < 7; i++) //Prüfe, ob es auf dem Spielfeld noch freie Positionen gibt 
		{
			if (grid.at(i).at(5) == 0) {
				flag_free_space = true;
			}
		}

		if (flag_free_space == false) {
			return -1;	//In diesem Fall kein Platz mehr auf dem Feld frei
		}
	} while (true);


	return column;
}

RandomBot::RandomBot(int id, std::string name):Bot(id,name)
{
}


RandomBot::~RandomBot()
{
}

int RandomBot::requestSetTile(const std::array<std::array<int, 6>, 7>& grid)
{
	return getNextTileReq(grid);
}
