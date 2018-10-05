#include "ConnectFour.h"
#include <iostream>

using namespace std;

void ConnectFour::playGame()
{
	clearBoard();
	char player1 = 'X';
	char player2 = 'O';

	char currentPlayer = 'X';
	bool isDone = false;

	int x;

	int turn = 0;

	while (isDone == false) {
		printBoard();
		x = getXCoord();


		if (placeMarker(x, currentPlayer) == false) {
			cout << "This column is occupied!\n";
		}
		else {
			turn++;
			if (checkForVictory(currentPlayer) == true) {
				cout << "The game is over! Player" << currentPlayer << " has won!\n";
				isDone = true;
			}
			else if (turn == 42) {
				cout << "It's a tie!\n";
				isDone = true;
			}

			// Switch player
			if (currentPlayer == player1) {
				currentPlayer = player2;
			}
			else {
				currentPlayer = player1;
			}

		};
	}
	printBoard();
}


ConnectFour::ConnectFour()
{
}


int ConnectFour::getXCoord()
{
	bool isInputBad = true;
	int num;

	cout << "Choose a column to drop your piece:";
	cin >> num;

	// check if the input is an integer
	while (!cin.good()) {

		cout << "Invalid Input! \n";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> num;
	}


    //check if the number is inside the range
	while (isInputBad == true) {
		if (num < 1 || num>7) {
			cout << "Invalid Input!\n";
		}
		else {
			isInputBad = false;
		}
	}

	return num - 1;
}


bool ConnectFour::placeMarker(int x, char currentPlayer)
{
	if (x >= 0 && x <= 6) {
		if (board[0][x] == '.') {
			int i;
			for (i = 0; board[i][x] == '.'; i++)

				if (i == 5) {
					board[i][x] = currentPlayer;
					return i;
				}
			i--;
			board[i][x] = currentPlayer;
			return i;
		}
		
		else {
			return false;
		}
	}
}

bool ConnectFour::checkForVictory(char currentPlayer)
{
	//check the rows
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == currentPlayer && (board[i][j] == board[i][j + 1]) && (board[i][j + 1] == board[i][j + 2]) && (board[i][j + 2] == board[i][j + 3])) {
				return true;
			}
		}
	}

	//check the columns
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 3; i++) {
			if (board[i][j] == currentPlayer && (board[i][j] == board[i + 1][j]) && (board[i + 1][j] == board[i + 2][j]) && (board[i + 2][j] == board[i + 3][j])) {
				return true;
			}
		}
	}

	//check top left diagonal
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == currentPlayer && (board[i][j] == board[i + 1][j + 1]) && (board[i + 1][j + 1] == board[i + 2][j + 2]) && (board[i + 2][j + 2] == board[i + 3][j + 3])) {
				return true;
			}
		}
	}


	//check top right digonal
	for (int i = 6; i > 2; i--) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == currentPlayer && (board[i][j] == board[i - 1][j + 1]) && (board[i - 1][j + 1] == board[i - 2][j + 2]) && (board[i - 2][j + 2] == board[i - 3][j + 3])) {
				return true;
			}
		}
	}

	return false;
}


void ConnectFour::clearBoard()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			board[i][j] = '.';
		}
	}
}

void ConnectFour::printBoard() {
	cout << endl;
	cout << " |1 2 3 4 5 6 7|\n";
	for (int i = 0; i < 6; i++) {
		cout << "-----------------\n";
		cout << i + 1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|" << board[i][3] << "|" << board[i][4] << "|" << board[i][5] << "|" << board[i][6] << "|\n";
	};

}
