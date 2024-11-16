/*
 * Board.h
 *
 *  Created on: Nov 12, 2024
 *      Author: Matthew Pelter
 */
#include "Checker.h"
#include <vector>

#ifndef BOARD_H_
#define BOARD_H_

using namespace std;

class Board {
private:
	vector<vector<Checker>> grid;
	int rows, cols;
	Checker emptySlot;

public:
	Board(int r = 6, int c = 7);
	bool placeChecker(int col, char player);
	bool isFull() const;
	bool isColFull(int col) const;
	bool isValidMove(int col) const;
	bool checkWin(char player) const;
	void print() const;
};

#endif /* BOARD_H_ */
