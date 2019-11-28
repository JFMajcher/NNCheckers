// NNCheckers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CheckerBoard {
public:
	void initPieces() {
		for (int i = 0; i < 32; i++) {
			pieces[i] = 0;
		}
		for (int i = 0; i < 12; i++) {
			pieces[i] = -1;
			pieces[31 - i] = 1;
		}
	}
	void initBoard() {
		int i = 0;
		for (int y = 0; y < 8; y++)
			for (int x = 0; x < 8; x++)
			{
				if (((x + y) % 2) == 0)
				{
					board[y][x] = ' ';
				}
				else
				{
					if (pieces[i] == -1) {
						board[y][x] = 'X';
					}
					else if (pieces[i] == 1) {
						board[y][x] = 'O';
					}
					else {
						board[y][x] = '.';
					}
					i++;
				}
			}
	}
	
	void printBoard() {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				cout << board[y][x];
			}
			cout << endl;
		}
	}

private:
	char board[8][8];
	char pieces[32];
	char piecesCopy[32];
	vector<char[32]> moves;
};

class Move : public CheckerBoard {
public:
	int initPos, destPos, jumps;
	vector<int> takenPieces;
	Move(int initP, int destP, int jmps) {
		initPos = initP;
		destPos = destP;
		jumps = jmps;
	}
	int operator [] (int x) {
		if (x == 0) {
			return initPos;
		}
		else if (x == 1) {
			return destPos;
		}
		else if (x == 2) {
			return jumps;
		}
		else {
			return 0;
		}
	}
};

//FUNCTIONS DECLARATIONS
vector<int> GibDiagonals(int x);
vector<Move> GibMoves(char pieces[32]);

int main()
{
	CheckerBoard checkerBoard;
	checkerBoard.initPieces();
	checkerBoard.initBoard();
	checkerBoard.printBoard();
}

//FUNCTIONS DEFINITIONS
vector<int> GibDiagonals(int x) { //returns vector of diagonal indexes in a form (right upper, left upper, right down, left down)
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
			if ((x % 8) == 7) { v_diagonals[0] = 99;}
			else { v_diagonals[0] = x + 5; }
			v_diagonals[1] = x + 4;
		}
		if ((x % 8) == 7) { v_diagonals[2] = 99; }
		else { v_diagonals[2] = x - 3; }
		v_diagonals[3] = x - 4;
	}
	return v_diagonals;
}
vector<Move> GibMoves(char pieces[32]) {
	vector<Move> v_moves;
	Move m_buff(0, 0, 0);
	vector<int> diagonals;
	for (int i = 0; i < 32; i++) {
		if (pieces[i] == 1) {
			diagonals = GibDiagonals(i);
			for (auto d : diagonals) {
				if (d != 99) {
					//rekurencje trzeb trzasn¹æ
				}
			}
		}
	}
	return v_moves;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
