#pragma once

void gotoXY(int, int);

class AST {
public:
	AST(int, int);
	void paint();
	void move();
	void collision(class SHIP &N);
	int X() { return x; }
	void changeX(int _x) { x = _x; }
	int Y() { return y; }
	void changeY(int _y) { y = _y; }
private:
	int x, y;
};