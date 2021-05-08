#pragma once

void gotoXY(int, int);

class BALA {
public:
	BALA(int, int);
	void mover();
	bool fuera();
	int X() { return x; }
	int Y() { return y; }
private:
	int x, y;
};