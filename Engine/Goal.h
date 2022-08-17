#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snek);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snek);
	void DrawGoal(Board& brd) const;
	const Location& GetLocation() const;
	const bool IsOverlapping(const Location& target) const;

private:
	static constexpr Color GoalColor = Colors::Red;
	Location GoalLoc;

};
