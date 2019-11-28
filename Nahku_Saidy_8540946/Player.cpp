#include "stdafx.h"
#include "Player.h"
#include <string>
#include <iostream>

Player::Player(int id, std::string name):m_id(id),m_name(name)
{
}

Player::~Player()
{
	
}


const std::string Player::getName()
{
	return m_name;
}

const int Player::getID()
{
	return m_id;
}
