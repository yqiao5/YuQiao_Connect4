#include <iostream>
#include "ConnectFour.h"
using namespace std;

int main()
{
	char input;
	bool isDone = false;
	ConnectFour game;

	while (isDone == false) {
		game.playGame();
		cout << "Would you like to play again? (Y/N) :";
		cin >> input;
		if (input == 'N' || input == 'n') {
			isDone = true;
		}
	}


	system("pause");
	return 0;

}