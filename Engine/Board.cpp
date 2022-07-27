#include "Board.h"

Board::Board(Graphics& gfx):
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, width, height, c);
}

int Board::GetBoardWidth() const
{
	return width;
}

int Board::GetBoardHeight() const
{
	return height;
}

int Board::GetCellDimension()
{
	return dimension;
}

bool Board::IsInBounds(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width && loc.y >= 0 && loc.y < height;
}
