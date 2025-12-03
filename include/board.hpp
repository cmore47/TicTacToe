#pragma once
#include <string>
#include <array>

// Stores the various variables to be used across the program.
class board
{
	std::array<std::array<char, 3>, 3> plrSpace{ { {' ', ' ', ' '}, { ' ', ' ', ' ' }, { ' ', ' ', ' '} } }; // Stores X's or O's in a 2d array.
	std::array<std::array<int, 3>, 2> score{ { {0, 0, 0}, {0, 0, 0} } }; // Stores both players score in this format: Win/Loss/Draw
	std::string error = ""; // Contains the error to be told to the user.
	bool contPlaying = true; // This bool tells the game to continue running or to stop.
	bool doSpcAgain = false; // This bool tells the game whether or not to repeat a turn.

public:
	// Replaces whatever value at the index with the value of playerType.
	void addSpace(int row, int column, char playerType);

	// Adds inc to the wins/losses/draws. An wLD value of 0 is wins, 1 is losses, and 2 is draws. Player selects which player the score is for.
	void addScore(int player, int wLD);

	// Replaces the current value of error with err.
	void addError(std::string err);

	// Changes the contPlaying bool to tell the program to continue/stop playing.
	void modContRun(bool val);

	// Changes the doSpcAgain bool to tell the program whether to repeat a turn or not.
	void modDoSpcAgain(bool val);

	// Returns the string that error contains.
	std::string getError();

	// Returns the contPlaying bool.
	bool getContPlay();

	// Returns the doSpcAgain bool.
	bool getDoSpcAgain();

	// Returns what is at the space. This can be a space, X, or O.
	char getSpace(int row, int column);

	// Returns what is at the space. This can be a space, X, or O. It also returns the space with the player color, then resets the color to white.
	std::string getCSpace(int row, int column);

	// Returns the score of one player. A wLD value of 0 is wins, 1 is losses, and 2 is draws.
	int  getScore(int player, int wLD);

	// Clears the error variable with nothing.
	void clearError();

	// Clears plrSpace with spaces.
	void clearSpace();

	// Clears score to all zeros.
	void clearScore();
};