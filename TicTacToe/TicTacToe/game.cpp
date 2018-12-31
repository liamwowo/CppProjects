#include "game.h"

#include <iostream>
#include <ctime>

using namespace std;

Field g_Board[3][3] = { { F_EMPTY, F_EMPTY, F_EMPTY }, { F_EMPTY, F_EMPTY, F_EMPTY }, { F_EMPTY, F_EMPTY, F_EMPTY } };
GameState g_GameState = NOT_STARTED;
Sign g_CurrentPlayer;

bool StartGame() {
	if (g_GameState != NOT_STARTED) {
		return false;
	}
	srand(static_cast<unsigned>(time(NULL)));
	g_CurrentPlayer = (rand() % 2 == 0 ? S_CIRCLE : S_CROSS);
	g_GameState = MOVE;

	return true;
}

bool Move(unsigned uFieldNumber) {
	bool isGameStateProper = g_GameState == MOVE;
	bool isFieldNumberProper = uFieldNumber >= 1 && uFieldNumber <= 9;
	if (!isGameStateProper || !isFieldNumberProper) {
		return false;
	}

	unsigned uY = (uFieldNumber - 1) / 3;
	unsigned uX = (uFieldNumber - 1) % 3;

	if (g_Board[uY][uX] == F_EMPTY) {
		g_Board[uY][uX] = static_cast<Field>(g_CurrentPlayer);
	}
	else {
		return false;
	}
	if (CheckWin()) {
		g_GameState = WON;
	}
	else if(CheckDraw()){
		g_GameState = DRAW;
	}
	else {
		g_CurrentPlayer = g_CurrentPlayer == S_CIRCLE ? S_CROSS : S_CIRCLE;
	}
	return true;
}

bool DrawBoard() {
	if (g_GameState == NOT_STARTED) {
		return false;
	}
	system("cls");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g_Board[i][j] == F_EMPTY) {
				cout << i * 3 + j + 1;
			}
			else {
				cout << static_cast<char>(g_Board[i][j]);
			}
		}
		cout << endl;
	}
	return true;
}

 bool CheckWin() {
	 Field currentPlayerAsField = static_cast<Field>(g_CurrentPlayer);
	 if (g_Board[0][0] == currentPlayerAsField && g_Board[0][1] == currentPlayerAsField && g_Board[0][2] == currentPlayerAsField ||
		 g_Board[1][0] == currentPlayerAsField && g_Board[1][1] == currentPlayerAsField && g_Board[1][2] == currentPlayerAsField||
		 g_Board[2][0] == currentPlayerAsField && g_Board[2][1] == currentPlayerAsField && g_Board[2][2] == currentPlayerAsField||

		 g_Board[0][0] == currentPlayerAsField && g_Board[1][0] == currentPlayerAsField && g_Board[2][0] == currentPlayerAsField||
		 g_Board[0][1] == currentPlayerAsField && g_Board[1][1] == currentPlayerAsField && g_Board[2][1] == currentPlayerAsField||
		 g_Board[0][2] == currentPlayerAsField && g_Board[1][2] == currentPlayerAsField && g_Board[2][2] == currentPlayerAsField||

		 g_Board[0][0] == currentPlayerAsField && g_Board[1][1] == currentPlayerAsField && g_Board[2][2] == currentPlayerAsField||
		 g_Board[2][0] == currentPlayerAsField && g_Board[1][1] == currentPlayerAsField && g_Board[0][2] == currentPlayerAsField) {
		 return true;
	 }
	 return false;
}

 bool CheckDraw() {
	 unsigned uFilledFields = 0;
	 for (int i = 0; i < 3; i++) {
		 for (int j = 0; j < 3; j++) {
			 if (g_Board[i][j] != F_EMPTY) {
				 uFilledFields++;
			 }
		 }
	 }
	 return uFilledFields == 9;
 }