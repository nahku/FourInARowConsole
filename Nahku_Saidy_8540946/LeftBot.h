#pragma once
#include "Bot.h"
class LeftBot :
	public Bot
{

	virtual int getNextTileReq(const std::array<std::array<int, 6>, 7> & grid);
public:
	LeftBot(int id, std::string name);
	~LeftBot();

	virtual int requestSetTile(const std::array<std::array<int, 6>, 7> & grid);
};

