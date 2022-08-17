#include "Obstacle.h"

void Obstacle::InitializeObstacle()
{
	ObstacleLoc = { 0, 0 };
}

void Obstacle::GenerateLocation(std::mt19937& rng, const Board& brd, const Snake& snek, const Goal& goal)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetBoardWidth());
	std::uniform_int_distribution<int> yDist(0, brd.GetBoardHeight());

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);

	} while (snek.IsOverlapping(newLoc) || !brd.IsInBoard(newLoc) || !goal.IsOverlapping(newLoc));

	ObstacleLoc = newLoc;
}

void Obstacle::DrawObstacle(Board& brd) const
{
	brd.DrawCell(ObstacleLoc, ObstacleColor);
}

const Location& Obstacle::GetLocation() const
{
	return ObstacleLoc;
}

const bool Obstacle::IsOverlapping(const Location& target) const
{
	if (ObstacleLoc == target)
	{
		return true;
	}

	return false;
}
