#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx):
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);


	int offset_x = x + BorderWidth + BorderPadding;
	int offset_y = y + BorderWidth + BorderPadding;

	// Shift everything 20 px and the border width and padding down and right so we can draw a border around the board
	gfx.DrawRectDim(loc.x * dimension + offset_x, loc.y * dimension + offset_y, dimension, dimension, c);
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

bool Board::IsInBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width && loc.y >= 0 && loc.y < height;
}

void Board::DrawBorder()
{
	const int left = x;
	const int top = y;
	const int right = left + (BorderWidth + BorderPadding) * 2 + width * dimension; // Addition of left brings back extra dimension lost by pushing the board 20 to the right
	const  int bottom = top + (BorderWidth + BorderPadding) * 2 + height * dimension;

	// Top
	gfx.DrawRect(left, top, right, top + BorderWidth, BorderColor); // + BorderWidth moves the point so we actually draw a rectangle
	// Bottom
	gfx.DrawRect(left, bottom, right, bottom - BorderWidth, BorderColor);
	// Left
	gfx.DrawRect(left, top + BorderWidth, left + BorderWidth, bottom - BorderWidth, BorderColor);
	// Right
	gfx.DrawRect(right - BorderWidth, top + BorderWidth, right, bottom - BorderWidth, BorderColor);
}
