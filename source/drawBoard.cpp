#include <sstream>
#include "checkBoard.hpp"
#include "drawBoard.hpp"
#include "getSpace.hpp"
#include "colors.hpp"
#include "error.hpp"

using namespace std;

// Combines the various strings that contribute to the board and stores it in the boardBuffer[].
string drawBoard(board& b, char player, int row, int column)
{
	stringstream playerStr, boardStr, scoreStr, errorStr;
	stringstream invPlr; // The opposite of player. If X is passed in player, invPlr will be O.
	string fullBoard = " ";

	b.clearError(); // Reset this var to not display a previous error.

	if (row == -1 && column == -1)
	{
		findError(b, -1);
		b.modDoSpcAgain(true); // Redo the turn due to an error.
	}

	else if (row == -4 && column == -4) // Error code -4 is to print the board without putting a space on the board. This is used when the game first starts.
		b.modDoSpcAgain(false);

	else
	{
		// Checks if the space is empty. If it is then add the space to the board. If it is not then tell the user.
		if (b.getSpace(row, column) == ' ')
		{
			b.addSpace(row, column, player); // Add the space to the board before assembling the whole board.
			b.modDoSpcAgain(false); // If there was no error, then do not repeat the turn again.
		}

		else
		{
			findError(b, -3); // Use the findError function to tell the user the space is taken.
			b.modDoSpcAgain(true); // Redo the turn due to an error.
		}
	}

	if (player == 'X' && !b.getDoSpcAgain()) // Get the opposite of the player. If the player does need to redo a space, it will just get the player that was passed in the args.
		invPlr << F_B_Y << 'O' << F_B_W;

	else if (player == 'O' && !b.getDoSpcAgain())
		invPlr << F_B_B << 'X' << F_B_W;

	else // If the player does need to redo a space, it will keep the original player.
		if (player == 'X') // Sets the color of the player.
			invPlr << F_B_B << player << F_B_W;
		else
			invPlr << F_B_Y << player << F_B_W;

	checkBoard(b, player); // Check for wins before drawing board.

	playerStr << "Player " << invPlr.str() << "'s turn\n";

	scoreStr << "Score " << F_B_G << "W" << F_B_W << "/" << F_B_R << "L"
		<< F_B_W << "/" << F_B_C << "D" << F_B_W << " (Player " << F_B_B << "X" << F_B_W << " | Player " << F_B_Y << "O" << F_B_W
		<< "): " << F_B_G << b.getScore(0, 0) << F_B_W << '/' << F_B_R << b.getScore(0, 1) << F_B_W << '/' << F_B_C << b.getScore(0, 2) << F_B_W
		<< " | " << F_B_G << b.getScore(1, 0) << F_B_W << '/' << F_B_R << b.getScore(1, 1) << F_B_W << '/' << F_B_C << b.getScore(1, 2) << F_B_W << '\n';

	boardStr << "     " << B_R << "1" << B_DEF << "     " << B_G << "2" << B_DEF << "     " << B_B << "3" << B_DEF << "   \n"
		<< "        |     |     \n"
		<< B_R << "a" << B_DEF << "    " << b.getCSpace(0, 0) << "  |  " << b.getCSpace(0, 1) << "  |  " << b.getCSpace(0, 2) << "  \n"
		<< "   _____|_____|_____\n"
		<< "        |     |     \n"
		<< B_G << "b" << B_DEF << "    " << b.getCSpace(1, 0) << "  |  " << b.getCSpace(1, 1) << "  |  " << b.getCSpace(1, 2) << "   \n"
		<< "   _____|_____|_____\n"
		<< "        |     |     \n"
		<< B_B << "c" << B_DEF << "    " << b.getCSpace(2, 0) << "  |  " << b.getCSpace(2, 1) << "  |  " << b.getCSpace(2, 2) << "  \n"
		<< "        |     |     \n";

	errorStr << F_B_R << b.getError() << F_B_W << '\n';

	fullBoard = playerStr.str() + scoreStr.str() + boardStr.str() + errorStr.str(); // Combine every element of the board to the board buffer.

	return fullBoard; // Return the full board.
}