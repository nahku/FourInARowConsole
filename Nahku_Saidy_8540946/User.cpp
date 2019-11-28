#include "stdafx.h"
#include "User.h"
#include "ConsoleManagement.h"


User::User(int id, std::string name):Player(id,name)
{
}


User::~User()
{
}

int User::requestSetTile(const std::array<std::array<int, 6>, 7> & grid)
{
	int choice;
	
	

	std::string msg = ": Bitte waehlen Sie die Reihe, in die Sie einen Stein werfen wollen: ";
	msg.insert(0, getName());

	choice = ConsoleManagement::readSaveInteger(msg, 1, 7);
	return (choice-1);
}