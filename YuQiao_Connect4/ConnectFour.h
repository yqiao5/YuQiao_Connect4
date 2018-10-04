#pragma once
class ConnectFour
{
public:
	ConnectFour();
	void playGame();


private:


	int  getXCoord();

	bool placeMarker(int x, char currentPlayer);

	bool checkForVictory(char currentPlayer);

	char board[6][7];
	void clearBoard();
	void printBoard();

};


