#include "stdafx.h"
#include "SmartBot.h"
#include <iostream>
#include <random>
#include "Grid.h"


int SmartBot::opponentCanWin(const std::array<std::array<int, 6>, 7>& board)
{

	for (int i = 0; i < 7; i++) { //Prüfe, ob es eine Position auf dem Spielfeld gibt, an der der Gegner gewinnen könnte
		Grid grid = Grid(board);
		grid.setTile(i, 1);
		Game game = Game();
		game.setGrid(grid);
		if (game.checkGameOver() == 1) {
			return i;
		}
	}

	return -1;
}

int SmartBot::bestChoice(const std::array<std::array<int, 6>, 7>& grid)
{
	std::array<std::array<int, 6>, 7> temp = grid;
	int x = 0;
	int y = 0;
	int value_counter = 0;
	int temp_best_column = 0;
	int temp_best_counter = 0;

	temp_best_column = opponentCanWin(grid);

	if (temp_best_column != -1) {
		return temp_best_column;
	}
	else {
		temp_best_column = 0;
	}

	while (x < 7) {	//Evaluiert beste Spalte nach horizontaler Gewinnmöglichkeit
		while (y < 6) {
			if (grid.at(x).at(y) == 2) {
				value_counter++;
			}
			if ((grid.at(x).at(y) != 0) && (grid.at(x).at(y) != getID())) {
				value_counter = 0;
			}
			y++;
		}
		if ( value_counter > temp_best_counter && grid.at(x).at(5) == 0 ) {
			int free_space_counter = 0;
			for (int i = 0; i < 6; i++) {
				if (grid.at(x).at(i)== 0) {
					free_space_counter++;
				}
			}

			if (free_space_counter + value_counter >= 4) { //Prüft, ob genug Platz für eine 4er Reihe nach oben Vorhanden ist
				temp_best_counter = value_counter;
				temp_best_column = x;
			}
		}
		value_counter = 0;
		y = 0;
		x++;
	}

	while (grid.at(temp_best_column).at(5) != 0) { //Falls Spalte voll, prüfe nächste Spalte
		temp_best_column++;
		if (temp_best_column == 6) {
			break;
		}
	}

	return temp_best_column;
}

int SmartBot::getNextTileReq(const std::array<std::array<int, 6>, 7>& grid)
{
	

	if (m_count_moves == 0) {
		m_count_moves++;
		return 3;
	}
	if (m_count_moves == 1) {
		m_count_moves++;
		return 0;
	}
	else {
		m_count_moves++;
		return bestChoice(grid);
	}
	m_count_moves++;
}




SmartBot::SmartBot(int id, std::string name):Bot(id,name)
{
	m_count_moves = 0;
}

SmartBot::~SmartBot()
{
}

int SmartBot::requestSetTile(const std::array<std::array<int, 6>, 7>& grid)
{
	return getNextTileReq(grid);
}
