#include "stdafx.h"
#include "Grid.h"
#include <iostream>



Grid::Grid()
{
	clearGrid();
}

Grid::Grid(const std::array<std::array<int, 6>, 7>& grid)
{
	m_board = grid;
}


Grid::~Grid()
{
	
}

void Grid::clearGrid()
{
	for (std::array<int, 6> & arr : m_board) {
		arr.fill(0);
	}
}

bool Grid::setTile(int column, int playerID)
{
	if (column > 6 || column < 0) {
		return false;
	}
		

	for (int i = 0; i < 6; i++) {
		if (m_board.at(column).at(i) == 0) { //Prüfe, ob freie Position in übergebener Spalte vorhanden
			m_board.at(column).at(i) = playerID;
			return true;
		}
	}

	return false;
}


const std::array<std::array<int, 6>, 7> & Grid::getField() const
{
	return  m_board ;
}

bool Grid::isEmpty()
{
	for (std::array<int, 6> & arr : m_board) {
		for (int value : arr) {
			if (value != 0) {
				return false;
			}
		}
	}

	return true;
}

bool Grid::isFull()
{
	for (std::array<int, 6> & arr : m_board) {
		for (int value : arr) {
			if (value == 0) {
				return false;
			}
		}
	}

	return true;
}
