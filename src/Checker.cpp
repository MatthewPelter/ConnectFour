/*
 * Checker.cpp
 *
 *  Created on: Nov 14, 2024
 *      Author: Matthew Pelter
 */

#include "Checker.h"

// Checker constructor. Sets player to symbol. Default is ' '
Checker::Checker(char symbol) :
		player(symbol) {
}

// Return players char (R or B)
char Checker::getPlayer() const {
	return player;
}

// Sets the player char
void Checker::setPlayer(char symbol) {
	player = symbol;
}

// Check if the checker piece is empty / has been set on the board.
bool Checker::isEmpty() const {
	return player == ' ';
}
