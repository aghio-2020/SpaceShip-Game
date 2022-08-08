#pragma once

#include <vector>

void gotoXY(int, int);

class SpaceShip {
public:
	SpaceShip(int, int, int, int);
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
	std::vector<char> keylist;

	void log_keys();
};