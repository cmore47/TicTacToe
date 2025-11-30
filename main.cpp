#include <iostream>
#include "drawBoard.hpp"
#include "getSpace.hpp"
#include "colors.hpp"
#include "board.hpp"

using namespace std;

// Tells the user if they want to play again and returns the associated bool.
bool contToPlay(board& b);

// Outputs ANSI escape codes to erase the console and reset the cursor to the begining of the console.
void clearConsole();

int main()
{
	board b;
	array<int, 2> plrOne = { 0, 0 }, plrTwo = { 0, 0 }; // Index 0 is row number and index 1 is the column number.
	bool runAgain = true;
	char userIn = ' ';

	cout << F_B_C << "------Tic Tac Toe " << F_B_W << "v1.0.0" << F_B_C << "------\n"
		<< F_B_W << "Enter (" << F_B_Y << "C" << F_B_W << ") to play against a computer | Enter(" << F_B_B << "P" << F_B_W
		<< ") to play against another human\n";
	cin >> userIn;

	while (runAgain)
	{
		if (userIn == 'C' || userIn == 'c')
		{
			clearConsole();
			cout << "a(1-3) is spaces 1-3 | b(1-3) is spaces 4-6 | c(1-3) is spaces 7-9 | ex. a2 is space 2\n";
			cout << drawBoard(b, 'O', -4, -4); // Error code -4 makes drawBoard return the board without adding a space. This is used to start the game.

			while (b.getContPlay())
			{
				do
				{
					plrOne = convertSpace(getHumanSpace(b));
					clearConsole();
					cout << drawBoard(b, 'X', plrOne[0], plrOne[1]);
				} while (b.getDoSpcAgain()); // Continue repeating the turn so long as there is an error.

				if (b.getContPlay()) // If player X wins, player O will not get to input a space before the game ends.
				{
					do
					{
						plrTwo = convertSpace(getComSpace(b));
						clearConsole();
						cout << drawBoard(b, 'O', plrTwo[0], plrTwo[1]);
					} while (b.getDoSpcAgain()); // Continue repeating the turn so long as there is an error.
				}

				else
					continue;
			}

			runAgain = contToPlay(b);
		}

		else if (userIn == 'P' || userIn == 'p')
		{
			clearConsole();
			cout << "a(1-3) is spaces 1-3 | b(1-3) is spaces 4-6 | c(1-3) is spaces 7-9 | ex. a2 is space 2\n";
			cout << drawBoard(b, 'O', -4, -4); // Error code -4 makes drawBoard return the board without adding a space. This is used to start the game.

			while (b.getContPlay())
			{
				do
				{
					plrOne = convertSpace(getHumanSpace(b));
					clearConsole();
					cout << drawBoard(b, 'X', plrOne[0], plrOne[1]);
				} while (b.getDoSpcAgain()); // Continue repeating the turn so long as there is an error.

				if (b.getContPlay()) // If player X wins, player O will not get to input a space before the game ends.
				{
					do
					{
						plrTwo = convertSpace(getHumanSpace(b));
						clearConsole();
						cout << drawBoard(b, 'O', plrTwo[0], plrTwo[1]);
					} while (b.getDoSpcAgain()); // Continue repeating the turn so long as there is an error.
				}

				else
					continue;
			}

			runAgain = contToPlay(b);
		}

		else
		{
			clearConsole();
			cout << F_B_R << "That's not C or P!\n" << F_B_W << "Enter (" << F_B_Y << "C" << F_B_W
				<< ") to play against a computer, or enter (" << F_B_B << "P" << F_B_W << ") to play against another human!\n";
			cin >> userIn; // First, tell the user that the inputted value is invalid. Then, get the mode again.
		}
	}

	return EXIT_SUCCESS;
}

// Tells the user if they want to play again and returns the associated bool.
bool contToPlay(board& b)
{
	char userIn = ' ';

	cout << "Do you want to play again? (" << F_B_G << "y" << F_B_W << "|" << F_B_R
		<< "n" << F_B_W << ")\n"; // Ask the user if they want to play again after finishing a game.
	cin >> userIn;

	if (userIn == 'Y' || userIn == 'y')
	{
		b.modContRun(true);
		b.clearSpace(); // Clear the board to start a new game.
		return true;
	}

	else if (userIn == 'N' || userIn == 'n')
		return false;

	else
		cout << F_B_R << "I did not get that!\n" << F_B_W;

	return true;
}

// Outputs ANSI escape codes to erase the entire screen and reset the cursor to the begining of the console.
void clearConsole()
{
	cout << "\x1B[2J\x1B[H"; // From https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
}