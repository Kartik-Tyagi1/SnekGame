#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snek)
{
	Respawn(rng, brd, snek);
}

void Goal::Respawn(std::mt19937 &rng, const Board& brd, const Snake& snek)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetBoardWidth());
	std::uniform_int_distribution<int> yDist(0, brd.GetBoardHeight());

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);

	} while (snek.IsOverlapping(newLoc) || !brd.IsInBoard(newLoc));

	GoalLoc = newLoc;
}

void Goal::DrawGoal(Board& brd) const
{
	brd.DrawCell(GoalLoc, GoalColor);
}

const Location& Goal::GetLocation() const
{
	return GoalLoc;
}

const bool Goal::IsOverlapping(const Location& target) const
{
	if (GoalLoc == target)
	{
		return true;
	}

	return false;
}
