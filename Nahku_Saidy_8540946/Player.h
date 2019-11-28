#pragma once
#include <string>
#include "Game.h"

class Player
{
private:
	const std::string m_name;
	const int m_id;
public:
	Player(int id, std::string name);
	~Player();
	virtual int requestSetTile(const std::array<std::array<int, 6>, 7> & grid) = 0;
	const std::string getName();
	const int getID();
	
};

