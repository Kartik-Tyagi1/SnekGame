#include "Goal.h"

Goal::Goal(std::mt19937 rng, const Board& brd, const Snake& snek)
{
	Respawn(rng, brd, snek);
}

void Goal::Respawn(std::mt19937 rng, const Board& brd, const Snake& snek)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetBoardWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetBoardHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);

	} while (snek.IsOverlapping(newLoc));

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
