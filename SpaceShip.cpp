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

SHIP::SHIP(int px, int py, int hea, int life)
{
	x = px; y = py; hearts = hea; lifes = life;
}

int SHIP::X() {
	return x;
}

int SHIP::Y() {
	return y;
}

void SHIP::COR() {
	hearts--;
}

void SHIP::paint() //ASCII
{
	gotoXY(x, y); printf("  %c", 111); 
	gotoXY(x, y + 1); printf(" %c%c%c", 174, 178, 175);
	gotoXY(x, y + 2); printf("%c%c %c%c", 60, 223, 223, 62);
}

void SHIP::erase()
{
	gotoXY(x, y); printf("     ");
	gotoXY(x, y + 1); printf("     ");
	gotoXY(x, y + 2); printf("     ");
}

void SHIP::move()
{
	int i = 0;
	//if coordinates aren't in the space of the game, doesnt move
	while (i < 2) {
		if (_kbhit()) { //if a key is pressed (ASCII)
			char key = _getch();
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

void SHIP::paint_hearts()
{
	gotoXY(50, 2); printf("LIFES: %d", lifes);
	gotoXY(64, 2); printf("Health");
	gotoXY(70, 2); printf("      ");
	for (int i = 0; i < hearts; i++) {
		gotoXY(70 + i, 2); printf("%c", 3);
	}
}

int SHIP::die()  //prints an animation of death
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
			return -1;
		hearts = 3;
		paint_hearts();
		paint();
	}
	return 0;
}