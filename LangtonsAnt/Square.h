#pragma once

class Square
{
private:
	int _x;
	int _y;
	char _color;

public:
	int x();
	int y();
	char color();

	Square(int x, int y, char color);
};