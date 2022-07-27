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
	bool IsInBoard(const Location& loc) const;

private:
	/* Dimension of each square cell in the board */
	static constexpr int dimension = 20;

	/* 
	* Actual width and hight of the board 
	* This means that there are 40, 20X20 cells across
	* This means that there are 30, 20x20 cells down
	*/
	static constexpr int width = 40;
	static constexpr int height = 30;

	Graphics& gfx;
};