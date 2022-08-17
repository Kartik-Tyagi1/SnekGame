#pragma once

#include "Snake.h"
#include "Board.h"
#include "Goal.h"
#include <random>

class Obstacle
{
public:
	void GenerateLocation(std::mt19937& rng, const Board& brd, const Snake& snek, const Goal& goal);
	void DrawObstacle(Board& brd) const;
	void InitializeObstacle();
	const Location& GetLocation() const;
	const bool IsOverlapping(const Location& target) const;

private:
	static constexpr Color ObstacleColor = Colors::Gray;
	Location ObstacleLoc;

};
