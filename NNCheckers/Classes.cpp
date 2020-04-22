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
	vector<vector<int>> positions; //positions[0] contains indexes of visited fields, positions[1] indexes of take pieces
	Move() {}
	Move(int init_p, int dest_p) {
		positions[0].push_back(init_p);
		positions[0].push_back(dest_p);
	}

	Move ActuateJump(Move move, int next_position, int taken_piece) {
		Move actuated_jump(move[0][0], move[0][1]);
		actuated_jump[0].push_back(next_position);
		actuated_jump[1].push_back(taken_piece);
		return actuated_jump;
	}
	//czy to tu bêdê potrzebowa³ wskazników?
	vector<int> operator [] (int x) {
		if (x == 0) {
			return positions[0];
		}
		else if (x == 1) {
			return positions[1];
		}
		else {
			return vector<int> (1, 0);
		}
	}
};