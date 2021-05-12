#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include "SpaceShip.h"
#include "Asteroid.h"
#include "Bullet.h"

/*Each time you shoot, it creates a bullet into a List, and deletes it when y == 4*/

BULLET::BULLET(int px, int py)
{
	x = px; y = py;
}

void BULLET::move()
{
	gotoXY(x, y); printf(" ");
	if (y > 4) {
		y--;
		gotoXY(x, y); printf("*");
	}
}

bool BULLET::out()
{
	if (y == 4) 
		return true;
	return false;
}