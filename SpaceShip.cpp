#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "SpaceShip.h"
#include "Asteroid.h"

/*keys asociated to a number*/
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

SpaceShip::SpaceShip(int px, int py, int hea, int life)
{
	x = px; y = py; hearts = hea; lifes = life;
}

int SpaceShip::X() {
	return x;
}

int SpaceShip::Y() {
	return y;
}

void SpaceShip::COR() {
	hearts--;
}

void SpaceShip::paint() //ASCII
{
	gotoXY(x, y); printf("  %c", 111); 
	gotoXY(x, y + 1); printf(" %c%c%c", 174, 178, 175);
	gotoXY(x, y + 2); printf("%c%c %c%c", 60, 223, 223, 62);
}

void SpaceShip::erase()
{
	gotoXY(x, y); printf("     ");
	gotoXY(x, y + 1); printf("     ");
	gotoXY(x, y + 2); printf("     ");
}

void SpaceShip::move()
{
	int i = 0;
	//if coordinates aren't in the space of the game, doesnt move
	while (i < 2) {
		if (_kbhit()) { //if a key is pressed (ASCII)
			char key = _getch();
			keylist.push_back(key);
			erase(); //deletes last character
			if (key == LEFT && x > 3) x--; //75
			if (key == RIGHT && x + 5 < 77) x++; //77
			if (key == UP && y > 4) y--; //72
			if (key == DOWN && y + 3 < 33) y++; //80
			paint();
			paint_hearts();
			gotoXY(2, 2); printf("%d  %d", x, y);
		}
		i++;
	}
}

void SpaceShip::paint_hearts()
{
	gotoXY(50, 2); printf("LIFES: %d", lifes);
	gotoXY(64, 2); printf("Health");
	gotoXY(70, 2); printf("      ");
	for (int i = 0; i < hearts; i++) {
		gotoXY(70 + i, 2); printf("%c", 3);
	}
}

void SpaceShip::log_keys()
{
	for (auto key : keylist)
	{
		printf("%c ", key);
	}
}

int SpaceShip::die()  //prints an animation of death
{
	if (hearts == 0) {
		erase();
		gotoXY(x, y); printf("  ** ");
		gotoXY(x, y+1); printf(" *** ");
		gotoXY(x, y+2); printf(" **  ");
		Sleep(200);

		erase();
		gotoXY(x, y); printf("* ***");
		gotoXY(x, y + 1); printf("** **");
		gotoXY(x, y + 2); printf("*** *");
		Sleep(200);
		erase();

		lifes--;
		if (lifes == 0)
		{
			log_keys();
			return true;
		}
		hearts = 3;
		paint_hearts();
		paint();
	}
	return false;
}