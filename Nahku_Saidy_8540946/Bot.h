#pragma once
#include "Player.h"
class Bot :
	public Player
{
protected:
	virtual int getNextTileReq(const std::array<std::array<int, 6>, 7> & grid) = 0;
public:
	Bot(int id, std::string name);
	~Bot();
};

