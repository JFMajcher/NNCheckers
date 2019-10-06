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
	int move(int index) {
		if (index % 8 >= 0 && index % 8 < 4) {
			if (index % 8 == 0) {
				
			}
		}
	}
	void checkMoves() {
		for (int i = 0; i < 32; i++) {
			copy(pieces[0], pieces[31], piecesCopy[0]);
			if (pieces[i] == 1) {
				if ((i % 8) >= 0 && (i % 8) < 4) {
					if (i % 8 == 0) {
						if ((i + 4) == 0) {
							piecesCopy[i] = 0;
							piecesCopy[i + 1] = 1;
							moves.push_back(piecesCopy);
							copy(pieces[0], pieces[31], piecesCopy[0]);
						}
						else {
							if ((i + 9) == 0) {
								piecesCopy[i] = 0;
								piecesCopy[i + 4] = 0;
								piecesCopy[i + 9] = 1;
								moves.push_back(piecesCopy);
								copy(pieces[0], pieces[31], piecesCopy[0]);
							}
						}
					else {
						if ((i + 4) == 0) {
							piecesCopy[i] = 0;
							piecesCopy[i + 1] = 1;
							moves.push_back(piecesCopy);
							copy(pieces[0], pieces[31], piecesCopy[0]);
						}
						else {
							if ((i + 9) == 0) {
								piecesCopy[i] = 0;
								piecesCopy[i + 4] = 0;
								piecesCopy[i + 9] = 1;
								moves.push_back(piecesCopy);
								copy(pieces[0], pieces[31], piecesCopy[0]);
							}
						}
					}
					}
				}
			}
		}
	}
private:
	char board[8][8];
	char pieces[32];
	char piecesCopy[32];
	vector<char[32]> moves;
};

int main()
{
	CheckerBoard checkerBoard;
	checkerBoard.initPieces();
	checkerBoard.initBoard();
	checkerBoard.printBoard();
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
