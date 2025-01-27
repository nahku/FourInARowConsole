// TestConnectFour.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "../Nahku_Saidy_8540946/Grid.h"
#include "../Nahku_Saidy_8540946/Game.h"
#include "../Nahku_Saidy_8540946/LeftBot.h"
#include "../Nahku_Saidy_8540946/LeastTileBot.h"
#include "../Nahku_Saidy_8540946/RandomBot.h"
#include "../Nahku_Saidy_8540946/SmartBot.h"
#include "../Nahku_Saidy_8540946/ConsoleManagement.h"

using ::testing::Return;

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	testing::InitGoogleMock(&argc, argv);

	int result = RUN_ALL_TESTS();
	//system("PAUSE");
	return result;
	
}

TEST(testGridBoard, isEmptyByDefault) {
	Grid g = Grid();

	EXPECT_TRUE(g.isEmpty());

}

TEST(testGridBoard, columnOverflow) {
	Grid g = Grid();
	for (size_t i = 0; i < 6; i++)
	{
		g.m_board.at(0).at(i) = 1;
	}

	EXPECT_FALSE(g.setTile(0,1));
	
}

TEST(testGridBoard, columnBorderLeft) {
	Grid g = Grid();

	EXPECT_FALSE(g.setTile(-1, 1));

}

TEST(testGridBoard, columnBorderRight) {
	Grid g = Grid();

	EXPECT_FALSE(g.setTile(8, 1));

}

TEST(testGridBoard, insertTile) {
	Grid g = Grid();
	g.setTile(0,1);

	EXPECT_EQ(1,g.m_board.at(0).at(0));

}

TEST(testGridBoard, isEmpty) {
	Grid g = Grid();

	EXPECT_EQ(g.isEmpty(), true);

}

TEST(testGridBoard, isFull) {
	Grid g = Grid();
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++) {
			g.setTile(i,2);
		}
	}
	EXPECT_EQ(g.isFull(), true);

}

TEST(testGameGameOverEvaluatuion, gridEmpty) {
	Game g = Game();

	EXPECT_EQ(0, g.checkGameOver());

}

TEST(testGameVerticalGameOverEvaluatuion, verticalWin) {
	Game g = Game();

	//EXPECT_EQ(0, g.checkVerticalGameOver());

	for (int i = 0; i < 4; i++)
	{
		g.m_grid.setTile(1, 1);
	}
	
	EXPECT_EQ(1, g.checkVerticalGameOver());

}

TEST(testGameVerticalGameOverEvaluatuion, gridEmpty) {
	Game g = Game();
	EXPECT_EQ(0, g.checkVerticalGameOver());
}

TEST(testGameHorizontalGameOverEvaluatuion, horizontalWin) {
	Game g = Game();

	for (int i = 0; i < 4; i++)
	{
		g.m_grid.m_board.at(i).at(0) = 1;
	}

	EXPECT_EQ(1, g.checkHorizontalGameOver());

}

TEST(testGameHorizontalGameOverEvaluatuion, gridEmpty) {
	Game g = Game();
	EXPECT_EQ(0, g.checkHorizontalGameOver());
}

TEST(testGameDiagonalGameOverEvaluatuion, bottomLeftDiagonalWin) {
	Game g = Game();
	

	for (int i = 0; i < 4; i++)
	{
		g.m_grid.m_board.at(i).at(i) = 1;
	}
	
	EXPECT_EQ(1, g.checkDiagonalGameOver());

}

TEST(testGameDiagonalGameOverEvaluatuion, topLeftDiagonalWin) {
	Game g = Game();


	for (int i = 4; i > 0; i--)
	{
		g.m_grid.m_board.at(i).at(i) = 1;
	}

	EXPECT_EQ(1, g.checkDiagonalGameOver());

}

TEST(testGameDiagonalGameOverEvaluatuion, gridEmpty) {
	Game g = Game();

	EXPECT_EQ(0, g.checkDiagonalGameOver());

}

TEST(testLeftBot, firstColumnFull) {
	Game g = Game();
	LeftBot b = LeftBot(1,"Bot");
	
	for (int i = 0; i < 4; i++)
	{
		g.m_grid.m_board.at(0).at(i) = i%2+1;
	}

	EXPECT_EQ(0, b.requestSetTile(g.getGrid()));

}

TEST(testLeastTileBot, gridEmpty) {
	Game g = Game();
	LeastTileBot b = LeastTileBot(1, "Bot");

	EXPECT_EQ(0, b.requestSetTile(g.getGrid()));

}

