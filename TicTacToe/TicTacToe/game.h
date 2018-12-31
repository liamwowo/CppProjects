#pragma once

enum Sign { 
	S_CIRCLE = 'O',
	S_CROSS = 'X'
};
enum Field {
	F_EMPTY, 
	F_CIRCLE = S_CIRCLE,
	F_CROSS = S_CROSS 
};
enum GameState { NOT_STARTED, MOVE, WON, DRAW };

extern GameState g_GameState;

bool StartGame();
bool Move(unsigned);
bool DrawBoard();

bool CheckWin();
bool CheckDraw();
