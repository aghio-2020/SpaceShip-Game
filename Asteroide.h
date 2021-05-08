#pragma once

void gotoXY(int, int);

class AST {
public:
	AST(int, int);
	void pintar();
	void mover();
	void choque(class NAVE&);
	int X() { return x; }
	void cambiaX(int _x) { x = _x; }
	int Y() { return y; }
	void cambiaY(int _y) { y = _y; }
private:
	int x, y;
};