TEST(testLeastTileBot, thirdColumnLeast) {
	Game g = Game();
	LeastTileBot b = LeastTileBot(1, "Bot");
	for (int i = 0; i < 7; i++)
	{
		if (i != 2) {
			for (int j = 0; j < 4; j++)
			{
				g.m_grid.m_board.at(i).at(j) = j % 2 + 1;
			}
		}
	}

	EXPECT_EQ(2, b.requestSetTile(g.getGrid()));
}

TEST(testRandomBot, gridEmpty) {
	Game g = Game();
	RandomBot b = RandomBot(1, "Bot");
	
	for (int i = 0; i < 10; i++)
	{
		int result = b.requestSetTile(g.getGrid());

		EXPECT_TRUE(0 <= result && result <= 6);
	}
	
}

TEST(testRandomBot, gridFull) {
	Game g = Game();
	RandomBot b = RandomBot(2, "Bot");
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			g.m_grid.setTile(i,1);
		}
	}

	int result = b.requestSetTile(g.getGrid());

	EXPECT_TRUE(result == -1);

}

TEST(testSmartBot, winPercentageLeftBot) {
	int iterations = 1000;
	int leftWinCounter = 0;
	
	
	bool correct;

	for (int i = 0; i < iterations; i++)
	{
		Game g;
		LeftBot leftBot = LeftBot(1, "left");
		SmartBot smartBot = SmartBot(2, "smart");
		while (true) {
			do {
				correct = g.m_grid.setTile(leftBot.requestSetTile(g.getGrid()), leftBot.getID());
			} while (!correct);

			if (g.checkGameOver() == 1) {
				leftWinCounter++;
				break;
			}

			do {
				correct = g.m_grid.setTile(smartBot.requestSetTile(g.getGrid()), smartBot.getID());
			} while (!correct);

			if (g.checkGameOver() == 2) {

				break;
			}
			
		}
	}
	float f = (float)leftWinCounter / (float)iterations;
	std::cout << "\n";
	std::cout << "Smart gewinnt gegen Left mit Wahscheinlichkeit: " << ((float)1 - f) << std::endl;
	std::cout << "\n";
	EXPECT_TRUE(f < 0.15);
}

TEST(testSmartBot, winPercentageLeastTileBot) {
	int iterations = 1000;
	int leastWinCounter = 0;
	
	bool correct;

	for (int i = 0; i < iterations; i++)
	{
		SmartBot smartBot = SmartBot(2, "smart");
		LeastTileBot leastTileBot = LeastTileBot(1, "least");
		Game g;
		while (true) {
			do {
				correct = g.m_grid.setTile(leastTileBot.requestSetTile(g.getGrid()), leastTileBot.getID());
			} while (!correct);

			if (g.checkGameOver() == 1) {
				leastWinCounter++;
				break;
			}
			
			do {
				correct = g.m_grid.setTile(smartBot.requestSetTile(g.getGrid()), smartBot.getID());
			} while (!correct);

			if (g.checkGameOver() == 2) {
				break;
			}
		}
	}
	float f = (float)leastWinCounter / (float)iterations;
	std::cout << "\n";
	std::cout << "Smart gewinnt gegen LeastTile mit Wahscheinlichkeit: " << ((float)1 - f) << std::endl;
	std::cout << "\n";
	EXPECT_TRUE(f < 0.15);
}

TEST(testSmartBot, winPercentageRandomBot) {
	int iterations = 1000;
	int randomWinCounter = 0;
	

	for (int i = 0; i < iterations; i++)
	{
		SmartBot smartBot = SmartBot(2, "smart");
		RandomBot randomBot = RandomBot(1, "random");
		Game g;
		bool correct;
		while (true) {
			do {
				correct = g.m_grid.setTile(randomBot.requestSetTile(g.getGrid()), randomBot.getID());
			} while (!correct);
			
			if (g.checkGameOver() == 1) {
				randomWinCounter++;
				break;
			}

			do {
				correct = g.m_grid.setTile(smartBot.requestSetTile(g.getGrid()), smartBot.getID());
			} while (!correct);
			if (g.checkGameOver() == 2) {
				break;
			}

			if (g.m_grid.isFull()) {
				break;  
			}
		}
	}

	float f = (float)randomWinCounter / (float)iterations;
	std::cout << "\n";
	std::cout << "Smart gewinnt gegen Random mit Wahscheinlichkeit: " << ((float)1 - f) << std::endl;
	std::cout << "\n";
	

	EXPECT_TRUE(f < 0.15);
}