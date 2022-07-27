#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	int GetCellDimension();
	bool IsInBounds(const Location& loc) const;

private:
	/* Dimension of each cell in the board */
	static constexpr int dimension = 20;

	/* Actual width and hight of the board */
	static constexpr int width = 40;
	static constexpr int height = 30;

	Graphics& gfx;
};