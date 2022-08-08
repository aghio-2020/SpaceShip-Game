#include "SpaceShip.h"
#include "Asteroid.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

AST::AST(int px, int py)
{
	x = px; y = py;
}

void AST::collision(SpaceShip &N)
{
	if (x >= N.X() && x < N.X()+5 && y > N.Y() && y <= N.Y()+2) 
	{
		N.COR();
		N.erase();
		N.paint();
		N.paint_hearts();
		x = 4 + rand() % 73;
		y = 4;
	}
}

void AST::paint()
{
	gotoXY(x, y); printf("%c", 184);
}

void AST::move()
{
	gotoXY(x, y); printf(" ");
	y++;
	if (y > 32) {
		x = 4 + rand() % 73;
		y = 4;
	}
	paint();
}