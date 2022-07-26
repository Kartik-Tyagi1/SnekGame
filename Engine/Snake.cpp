#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	// From tail up to segment before the head, follow the segment before
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}

	// Head does not have anything to follow so we move it manually
	segments[0].MoveSegmentBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < MaxSegments)
	{
		segments[nSegments].InitBody();
		nSegments++;
	}
}

void Snake::DrawSnake(Board& brd) const
{
	// Draw each individual segment 
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].DrawSegment(brd);
	}
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::HeadColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::BodyColor;
}

void Snake::Segment::Follow(const Segment& next_seg)
{
	loc = next_seg.loc;
}

void Snake::Segment::MoveSegmentBy(const Location& delta_loc)
{
	// Make sure we are only moving one cell
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);

	loc.Add(delta_loc);
}

void Snake::Segment::DrawSegment(Board& brd) const
{
	brd.DrawCell(loc, c);
}
