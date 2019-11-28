#pragma once
#include "Bot.h"
class SmartBot :
	public Bot
{
	int m_count_moves;
	int opponentCanWin(const std::array<std::array<int, 6>, 7>& grid);
	int bestChoice(const std::array<std::array<int, 6>, 7>& grid);

	virtual int getNextTileReq(const std::array<std::array<int, 6>, 7> & grid);
public:
	SmartBot(int id, std::string name);
	~SmartBot();

	virtual int requestSetTile(const std::array<std::array<int, 6>, 7> & grid);
};

