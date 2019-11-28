#pragma once

#include "Grid.h"
#include <memory>

class Player;

class Game
{
	friend class testGameVerticalGameOverEvaluatuion_verticalWin_Test;
	friend class testGameVerticalGameOverEvaluatuion_gridEmpty_Test;
	friend class testGameHorizontalGameOverEvaluatuion_horizontalWin_Test;
	friend class testGameHorizontalGameOverEvaluatuion_gridEmpty_Test;
	friend class testGameDiagonalGameOverEvaluatuion_bottomLeftDiagonalWin_Test;
	friend class testGameDiagonalGameOverEvaluatuion_topLeftDiagonalWin_Test;
	friend class testGameDiagonalGameOverEvaluatuion_gridEmpty_Test;
	friend class testLeftBot_firstColumnFull_Test;
	friend class testLeastTileBot_gridEmpty_Test;
	friend class testLeastTileBot_thirdColumnLeast_Test;
	friend class testRandomBot_gridEmpty_Test;
	friend class testRandomBot_gridFull_Test;
	friend class testSmartBot_winPercentageLeftBot_Test;
	friend class testSmartBot_winPercentageLeastTileBot_Test;
	friend class testSmartBot_winPercentageRandomBot_Test;

private:
	Grid m_grid;

	int checkVerticalGameOver();
	int checkHorizontalGameOver();
	int checkDiagonalGameOver();
public:
	Game();
	~Game();

	void mainMenue();
	void startGameMenue();
	void gameMenue(std::shared_ptr<Player> player_1, std::shared_ptr<Player> player_2);
	void gameOverMenue(std::string winner, int game_over_type);
	void showGrid();
	void setGrid(Grid grid);
	const std::array<std::array<int, 6>, 7> & getGrid() const;
	int checkGameOver();
};

