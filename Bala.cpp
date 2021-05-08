#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include "Nave.h"
#include "Asteroide.h"
#include "Bala.h"

/*cada vez que se dispara se crea un objeto de BALA y cuando se llega a y = 4 se borra. Usando una Lista ligada*/

BALA::BALA(int px, int py)
{
	x = px; y = py;
}

void BALA::mover()
{
	gotoXY(x, y); printf(" ");
	if (y > 4) {
		y--;
		gotoXY(x, y); printf("*");
	}
}

bool BALA::fuera()
{
	if (y == 4) 
		return true;
	return false;
}