#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CheckerBoard {
public:
	char pieces[32];
	
	void initPieces() {
		for (int i = 0; i < 32; i++) {
			this->pieces[i] = 0;
		}
		for (int i = 0; i < 12; i++) {
			this->pieces[i] = - 1;
			this->pieces[31 - i] = 1;
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
	//char pieces[32];
	char piecesCopy[32];
	//vector<char[32]> moves;
};


class Move : public CheckerBoard {
public:
	vector<vector<int>> positions; //positions[0] contains indexes of visited fields, positions[1] indexes of taken pieces
	Move() {}
	Move(int init_p, int dest_p) {
		vector<int> positions1;
		positions1.push_back(init_p);
		positions1.push_back(dest_p);
		positions.push_back(positions1);
		vector<int> takenPieces;
		positions.push_back(takenPieces);
	}
	Move(vector<vector<int>> pos) {
		for (auto vec : pos) {
			positions.push_back(vec);
		}
		//positions = pos;
	}


	void ReassignMove(int position, int destination) {
		this->positions.clear();
		vector<int> positions0;
		positions0.push_back(position);
		positions0.push_back(destination);
		this->positions.push_back(positions0);
	}
	void ReassignJump(int position, int destination, int taken_piece) {
		this->positions.clear();
		vector<int> positions0;
		positions0.push_back(position);
		positions0.push_back(destination);
		this->positions.push_back(positions0);
		vector<int> taken_pieces;
		taken_pieces.push_back(taken_piece);
		this->positions.push_back(taken_pieces);
	}
	Move ActuateJump(int next_position, int taken_piece) {
		Move actuated_jump(this->positions);
		actuated_jump.positions[0].push_back(next_position);
		actuated_jump.positions[1].push_back(taken_piece);
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