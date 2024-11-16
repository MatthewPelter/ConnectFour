/*
 * Board.cpp
 *
 *  Created on: Nov 12, 2024
 *      Author: Matthew Pelter
 */

#include "Board.h"
#include <iostream>
#include <vector>
using namespace std;

// Board constructor. Set amount of rows and columns. Sets the grid to an empty 2d vector with each spot
// intialized to an empty Checker object denoted by emptySlot.
Board::Board(int r, int c) :
		rows(r), cols(c), emptySlot(' ') {
	grid = vector<vector<Checker>>(r, vector<Checker>(c, emptySlot));
}

// Placer a checker piece
bool Board::placeChecker(int col, char player) {
	// If the column input is out of range or the column is not empty, return
	if (!Board::isValidMove(col))
		return false;

	for (int row = rows - 1; row >= 0; --row) {
		// loop through every row in the column.
		if (grid[row][col - 1].isEmpty()) {
			// using the setPlayer method of the Checker object to set player char (R or B).
			grid[row][col - 1].setPlayer(player);
			return true;
		}
	}

	return false;
}

bool Board::isFull() const {
	for (int col = 0; col < cols; ++col) {
		// Check each piece at the top of the board. If any of them are empty, the board is not full.
		if (grid[0][col].isEmpty())
			return false;
	}

	// If none of the pieces at the top of the board are empty, then the board is full. Return true
	return true;
}

bool Board::isValidMove(int col) const {
	return !((col - 1) < 0 || (col - 1) > (cols - 1));
}

bool Board::isColFull(int col) const {
	for (int row = 0; row < rows; ++row) {
		// Check each piece in the column. If any of them are empty, the column is not full.
		if (grid[row][col - 1].isEmpty())
			return false;
	}

	// If none of the pieces in the column are empty, then the column is full. Return true
	return true;
}

bool Board::checkWin(char player) const {

	// Checks for a horizontal win
	for (int r = 0; r < rows; ++r) {
		// We stop at cols - 3 since checking past that would cause an out of bounds for the vector.
		for (int c = 0; c < cols - 3; ++c) {
			if (grid[r][c].getPlayer() == player
					&& grid[r][c + 1].getPlayer() == player
					&& grid[r][c + 2].getPlayer() == player
					&& grid[r][c + 3].getPlayer() == player)
				return true;
		}
	}

	// Check for vertical win
	for (int r = 0; r < rows - 3; ++r) {
		for (int c = 0; c < cols; ++c) {
			// Check every row in each column to see if 4 checkers line up.
			if (grid[r][c].getPlayer() == player
					&& grid[r + 1][c].getPlayer() == player
					&& grid[r + 2][c].getPlayer() == player
					&& grid[r + 3][c].getPlayer() == player)
				return true;
		}
	}

	// Check for diagonal right win
	for (int r = 0; r < rows - 3; ++r) {
		for (int c = 0; c < cols - 3; ++c) {
			// Check if each piece has 3 more pieces going up 1 and right 1.
			if (grid[r][c].getPlayer() == player
					&& grid[r + 1][c + 1].getPlayer() == player
					&& grid[r + 2][c + 2].getPlayer() == player
					&& grid[r + 3][c + 3].getPlayer() == player)
				return true;
		}
	}

	// Check for diagonal left win
	for (int r = 3; r < rows - 3; ++r) {
		for (int c = 0; c < cols - 3; ++c) {
			if (grid[r][c].getPlayer() == player
					&& grid[r - 1][c + 1].getPlayer() == player
					&& grid[r - 2][c + 2].getPlayer() == player
					&& grid[r - 3][c + 3].getPlayer() == player)
				return true;
		}
	}

	return false;

}

// Prints the board
void Board::print() const {
	cout << "| [1] | [2] | [3] | [4] | [5] | [6] | [7] |" << endl;
	cout << "|-----------------------------------------|" << endl;
	for (int r = 0; r < rows; ++r) {
		cout << "| ";
		for (int c = 0; c < cols; ++c) {
			// Uses getPlayer() to get the char of the Checker object
			cout << "(" << grid[r][c].getPlayer() << ") | ";
		}
		cout << endl;
	}
	cout << "|-----------------------------------------|" << endl;
}
