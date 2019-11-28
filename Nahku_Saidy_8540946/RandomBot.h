#pragma once
#include "Bot.h"
class RandomBot :
	public Bot
{

	virtual int getNextTileReq(const std::array<std::array<int, 6>, 7> & grid);
public:
	RandomBot(int id, std::string name);
	~RandomBot();

	virtual int requestSetTile(const std::array<std::array<int, 6>, 7> & grid);

};

