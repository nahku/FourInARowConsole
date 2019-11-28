#include "stdafx.h"
#include "LeftBot.h"


int LeftBot::getNextTileReq(const std::array<std::array<int, 6>, 7> & grid)
{
	int column = 0;

	for (std::array<int, 6>  arr : grid) {
		for (int i = 0; i < 6; i++) {
			if (arr.at(i) == 0) {
				return column;
			}
		}
		column++;
	}

	return -1;
}

LeftBot::LeftBot(int id, std::string name):Bot(id,name)
{
}


LeftBot::~LeftBot()
{
}

int LeftBot::requestSetTile(const std::array<std::array<int, 6>, 7>& grid)
{
	return getNextTileReq(grid);
}
