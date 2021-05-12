#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<list>
#include "SpaceShip.h"
#include "Asteroid.h"
#include "Bullet.h"

using namespace std;

void hideCursor();
void limits();
void gotoXY(int, int);

int main()
{
	hideCursor();
	limits();
	SHIP vessel(30,30, 3, 3);
	vessel.paint();
	vessel.paint_hearts();

	list<AST*> A;
	list<AST*>::iterator itA;
	for (int i = 0; i < 4; i++) {
		A.push_back(new AST(3 + rand() % 75, 4 + rand() % 4));
	}
	list<BULLET*> B;
	list<BULLET*>::iterator itB;

	int points=0;
	int game_over = 0;
	while (game_over == 0)
	{
		gotoXY(3, 34); printf("Puntos: %d", points);

		if (_kbhit()) {
			char key = _getch();
			if (key == 'f') {
				B.push_back(new BULLET(vessel.X() + 2, vessel.Y() - 1));
			}
		}

		for (itB = B.begin(); itB != B.end();) {
			(*itB)->move(); //list element access
			if ((*itB)->out()) {
				gotoXY((*itB)->X(), 4); printf(" ");
				delete(*itB);
				itB = B.erase(itB);
			}
			else itB++; //if it deletes an element, you don't have to iterate, since it will automatically pointing to the next
		}

		for (itA = A.begin(); itA != A.end(); itA++) {
			(*itA)->move();
			(*itA)->collision(vessel);
		}

		for (itA = A.begin(); itA != A.end();itA++) {
			for (itB = B.begin(); itB != B.end();) {
				if ((*itA)->X() == (*itB)->X() && (((*itA)->Y() == (*itB)->Y() + 1) || ((*itA)->Y() == (*itB)->Y())))
				{
					gotoXY((*itB)->X(), (*itB)->Y()); printf(" ");
					delete(*itB);
					itB = B.erase(itB);
					points++;
					gotoXY((*itA)->X(), (*itA)->Y()); printf(" ");
					(*itA)->changeX(3 + rand() % 75);
					(*itA)->changeY(4);
				}
				else itB++; 
			}
		}

		game_over = vessel.die(); //checks if hearts == 0
		vessel.move();
		Sleep(30); //stops the program for 30ms
	}

	return 0;
}

void gotoXY(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE); //Console identifier
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos); //Identifier, Struct
}

void hideCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci; //Cursor looks
	cci.dwSize = 50; //Cursor size
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon, &cci); //by Reference
}

void limits()
{
	for (int i = 3; i < 78; i++) {
		gotoXY(i, 3); printf("%c", 205);
		gotoXY(i, 33); printf("%c", 205);
	}
	for (int i = 4; i < 33; i++) {
		gotoXY(2, i); printf("%c", 186);
		gotoXY(77, i); printf("%c", 186);
	}

	gotoXY(2, 3); printf("%c", 201);
	gotoXY(2, 33); printf("%c", 200);
	gotoXY(77, 3); printf("%c", 187);
	gotoXY(77, 33); printf("%c", 188);
}