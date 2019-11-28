#pragma once
#include "Bot.h"
class LeastTileBot :
	public Bot
{
	virtual int getNextTileReq(const std::array<std::array<int, 6>, 7> & grid);
public:
	LeastTileBot(int id, std::string name);
	~LeastTileBot();

	virtual int requestSetTile(const std::array<std::array<int, 6>, 7> & grid);
};

