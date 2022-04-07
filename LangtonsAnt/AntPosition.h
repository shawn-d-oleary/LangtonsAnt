#pragma once

class AntPosition
{
private:
	// x coordinate
	int _x;

	// y coordinate
	int _y;

	// direction represented by integer which represents degrees divided by 90. 
	//		0 = 0 degrees, 1 = 90 degrees, 2 = 180 degrees, 3 = 270 degrees, 4 = 360 degrees but will convert back to 0 degrees
	int _direction;

	// square color is white if value is true, else value is false and sqaure color is black.
	bool _squareIsWhite;

public:
	int x();
	int y();
	int direction();
	bool squareIsWhite();

	AntPosition(int x, int y, int direction, bool squareIsWhite);

	void Move(int &x, int &y, int &direction);
	int RotateDirection(bool squareIsWhite);

private:
	int CorrectDirection(int direction);
};