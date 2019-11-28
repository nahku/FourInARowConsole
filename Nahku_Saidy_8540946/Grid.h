#pragma once
#include <array>
class Grid
{
	friend class testGridBoard_columnOverflow_Test;
	friend class testGridBoard_insertTile_Test;
	friend class testGameVerticalGameOverEvaluatuion_verticalWin;
	friend class testGameHorizontalGameOverEvaluatuion_horizontalWin_Test;
	friend class testGameDiagonalGameOverEvaluatuion_bottomLeftDiagonalWin_Test;
	friend class testGameDiagonalGameOverEvaluatuion_topLeftDiagonalWin_Test;
	friend class testLeftBot_firstColumnFull_Test;
	friend class testLeastTileBot_thirdColumnLeast_Test;
	friend class testRandomBot_gridEmpty_Test;

private:
	static const int m_height = 6;
	static const int m_length = 7;
	std::array<std::array<int, m_height>, m_length> m_board;
public:
	Grid();
	Grid(const std::array<std::array<int, 6>, 7>& grid);
	~Grid();

	void clearGrid();
	bool setTile(int column, int playerID);

	const std::array<std::array<int, 6>, 7> & getField() const;
	bool isEmpty();
	bool isFull();
};

