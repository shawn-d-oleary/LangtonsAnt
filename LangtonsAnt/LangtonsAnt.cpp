// LangtonsAnt.cpp : This file contains the 'main' function. Program execution begins and ends there.
// //////////////////////// //
// Shawn O'Leary 04/07/2022 //
// ///////////////////////////
// Langton's Ant requires input of K which is the number of ant movements performed by the ant.
// All squares on the grid are initially white, but will be flipped to black if the ant moves into that sqaure. 
// When an ant moves into a black square, the square flips back to white.

#include <iostream>
#include <vector>
#include "AntPosition.h"
using namespace std;

int main() {
	int k_moves = 0;
	cout << "Langtons Ant. How many moves (K) would you like?\n";
	cin >> k_moves;
	cout << "K = " << k_moves << endl;

	if (k_moves < 0)
	{
		cout << "Invalid input.\n" << endl;
		return 0;
	}
	if (k_moves == 0)
	{
		cout << "The board of squares is entirely white. The ant has not moved!" << endl;
		return 0;
	}

	cout << "-----------------------------------------" << endl << endl;

	//list of ant positions (based on moves)
	vector<AntPosition*> antPositions;

	//reverse iterator for ant positions 
	//	used to find the last known color of the square coordinates (x,y) based on the ant's most recent visit to that square.
	//	when reverse iterating, if the square coordinators are not found, 
	//	then we know the sqaure color is white based on the initial value as all squares start out as white.
	vector<AntPosition*>::reverse_iterator r_itr;

	//initial ant position
	AntPosition ant(0, 0, 1, true);

	//initialize variables (current ant position)
	int x = ant.x();
	int y = ant.y();
	int direction = ant.direction();
	bool isWhite = ant.squareIsWhite();

	int min_x = 0;
	int min_y = 0;
	int max_x = 0;
	int max_y = 0;

	for (int i = 0;  i < k_moves; i++)
	{
		antPositions.push_back(
			new AntPosition(
				ant.x(),
				ant.y(),
				ant.direction(),
				ant.squareIsWhite()
			)
		);

		//based on ant's direction, update coordinates (x,y)
		ant.Move(x, y, direction);

		//find last known square color by retracing ant movements starting with most recent.
		isWhite = true;
		for (r_itr = antPositions.rbegin(); r_itr != antPositions.rend(); ++r_itr)
		{
			if ((**r_itr).x() == x && (**r_itr).y() == y) {
				isWhite = (**r_itr).squareIsWhite();
				break;
			}
		}

		direction = ant.RotateDirection(isWhite);

		max_x = x > max_x ? x : max_x;
		max_y = y > max_y ? y : max_y;
		min_x = x < min_x ? x : min_x;
		min_y = y < min_y ? y : min_y;
	}

	#pragma region test output

		//cout << "-----------------------------------------" << endl;
		//vector<AntPosition*>::iterator itr;
		//for (itr = antPositions.begin(); itr != antPositions.end(); ++itr)
		//{
		//	cout << (**itr).x() << " | " 
		//		<< (**itr).y() << " | " 
		//		<< (**itr).direction() 
		//		<< " | " << (**itr).squareIsWhite() << endl;
		//}
		//cout << "-----------------------------------------" << endl;
		//cout << "MIN Y = " << min_y << " | " << "MAX Y = " << max_y << endl;
		//cout << "MIN X = " << min_x << " | " << "MAX X = " << max_x << endl;
		//cout << "-----------------------------------------" << endl;

	#pragma endregion

	char squareColor = ' '; // ' ' is white and 'X' is black.

	for (int x = min_x; x <= max_x; x++)
	{
		for (int y = max_y; y >= min_y; y--) {
			for (r_itr = antPositions.rbegin(); r_itr != antPositions.rend(); ++r_itr)
			{
				squareColor = ' ';
				if ((**r_itr).x() == x && (**r_itr).y() == y) {
					if (!(**r_itr).squareIsWhite())
						squareColor = 'X';
					break;
				}
			}

			cout << squareColor;
		}

		cout << endl;
	}

	cout << endl << "-----------------------------------------" << endl;
	cout << "X = black square" << endl;
	cout << "<space> = white square" << endl;

	return 0;
}