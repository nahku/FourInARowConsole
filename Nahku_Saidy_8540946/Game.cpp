#include "stdafx.h"
#include "Game.h"
#include "Grid.h"
#include "ConsoleManagement.h"
#include "User.h"
#include "LeftBot.h"
#include "LeastTileBot.h"
#include "RandomBot.h"
#include "SmartBot.h"

#include <iostream>
#include <string>
#include <memory>

using std::cout;

int Game::checkVerticalGameOver()
{
	std::array<std::array<int, 6>, 7> board = m_grid.getField();

	for (std::array<int, 6> & arr : board) {
		for (int offset = 0; offset < 3; offset++) {
			bool flag = true;
			int lowestPlayerTile = arr.at(offset);
			if (lowestPlayerTile != 0) {
				for (int i = 1; i < 4; i++) {
					if (lowestPlayerTile != arr.at(offset + i)) {
						flag = false;
						break;
					}
				}
				if (flag == true) {
					return lowestPlayerTile;
				}
			}
		}
	}

	return 0;
}

int Game::checkHorizontalGameOver()
{
	std::array<std::array<int, 6>, 7> board = m_grid.getField();
	for (int column = 0; column < 6; column++)
	{
		for (int offset = 0; offset < 4; offset++)
		{
			bool flag = true;
			int lowestPlayerTile = board.at(offset).at(column);
			if (lowestPlayerTile != 0) {
				for (int i = 1; i < 4; i++)
				{
					if (lowestPlayerTile != board.at(offset + i).at(column)) {
						flag = false;
						break;
					}
				}
				if (flag == true) {
					return lowestPlayerTile;
				}
			}
		}
	}

	return 0;
}

int Game::checkDiagonalGameOver()
{
	std::array<std::array<int, 6>, 7> board = m_grid.getField();
	
	
	for (int offsetHorizontal = 0; offsetHorizontal < 4; offsetHorizontal++)
	{
		for (int offsetVertical = 0; offsetVertical < 3; offsetVertical++)
		{
			bool flag = true;
			int lowestPlayerTile = board.at(offsetHorizontal).at(offsetVertical);
			if (lowestPlayerTile != 0) {
				for (int i = 1; i < 4; i++)
				{
					if (lowestPlayerTile != board.at(offsetHorizontal+i).at(offsetVertical+i)) {
						flag = false;
						break;
					}
				}
				if (flag == true) {
					return lowestPlayerTile;
				}
			}
		}
		
	}

	for (int offsetHorizontal = 3; offsetHorizontal < 7; offsetHorizontal++)
	{
		for (int offsetVertical = 0; offsetVertical < 3; offsetVertical++)
		{
			bool flag = true;
			int lowestPlayerTile = board.at(offsetHorizontal).at(offsetVertical);
			if (lowestPlayerTile != 0) {
				for (int i = 1; i < 4; i++)
				{
					if (lowestPlayerTile != board.at(offsetHorizontal - i).at(offsetVertical + i)) {
						flag = false;
						break;
					}
				}
				if (flag == true && lowestPlayerTile != 0) {
					return lowestPlayerTile;
				}
			}
		}

	}

	return 0;
}



Game::Game()
{

}


Game::~Game()
{
}



void Game::mainMenue()
{
	int choice;

	cout << "Herzlich Willlkommen im Hauptmenue von 4-Gewinnt" << std::endl;

	while (true) {
		cout << "Um ein Spiel zu Starten, geben Sie bitte die 1 ein" << std::endl;
		cout << "Um zu Beenden, geben Sie bitte die 0 ein" << std::endl;
		choice = ConsoleManagement::readInteger(0, 1);

		switch (choice)
		{
		case 0: return;

		case 1: startGameMenue();
			break;
		}
	}
}

