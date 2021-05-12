#pragma once

void gotoXY(int, int);

class SHIP {
public:
	SHIP(int, int, int, int);
	void paint();
	void erase();
	void move();
	void paint_hearts();
	int die();
	int X();
	int Y();
	void COR();
private:
	int x;
	int y;
	int hearts;
	int lifes;
};