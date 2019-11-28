#pragma once
#include "Player.h"
class User :
	public Player
{
public:
	User(int id, std::string name);
	~User();

	virtual int requestSetTile(const std::array<std::array<int, 6>, 7> & grid);
};

