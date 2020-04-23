// NNCheckers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Classes.cpp"

using namespace std;

template <typename T>
std::vector<T>& operator+=(std::vector<T>& a, const std::vector<T>& b)
{
	a.insert(a.end(), b.begin(), b.end());
	return a;
}

template <typename T>
std::vector<T>& operator+=(std::vector<T>& aVector, const T& aObject)
{
	aVector.push_back(aObject);
	return aVector;
}


//FUNCTIONS DECLARATIONS
vector<int> GiveDiagonals(int x);
vector<Move> GiveMoves(char pieces[32]);
int SingleDiagonal(int, int);
vector<Move> NextJumps(Move, char[32]);

int main()
{
	int test = SingleDiagonal(4, 8);
	cout << test << endl;
	CheckerBoard checkerBoard;
	checkerBoard.initPieces();
	cout << sizeof(checkerBoard.pieces) << endl;
	int test_d = SingleDiagonal(4, 8);
	cout << test_d << endl;
	/*Move test_move(2, 9);
	vector<Move> test_jumps;
	vector<Move> test_jumps = NextJumps(test_move, checkerBoard.pieces);*/

	vector<Move> available_moves = GiveMoves(checkerBoard.pieces);
	
	
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
	if (obstacle_pos != 99) {
		for (int i = 0; i < 4; i++) {
			if (diagonals_1[i] == obstacle_pos && diagonals_2[i] != 99) {
				return diagonals_2[i];
			}
		}
	}	
	return 99;
}
vector<Move> NextJumps(Move jump, char pieces[32]) {
	vector<Move> possible_jumps;
	//int position = jump.positions[0].back();
	//vector<int> diagonals = GiveDiagonals(position);
	//int size = jump.positions[0].size();
	/*for (int d : diagonals) {
		if (d != 99 && pieces[d] != 0 && SingleDiagonal(position, d) != 99) {
			if (d != jump.positions[0][size - 1] && !pieces[SingleDiagonal(position, d)]) {
				possible_jumps.push_back(jump.ActuateJump(SingleDiagonal(position, d), d));
			}			
		}
	}*/
	return possible_jumps;
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
					if (pieces[d] && SingleDiagonal(i, d) != 99) {
						if (!pieces[SingleDiagonal(i, d)]) {
							current_move.ReassignJump(i, SingleDiagonal(i, d), d);
							v_moves.push_back(current_move);
						}						 
					}
				}
			}
		}
	}
	if (v_moves.empty()) {
		for (int i = 0; i < 32; i++) {
			if (pieces[i] == 1) {
				v_dials = GiveDiagonals(i);
				for (int d : v_dials) {
					if (d != 99) {
						if (!pieces[d]) {
							current_move.ReassignMove(i, d);
							v_moves.push_back(current_move);
						}
					}
				}
			}
		}
		return v_moves;
	}
	else {
		vector<Move>::iterator it_end = v_moves.end();
		for (vector<Move>::iterator it = v_moves.begin(); it != it_end; ++it) {
			if (!NextJumps(*it, pieces).empty()) {
				v_moves += NextJumps(*it, pieces);
				v_moves.erase(it);
			}
			it_end = v_moves.end();
		}
		return v_moves;
	}
}