#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include "SpaceShip.h"
#include "Asteroid.h"
#include "Bullet.h"

/*Each time you shoot, it creates a Bullet into a List, and deletes it when y == 4*/

Bullet::Bullet(int px, int py)
{
	x = px; y = py;
}

void Bullet::move()
{
	gotoXY(x, y); printf(" ");
	if (y > 4) {
		y--;
		gotoXY(x, y); printf("*");
	}
}

bool Bullet::out()
{
	if (y == 4) 
		return true;
	return false;
}