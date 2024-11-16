/*
 * Game.cpp
 *
 *  Created on: Nov 12, 2024
 *      Author: Matthew Pelter
 */

#include "Game.h"
#include <iostream>
using namespace std;

// Intialize Game with constructor. Set each player pieces as player1 and player2.
// Sets isPlayerOne to true indicating that player1 starts the game
Game::Game(char p1, char p2) :
		player1(p1), player2(p2), isPlayerOne(true), board(6, 7) {
}

// Starts the game
void Game::StartGame() {
	// Input from the user
	char playerCol;
	// Keeps track of how many times the users enter the wrong/unexpected input.
	int misbehave = 1;

	// Game loop
	while (true) {
		// Prints the board
		board.print();

		// Determines who the current player is based on the isPlayerOne flag.
		char currPlayer = isPlayerOne ? player1 : player2;

		// Every 5 improper inputs will display this joke message :).
		if (misbehave % 5 == 0) {
			cout << "Why aren't you following the rules???." << endl;
		}

		cout << "Player " << currPlayer
				<< " moves. Select column [1-7], 'q' to quit: ";
		// Get column to place piece
		cin >> playerCol;

		// Kill the game if player enters 'q'
		if (playerCol == 'q') {
			cout << "Game has been ended." << endl;
			break;
		}

		/*
		 * The reason for playerCol - '0' is because we must convert the char to an int. The char '0' in decimal is 48.
		 * Say the user enters 5: The ascii decimal values subracted would be 53 - 48 getting us 5 which we store in colint.
		 * */
		int colint = playerCol - '0';

		if (!board.isValidMove(colint)) {
			cout << "Invalid column entered. Please try again." << endl;
			cout << "Please enter a number between 1 and 7." << endl;
			misbehave++;
			continue;
		}

		if (board.isColFull(colint)) {
			cout << "Sorry that column is full. Try again." << endl;
			continue;
		}

		// IF the move is valid and the column is not full, place the piece.
		board.placeChecker(colint, currPlayer);

		// Check if the current player is a winner.
		if (board.checkWin(currPlayer)) {
			board.print();
			cout << "CONGRATULATIONS! Player " << currPlayer
					<< " has won! Great job!" << endl;
			break;
		}

		// Check if the board is full. End game.
		if (board.isFull()) {
			board.print();
			cout << "The board is full. The game is a draw." << endl;
			break;
		}

		// invert the flag to allow next player to go.
		isPlayerOne = !isPlayerOne;
	}
}
