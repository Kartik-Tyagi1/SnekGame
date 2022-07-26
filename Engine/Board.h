#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetBoardWidth();
	int GetBoardHeight();
	int GetCellDimension();

private:
	/* Dimension of each cell in the board */
	static constexpr int dimension = 20;

	/* Actual width and hight of the board */
	static constexpr int width = 20;
	static constexpr int height = 20;

	Graphics& gfx;
};