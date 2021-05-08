#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "Nave.h"
#include "Asteroide.h"

/*las teclas tienen asociadas todas un  número*/
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

NAVE::NAVE(int px, int py, int cora, int vida)
{
	x = px; y = py; corazones = cora; vidas = vida;
}

int NAVE::X() {
	return x;
}

int NAVE::Y() {
	return y;
}

void NAVE::COR() {
	corazones--;
}

void NAVE::pintar() // la coordenada X es la de la izquierda
{
	gotoXY(x, y); printf("  %c", 111); //ASCII
	gotoXY(x, y + 1); printf(" %c%c%c", 174, 178, 175);
	gotoXY(x, y + 2); printf("%c%c %c%c", 60, 223, 223, 62);
}

void NAVE::borrar()
{
	gotoXY(x, y); printf("     "); //ASCII
	gotoXY(x, y + 1); printf("     ");
	gotoXY(x, y + 2); printf("     ");
}

void NAVE::mover()
{
	int i = 0;
	//si las coordenadas no estan en el campo del juego, no permite hacer el movimiento
	while (i < 2) {
		if (_kbhit()) { //Si se presiona una tecla (ASCII)
			char tecla = _getch();
			borrar(); //borra caracter anterior
			if (tecla == IZQUIERDA && x > 3) x--; //75
			if (tecla == DERECHA && x + 5 < 77) x++; //77
			if (tecla == ARRIBA && y > 4) y--; //72
			if (tecla == ABAJO && y + 3 < 33) y++; //80
			pintar();
			pintar_corazones();
			gotoXY(2, 2); printf("%d  %d", x, y);
		}
		i++;
	}
}

void NAVE::pintar_corazones()
{
	gotoXY(50, 2); printf("VIDAS: %d", vidas);
	gotoXY(64, 2); printf("Salud");
	gotoXY(70, 2); printf("      ");
	for (int i = 0; i < corazones; i++) {
		gotoXY(70 + i, 2); printf("%c", 3);
	}
}

int NAVE::morir()
{
	if (corazones == 0) {
		borrar();
		gotoXY(x, y); printf("  ** ");
		gotoXY(x, y+1); printf(" *** ");
		gotoXY(x, y+2); printf(" **  ");
		Sleep(200);

		borrar();
		gotoXY(x, y); printf("* ***");
		gotoXY(x, y + 1); printf("** **");
		gotoXY(x, y + 2); printf("*** *");
		Sleep(200);
		borrar();

		vidas--;
		if (vidas == 0)
			return -1;
		corazones = 3;
		pintar_corazones();
		pintar();
	}
	return 0;
}