#include<stdio.h>
#include<windows.h>
#include<cstdlib>
#include<conio.h>
#include<list>
#include "SpaceShip.h"
#include "Asteroid.h"
#include "Bullet.h"

using namespace std;

void hideCursor();
void limits();
void gotoXY(int, int);

// COULD: make a Game class to monitor all the objects on the inside without having to pass a SpaceShip to asteroid 

int main()
{
	hideCursor();
	limits();
	SpaceShip vessel(30,30, 3, 3);
	vessel.paint();
	vessel.paint_hearts();

	list<AST*> ast;
	list<AST*>::iterator itAst;
	for (int i = 0; i < 4; i++) {
		ast.push_back(new AST(3 + rand() % 75, 4 + rand() % 4));
	}
	list<Bullet*> bullet;
	list<Bullet*>::iterator itBullet;

	int points=0;
	bool game_over = false;
	while (!game_over)
	{
		gotoXY(3, 34); printf("Puntos: %d", points);

		if (_kbhit()) {
			char key = _getch();
			if (key == 'f') {
				bullet.push_back(new Bullet(vessel.X() + 2, vessel.Y() - 1));
			}
		}

		for (itBullet = bullet.begin(); itBullet != bullet.end();) {
			(*itBullet)->move(); //list element access
			if ((*itBullet)->out()) {
				gotoXY((*itBullet)->X(), 4); printf(" ");
				delete(*itBullet);
				itBullet = bullet.erase(itBullet);
			}
			else itBullet++; //if it deletes an element, you don't have to iterate, since it will automatically pointing to the next
		}

		for (itAst = ast.begin(); itAst != ast.end(); itAst++) {
			(*itAst)->move();
			(*itAst)->collision(vessel);
		}

		for (itAst = ast.begin(); itAst != ast.end();itAst++) {
			for (itBullet = bullet.begin(); itBullet != bullet.end();) {
				if ((*itAst)->X() == (*itBullet)->X() && (((*itAst)->Y() == (*itBullet)->Y() + 1) || ((*itAst)->Y() == (*itBullet)->Y())))
				{
					gotoXY((*itBullet)->X(), (*itBullet)->Y()); printf(" ");
					delete(*itBullet);
					itBullet = bullet.erase(itBullet);
					points++;
					gotoXY((*itAst)->X(), (*itAst)->Y()); printf(" ");
					(*itAst)->changeX(3 + rand() % 75);
					(*itAst)->changeY(4);
				}
				else itBullet++; 
			}
		}

		game_over = vessel.die(); //checks if hearts == 0
		vessel.move();
		Sleep(20); //stops the program for 30ms
	}

	printf("\n\n\n\n\n");
	system("PAUSE");

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