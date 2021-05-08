#pragma once

void gotoXY(int, int);

class NAVE {
public:
	NAVE(int, int, int, int);
	void pintar();
	void borrar();
	void mover();
	void pintar_corazones();
	int morir();
	int X();
	int Y();
	void COR();
private:
	int x;
	int y;
	int corazones;
	int vidas;
};