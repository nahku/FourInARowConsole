#include "stdafx.h"
#include "ConsoleManagement.h"
#include <iostream>
#include <array>

using std::cin;
using std::string;
using std::cout;

int ConsoleManagement::readInteger()
{
	int result = -1;
	cin >> result;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return result;
}

int ConsoleManagement::readInteger(int min, int max)
{
	int input = -1;
	int counter = 0;
	do{
		if (counter > 0) {
			std::cout << "Bitte geben Sie einen Wert zwischen " << min << " und " << max << " ein: \n";
		}
		counter++;
		input = readInteger();
	} while (!(min <= input && max >= input));
	
	return input;
}

long ConsoleManagement::readLong()
{
	long result = -1;
	cin >> result;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return result;
}

double ConsoleManagement::readDouble()
{
	double result = -1;
	cin >> result;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return result;
}

std::string ConsoleManagement::readString()
{
	string line;
	cin >> line;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return line;
}

std::string ConsoleManagement::readString(std::string message)
{
	std::cout << message << std::endl;
	return ConsoleManagement::readString();
}


int ConsoleManagement::readSaveInteger(std::string message)
{
	int result = -1;
	while (result == -1)
	{
		cout << message;
		result = readInteger();
	}
	return result;
}

int ConsoleManagement::readSaveInteger(std::string message, int min, int max)
{

	int input = -1;
	int counter = 0;

	cout << message;

	return readInteger(min,max);
}

void ConsoleManagement::printGrid(const std::array<std::array<int, 6>, 7> & grid) {
	
	for (int i = 5; i >= 0; i--)
	{
		for (int j = 0; j < 7; j++)
		{
			std::cout << grid.at(j).at(i) << " ";
		}
		
		std::cout << "\n";
		
	}
	std::cout << "_____________";
	std::cout << "\n";
	std::cout << "1|2|3|4|5|6|7";
	std::cout << "\n";
}