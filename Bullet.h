#pragma once

void gotoXY(int, int);

class BULLET {
public:
	BULLET(int, int);
	void move();
	bool out();
	int X() { return x; }
	int Y() { return y; }
private:
	int x, y;
};