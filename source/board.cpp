#include "colors.hpp"
#include "board.hpp"

using namespace std;

// Replaces whatever value at the index with the value of playerType.
void board::addSpace(int row, int column, char playerType)
{
	plrSpace[row][column] = playerType;
}

// Adds one to the wins, losses, or draws. An wLD value of 0 is wins, 1 is losses, and 2 is draws. Player selects which player the score is for.
void board::addScore(int player, int wLD)
{
	score[player][wLD] = score[player][wLD] + 1;
}

// Replaces the current value of error with err.
void board::addError(std::string err)
{
	error = err;
}

// Changes the contPlaying bool to tell the program to stop playing.
void board::modContRun(bool val)
{
	contPlaying = val;
}

void board::modDoSpcAgain(bool val)
{
	doSpcAgain = val;
}

// Returns the string that error contains.
std::string board::getError()
{
	return error;
}

// Returns the contPlaying bool.
bool board::getContPlay()
{
	return contPlaying;
}

bool board::getDoSpcAgain()
{
	return doSpcAgain;
}

// Returns what is at the space. This can be a space, X, or O.
char board::getSpace(int row, int column)
{
	return plrSpace[row][column];
}

// Returns what is at the space. This can be a space, X, or O. It also returns the space with the player color, then resets the color to white.
std::string board::getCSpace(int row, int column)
{
	string space = " ";

	space = plrSpace[row][column];

	if (space == "X")
		return F_B_B + space + F_B_W; // Player X is color blue.

	else if (space == "O")
		return F_B_Y + space + F_B_W; // Player O is color yellow.

	else
		return space; // This returns an empty space.
}

// Returns the score of one player. A wLD value of 0 is wins, 1 is losses, and 2 is draws.
int board::getScore(int player, int wLD)
{
	return score[player][wLD];
}

void board::clearError()
{
	error = "";
}

// Clears plrSpace[] with spaces.
void board::clearSpace()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			plrSpace[i][j] = ' ';
}

// Clears score[] to all zeros.
void board::clearScore()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			score[i][j] = 0;
}