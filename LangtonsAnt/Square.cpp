#include "Square.h"

int Square::x() {
	return _x;
}

int Square::y() {
	return _y;
}

char Square::color() {
	return _color;
}

Square::Square(int x, int y, char color) {
	_x = x;
	_y = y;
	_color = color;
}