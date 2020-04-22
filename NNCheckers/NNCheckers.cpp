// NNCheckers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Classes.cpp"

using namespace std;



//FUNCTIONS DECLARATIONS
vector<int> GiveDiagonals(int x);
vector<Move> GiveMoves(char pieces[32]);
int SingleDiagonal(int, int);

int main()
{
	int test = SingleDiagonal(4, 8);
	cout << test << endl;
	CheckerBoard checkerBoard;
	checkerBoard.initPieces();
	checkerBoard.initBoard();
	checkerBoard.printBoard();
}

//FUNCTIONS DEFINITIONS
vector<int> GiveDiagonals(int x) { //returns vector of diagonal indexes in a form (right upper, left upper, right down, left down)
	vector<int> v_diagonals(4, 0);
	if ((x % 8) >= 0 && (x % 8) < 4) {
		v_diagonals[0] = x + 4;
		if ((x % 8) == 0) { v_diagonals[1] = 99; }
		else { v_diagonals[1] = x + 3; }
		if (x < 4) { v_diagonals[2] = 99; v_diagonals[3] = 99; }
		else {
			v_diagonals[2] = x - 4;
			if ((x % 8) == 0) { v_diagonals[3] = 99; }
			else { v_diagonals[3] = x - 5; }
		}
	}
	else if ((x % 8) >= 4 && (x % 8) < 8) {
		if (x > 27) { v_diagonals[0] = 99; v_diagonals[1] = 99; }
		else {
			if ((x % 8) == 7) { v_diagonals[0] = 99; }
			else { v_diagonals[0] = x + 5; }
			v_diagonals[1] = x + 4;
		}
		if ((x % 8) == 7) { v_diagonals[2] = 99; }
		else { v_diagonals[2] = x - 3; }
		v_diagonals[3] = x - 4;
	}
	return v_diagonals;
}
int SingleDiagonal(int init_pos, int obstacle_pos) {
	vector<int> diagonals_1 = GiveDiagonals(init_pos);
	vector<int> diagonals_2 = GiveDiagonals(obstacle_pos);
	for (int i = 0; i < 4; i++) {
		if (diagonals_1[i] == obstacle_pos && diagonals_2[i] != 99) {
			return diagonals_2[i];
		}
	}
	return 99;
}
vector<Move> GiveMoves(char pieces[32]) {
	vector<Move> v_moves;
	vector<int> v_dials;
	Move current_move;
	for (int i = 0; i < 32; i++) {
		if (pieces[i] == 1) {
			v_dials = GiveDiagonals(i);
			for (int d : v_dials) {
				if (d != 99) {
					if (pieces[d] && !pieces[SingleDiagonal(i , d)]) {
						Move current_move(i, SingleDiagonal(i, d));
						//v_moves.push_back(current_move); nie da rady tutaj
					}
				}
			}
		}
	}
	return v_moves;
}