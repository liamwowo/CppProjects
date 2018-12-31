#include <iostream>

#include "game.h"

using namespace std;

int main() {
	StartGame();

	while (true) {
		DrawBoard();
		if (g_GameState == MOVE) {
			unsigned selectedField;
			cin >> selectedField;
			Move(selectedField);
		}
		else if (g_GameState == WON || g_GameState == DRAW) {
			break;
		}
	}
	return 0;
}