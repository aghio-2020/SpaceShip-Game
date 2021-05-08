#include "Nave.h"
#include "Asteroide.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

AST::AST(int px, int py)
{
	x = px; y = py;
}

void AST::choque(class NAVE &N)
{
	if (x >= N.X() && x < N.X()+5 && y > N.Y() && y <= N.Y()+2) 
	{
		N.COR();
		N.borrar();
		N.pintar();
		N.pintar_corazones();
		x = 4 + rand() % 73;
		y = 4;
	}
}

void AST::pintar()
{
	gotoXY(x, y); printf("%c", 184);
}

void AST::mover()
{
	gotoXY(x, y); printf(" ");
	y++;
	if (y > 32) {
		x = 4 + rand() % 73;
		y = 4;
	}
	pintar();
}