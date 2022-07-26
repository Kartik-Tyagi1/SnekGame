#pragma once

struct Location
{
	int x;
	int y;

	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
};