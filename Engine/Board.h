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
	void DrawBorder();

private:
	/* Dimension of each square cell in the board */
	static constexpr int dimension = 20;

	/* 
	* Actual width and hight of the board 
	* This means that there are 25, 20X20 cells across
	* This means that there are 25, 20x20 cells down
	*/
	static constexpr int width = 25;
	static constexpr int height = 25;

	/* Starting position of the board */
	static constexpr int x = 20;
	static constexpr int y = 20;

	/* Border Properties */
	const Color BorderColor = Colors::Blue;
	static constexpr int BorderWidth = 4;   
	static constexpr int BorderPadding = 2;  // Padding between the border and the actual board

	Graphics& gfx;
};