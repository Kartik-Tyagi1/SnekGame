#include "Board.h"

Board::Board(Graphics& gfx):
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, width, height, c);
}

int Board::GetBoardWidth()
{
	return width;
}

int Board::GetBoardHeight()
{
	return height;
}

int Board::GetCellDimension()
{
	return dimension;
}
