/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snek({ 3,3 }),
	delta_loc({ 1,0 }),
	goal(rng, brd, snek)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!IsGameOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0, -1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0, 1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1, 0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1, 0 };
		}



		++snekMoveCounter;
		if (snekMoveCounter >= SnekMovePeriod)
		{
			snekMoveCounter = 0;
			const Location next = snek.GetNextHeadLocation(delta_loc);
			if (!brd.IsInBoard(next) || snek.IsOverlappingExceptEnd(next))
			{
				IsGameOver = true;
			}
			else
			{
				const bool IsEating = (next == goal.GetLocation());
				if (IsEating)
				{
					snek.Grow();
				}
				snek.MoveBy(delta_loc);

				// Only respawn when the snek moves to that goal location so that it doesn't respawn at the same location
				if (IsEating)
				{
					goal.Respawn(rng, brd, snek);
				}

			}
		}
	}

}

void Game::ComposeFrame()
{
	/*std::uniform_int_distribution<int> colorDist(0, 255);
	for (int y = 0; y < brd.GetBoardHeight(); y++)
	{
		for (int x = 0; x < brd.GetBoardWidth(); x++)
		{
			Location loc = { x, y };
			Color c(colorDist(rng), colorDist(rng), colorDist(rng));
			brd.DrawCell(loc, c);
		}
	}*/

	snek.DrawSnake(brd);
	goal.DrawGoal(brd);
	if (IsGameOver)
	{
		SpriteCodex::DrawGameOver(200, 200, gfx);
	}
}
