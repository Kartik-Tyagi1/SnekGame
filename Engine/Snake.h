#pragma once

#include "Board.h"

/* This class is the entire snake including all its segments*/
class Snake
{
private:
	/* Class Represents Each Individual Segment of the Snake*/
	class Segment
	{
	public:
		/* Functin to set where the head of the snake starts */
		void InitHead(const Location& loc);
		/* Function to Initalize body color */
		void InitBody();
		/* Function to make segments follow the others as the snake moves */
		void Follow(const Segment& next_seg);
		/* Function to determine how much to move the head segment */
		void MoveSegmentBy(const Location& delta_loc);
		void DrawSegment(Board& brd) const;

		/* This function returns a reference to the location. Not a copy. So it shows the real thing since we are just looking at the value */
		const Location& GetSegmentLocation() const;

	private:
		Location loc;
		Color c;

	};

public:
	Snake(const Location& loc);

	/* Function to determine how much to move the snake */
	void MoveBy(const Location& delta_loc);

	/* Function to grow the snake after it eats the food */
	void Grow();
	void DrawSnake(Board& brd) const;

	/* Get the value of where the head will be next. Used to determine if snake goes out of bounds */
	Location GetNextHeadLocation(const Location& delta_loc) const;

	/* Check if any part of the snake is overlapping itself except the tail */
	bool IsOverlappingExceptEnd(const Location& target);

	/* Check if any part of the snake is overlapping itself */
	bool IsOverlapping(const Location& target) const;

private:
	/* Max segments the snake can have */
	static constexpr int MaxSegments = 100;
	Segment segments[MaxSegments];

	/* Current amount of segments of the snake */
	int nSegments = 1;

	static constexpr Color HeadColor = Colors::Yellow;
	static constexpr Color BodyColor = Colors::Green;

};