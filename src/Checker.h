/*
 * Checker.h
 *
 *  Created on: Nov 14, 2024
 *      Author: Matthew Pelter
 */

#ifndef CHECKER_H_
#define CHECKER_H_

class Checker {
private:
	char player;
public:
	Checker(char player);

	char getPlayer() const;

	void setPlayer(char symbol);

	bool isEmpty() const;
};

#endif /* CHECKER_H_ */
