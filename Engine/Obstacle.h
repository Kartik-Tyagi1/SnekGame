#pragma once

#include "Snake.h"
#include "Board.h"
#include <random>

class Obstacle
{
public:
	void GenerateLocation(std::mt19937& rng, const Board& brd, const Snake& snek);
	void DrawObstacle(Board& brd) const;
	void InitializeObstacle();
	const Location& GetLocation() const;

private:
	static constexpr Color ObstacleColor = Colors::Gray;
	Location ObstacleLoc;

};
