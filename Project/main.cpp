#include"Dot.h"
#include "Player.h"
#include<iostream>
using namespace twixt;

int main()
{
	Board board(24);
	Player player("nume", Player::Color::Red);
	board.showBoard();
	player.turn(board);
	board.showBoard();
	return 0;
}
