#pragma once

void gotoXY(int, int);

class Bullet {
public:
	Bullet(int, int);
	void move();
	bool out();
	int X() { return x; }
	int Y() { return y; }
private:
	int x, y;
};