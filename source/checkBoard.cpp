#include "checkBoard.hpp"

using namespace std;

// Scans all the rows finding three X's or O's in a horizontal row.
void hRow(board& b, char plr, int plrOne, int plrTwo);

// Scans all the columns to find three X's or O's in a vertical row.
void vRow(board& b, char plr, int plrOne, int plrTwo);

// Scans the whole board to find three X's or O's that are in a diagonal row.
void dRow(board& b, char plr, int plrOne, int plrTwo);

// Scans the whole board to find that all rows are filled to give both players a draw.
void aRow(board& b, char plr, int plrOne, int plrTwo);

// Checks the whole board to determine a win, loss, or draw for each player.
void checkBoard(board& b, char plr)
{
	int plrOne = 0, plrTwo = 0;

	// Figure out who player two is to give them a loss or a draw.
	if (plr == 'X')
	{
		plrOne = 0; // X
		plrTwo = 1; // O
	}

	else
	{
		plrOne = 1; // O
		plrTwo = 0; // X
	}

	// Run all the checking functions.
	hRow(b, plr, plrOne, plrTwo);
	vRow(b, plr, plrOne, plrTwo);
	dRow(b, plr, plrOne, plrTwo);

	if (b.getContPlay() == true)
		aRow(b, plr, plrOne, plrTwo); // If there is already a win, it will not check for a draw.
}

// Scans all the rows finding three X's or O's in a horizontal row.
void hRow(board& b, char plr, int plrOne, int plrTwo)
{
	int numOfPlr = 0;

	for (int i = 0; i < 3; i++)
	{
		numOfPlr = 0; // Reset the var in order to find if they filled one row completely.

		for (int j = 0; j < 3; j++)
		{
			if (b.getSpace(i, j) == plr)
			{
				numOfPlr++;

				if (numOfPlr == 3)
				{
					b.addScore(plrOne, 0);
					b.addScore(plrTwo, 1);
					b.modContRun(false); // End the game.
					break;
				}

				else
					continue;
			}

			else
				continue;
		}

		if (b.getContPlay() == false) // Exits the for loop once there is 3 in a row.
			break;
		else
			continue;
	}
}

// Scans all the columns to find three X's or O's in a vertical row.
void vRow(board& b, char plr, int plrOne, int plrTwo)
{
	int numOfPlr = 0;

	for (int i = 0; i < 3; i++)
	{
		numOfPlr = 0; // Reset the var in order to find if they filled one column completely.

		for (int j = 0; j < 3; j++)
		{
			if (b.getSpace(j, i) == plr)
			{
				numOfPlr++;

				if (numOfPlr == 3)
				{
					b.addScore(plrOne, 0);
					b.addScore(plrTwo, 1);
					b.modContRun(false); // End the game.
					break;
				}

				else
					continue;
			}

			else
				continue;
		}

		if (b.getContPlay() == false) // Exits the for loop once there is 3 in a row.
			break;
		else
			continue;
	}
}

// Scans the whole board to find three X's or O's that are in a diagonal row.
void dRow(board& b, char plr, int plrOne, int plrTwo)
{
	int numOfPlr = 0, numOfDiagPlr = 0;

	for (int i = 0; i < 3; i++)
	{
		if (b.getSpace(i, i) == plr) // Diagonal row from top-left corner to bottom-right corner.
		{
			numOfPlr++;

			if (numOfPlr == 3)
			{
				b.addScore(plrOne, 0);
				b.addScore(plrTwo, 1);
				b.modContRun(false); // End the game.
				break;
			}

			else
				continue;
		}

		else
			continue;
	}

	for (int i = 0, j = 2; i < 3 && j > -1; i++, j--)
	{
		if (b.getSpace(j, i) == plr) // Diagonal row from top-right corner to bottom-left corner.
		{
			numOfDiagPlr++;

			if (numOfDiagPlr == 3)
			{
				b.addScore(plrOne, 0);
				b.addScore(plrTwo, 1);
				b.modContRun(false); // End the game.
				break;
			}

			else
				continue;
		}

		else
			continue;
	}
}

// Scans the whole board to find that all rows are filled to give both players a draw.
void aRow(board& b, char plr, int plrOne, int plrTwo)
{
	int numOfPlr = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (b.getSpace(i, j) != ' ')
			{
				numOfPlr++;

				if (numOfPlr == 9)
				{
					b.addScore(plrOne, 2);
					b.addScore(plrTwo, 2);
					b.modContRun(false); // End the game.
					break;
				}

				else
					continue;
			}

			else
				continue;
		}
	}
}