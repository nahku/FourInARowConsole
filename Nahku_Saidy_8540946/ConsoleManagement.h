#pragma once
#include <string>
namespace ConsoleManagement
{
	int readInteger();
	int readInteger(int min, int max);
	long readLong();
	double readDouble();
	std::string readString();
	std::string readString(std::string message);
	int readSaveInteger(std::string message);
	int readSaveInteger(std::string message, int min, int max);
	void printGrid(const std::array<std::array<int, 6>, 7> & grid);
};

