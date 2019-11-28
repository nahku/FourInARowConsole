#include "stdafx.h"
#include "LeastTileBot.h"


int LeastTileBot::getNextTileReq(const std::array<std::array<int, 6>, 7>& grid)
{
	int columnMinTiles = 0;
	int minTiles = 7;

	for (int column = 0; column < 7; column++)
	{
		int tempTiles = 0;
		for (int height = 0; height < 6; height++)
		{
			if (grid.at(column).at(height) != 0) {
				tempTiles++;
			}
		}

		if (tempTiles < minTiles) {
			minTiles = tempTiles;
			columnMinTiles = column;
		}
	}
	return columnMinTiles;
}

LeastTileBot::LeastTileBot(int id, std::string name):Bot(id,name)
{
}


LeastTileBot::~LeastTileBot()
{
}

int LeastTileBot::requestSetTile(const std::array<std::array<int, 6>, 7>& grid)
{
	return getNextTileReq(grid);
}
