#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<list>
using namespace std;
#include "Nave.h"
#include "Asteroide.h"
#include "Bala.h"

void ocultarCursor();
void limites();
void gotoXY(int, int);

int main()
{
	ocultarCursor();
	limites();
	NAVE vessel(30,30, 3, 3);
	vessel.pintar();
	vessel.pintar_corazones();

	list<AST*> A;
	list<AST*>::iterator itA;
	for (int i = 0; i < 4; i++) {
		A.push_back(new AST(3 + rand() % 75, 4 + rand() % 4));
	}
	list<BALA*> B;
	list<BALA*>::iterator it;

	int puntos=0;
	int game_over = 0;
	while (game_over == 0)
	{
		gotoXY(3, 34); printf("Puntos: %d", puntos);

		if (_kbhit()) {
			char tecla = _getch();
			if (tecla == 'f') {
				B.push_back(new BALA(vessel.X() + 2, vessel.Y() - 1));
			}
		}

		for (it = B.begin(); it != B.end();) {
			(*it)->mover(); //acceso a elemento de la lista
			if ((*it)->fuera()) {
				gotoXY((*it)->X(), 4); printf(" ");
				delete(*it);
				it = B.erase(it);
			}
			else it++; //si un elemento se borra no se puede recorrer el siguiente, ya que hay uno menos. sigue en el mismo
		}

		for (itA = A.begin(); itA != A.end(); itA++) {
			(*itA)->mover();
			(*itA)->choque(vessel);
		}

		for (itA = A.begin(); itA != A.end();itA++) {
			for (it = B.begin(); it != B.end();) {
				if ((*itA)->X() == (*it)->X() && (((*itA)->Y() == (*it)->Y() + 1) || ((*itA)->Y() == (*it)->Y())))
				{
					gotoXY((*it)->X(), (*it)->Y()); printf(" ");
					delete(*it);
					it = B.erase(it);
					puntos++;
					gotoXY((*itA)->X(), (*itA)->Y()); printf(" ");
					(*itA)->cambiaX(3 + rand() % 75);
					(*itA)->cambiaY(4);
				}
				else it++; 
			}
		}

		game_over = vessel.morir(); //se fija si corazones == 0
		vessel.mover();
		Sleep(30); //detiene el programa por 30us para no exceder las operaciones del ciclo while
	}

	return 0;
}

void gotoXY(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE); //recuperar identificador de la consola
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos); //identificador, estructura de datos
}

void ocultarCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci; //apariencia del cursor
	cci.dwSize = 50; //tamaño del cursor
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon, &cci); //pòr referencia
}

void limites()
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