void Game::startGameMenue()
{
	int input[2];
	std::shared_ptr<Player>Player1;
	std::shared_ptr<Player>Player2;

	cout << "Herzlich Willlkommen im Spielstart-Menue von 4-Gewinnt" << std::endl;

	for (int i = 1; i < 3; i++) {
		cout << "Wer soll Spieler " << i << " sein: " << std::endl;
		cout << "0: Menschlicher Spieler" << std::endl;
		cout << "1: LeftBot" << std::endl;
		cout << "2: LeastTileBot" << std::endl;
		cout << "3: RandomBot" << std::endl;
		if (i == 2) {
			cout << "4: SmartBot" << std::endl;
			input[i - 1] = ConsoleManagement::readInteger(0, 4);
		}
		else {
			input[i - 1] = ConsoleManagement::readInteger(0, 3);
		}
		

		switch (input[i-1])
		{
		case 0:
			if (i == 1) {
				Player1 = std::shared_ptr<User>(new User(1, ConsoleManagement::readString("Bitte geben Sie einen Namen fuer Spieler 1 ein: ")));
			}
			else {
				Player2 = std::shared_ptr<User>(new User(2, ConsoleManagement::readString("Bitte geben Sie einen Namen fuer Spieler 1 ein: ")));
			}
			break;
		case 1:
			if (i == 1) {
				Player1 = std::shared_ptr<LeftBot>(new LeftBot(1, "LeftBot 1"));
			}
			else {
				Player2 = std::shared_ptr<LeftBot>(new LeftBot(2, "LeftBot 2"));
			}
			break;
		case 2:
			if (i == 1) {
				Player1 = std::shared_ptr<LeastTileBot>(new LeastTileBot(1, "LeastTileBot 1"));;
			}
			else {
				Player2 = std::shared_ptr<LeastTileBot>(new LeastTileBot(2, "LeastTileBot 2"));;
			}
			break;
		case 3:
			if (i == 1) {
				Player1 = std::shared_ptr<RandomBot>(new RandomBot(1, "RandomBot 1"));
			}
			else {
				Player2 = std::shared_ptr<RandomBot>(new RandomBot(2, "RandomBot 2"));
			}
			break;
		case 4:		
				Player2 = std::shared_ptr<SmartBot>(new SmartBot(2, "SmartBot 2"));
		}
	}

	gameMenue(Player1, Player2);
}

void Game::gameMenue(std::shared_ptr<Player> player_1, std::shared_ptr<Player> player_2)
{
	m_grid.clearGrid();
	bool correct;
	int winner;
	ConsoleManagement::printGrid(getGrid());
	while (true) {
		do {
			correct = m_grid.setTile(player_1->requestSetTile(getGrid()), player_1->getID()); //Frage solange nach Position für Spielstein, bis gültig
		} while (!correct);
		
		winner = checkGameOver(); //checkGameOver gibt ID des Gewinners, "0" für keinen Gewinner und "-1" für Unentschieden zurück
		ConsoleManagement::printGrid(getGrid());
		if (winner != 0) {
			gameOverMenue(player_1->getName(), winner); //Nach Zug von Spieler 1 kann nur Spieler 1 gewinnen
			break;
		}

		
		
		do {
			correct = m_grid.setTile(player_2->requestSetTile(getGrid()), player_2->getID());
		} while (!correct);
		
		winner = checkGameOver();
		ConsoleManagement::printGrid(getGrid());
		if (winner != 0) {
			if (winner == -1) {
				gameOverMenue("Unentschieden", -1); //Unentschieden kann nur bei Zug des 2. Spielers geschehen
				break;
			}
			gameOverMenue(player_2->getName(), winner);
			break;
		}

	
	}

}

void Game::gameOverMenue(std::string winner, int game_over_type)
{
	if (game_over_type != -1) {
		ConsoleManagement::printGrid(getGrid());
		cout << winner << " hat gewonnen! Herzlichen Glueckwunsch!" << std::endl;
		cout << "0: Zurueck zum Hauptmenue" << std::endl;
		ConsoleManagement::readInteger(0, 0);
	}

	else {
		cout << "Es gab ein Untentschieden!" << std::endl;
		cout << "0: Zurueck zum Hauptmenue" << std::endl;
		ConsoleManagement::readInteger(0, 0);
	}
}

void Game::showGrid()
{
	ConsoleManagement::printGrid(m_grid.getField());
}

void Game::setGrid(Grid grid)
{
	m_grid = grid;
}

const std::array<std::array<int, 6>, 7> & Game::getGrid() const
{
	return m_grid.getField();
}

int Game::checkGameOver()
{
	int flag; 

	if (m_grid.isEmpty()) {
		return 0;
	}

	flag = checkVerticalGameOver();
	
	if (flag != 0) {
		return flag;
	}

	flag = checkHorizontalGameOver();

	if (flag != 0) {
		return flag;
	}

	flag = checkDiagonalGameOver();

	if (flag != 0) {
		return flag;
	}
	
	if (m_grid.isFull()) {
		return -1;
	}
	

	return 0;
}
