#pragma once
class ConnectFour
{
public:
	ConnectFour();
	void playGame();


private:


	int  getXCoord();

	bool placeMarker(int x, char currentPlayer,char player1, char player2);

	bool checkForVictory(char currentPlayer);
	bool checkTie();

	char board[6][7];
	void clearBoard();
	void printBoard();

};


