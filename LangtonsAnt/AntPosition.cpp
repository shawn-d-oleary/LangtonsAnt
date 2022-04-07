#include "AntPosition.h"

//get x
int AntPosition::x() 
{
	return _x;
}

//get y
int AntPosition::y() 
{
	return _y;
}

//get direction
int AntPosition::direction()
{
	return _direction;
}

//get squareIsWhite
bool AntPosition::squareIsWhite()
{
	return _squareIsWhite;
}

//constructor
AntPosition::AntPosition(int x, int y, int direction, bool squareIsWhite = true)
{
	_x = x;
	_y = y;
	_direction = CorrectDirection(direction);
	_squareIsWhite = squareIsWhite;
}

//move ant to new position (x,y) based on direction.
void AntPosition::Move(int &x, int &y, int &direction) 
{
	_direction = CorrectDirection(direction);

	switch (_direction) {
	case 0:
		y++;
		break;
	case 1:
		x++;
		break;
	case 2:
		y--;
		break;
	case 3:
		x--;
		break;
	default:
		break;
	}

	_x = x;
	_y = y;
}

//rotate ant's direction based on current square color.
int AntPosition::RotateDirection(bool squareIsWhite)
{
	if (squareIsWhite)
		_direction++;
	else
		_direction--;

	_squareIsWhite = !squareIsWhite;

	return _direction;
}

//-----private-----

//ensure direction is between 0 and 3.
int AntPosition::CorrectDirection(int direction) {
	if (direction >= 0)
		return direction % 4;
	else
		return ((direction % 4) + 4) % 4;
}