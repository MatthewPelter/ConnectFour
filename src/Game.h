/*
 * Game.h
 *
 *  Created on: Nov 12, 2024
 *      Author: Matthew Pelter
 */

#ifndef GAME_H_
#define GAME_H_

#include "Board.h"

class Game {
private:
	char player1;
	char player2;
	bool isPlayerOne;
	Board board;
public:
	Game(char p1 = 'R', char p2 = 'B');
	void StartGame();
};

#endif /* GAME_H_ */
