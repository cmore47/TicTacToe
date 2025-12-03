#include <iostream>
#include <string>
#include <array>
#include <time.h>
#include "board.hpp"
#include "error.hpp"

using namespace std;

array<int, 2> convertSpace(int space);
int convertSpace(board& b, string rowCol);

// Gets the space the human player inputs.
int getHumanSpace(board& b)
{
	string plrSpaceStr = " ";

	cout << "Enter your space:\n";
	cin >> plrSpaceStr;

	return convertSpace(b, plrSpaceStr);
}

// Generates the computer players space.
int getComSpace(board& b)
{
	array<int, 2> rowCol{ 0, 0 };
	int randNum = 0;

	srand(static_cast<unsigned int> (time(NULL))); // Sets the rand() seed to the current time for a more random number.

	do
	{
		randNum = rand() % 9 + 1;
		rowCol = convertSpace(randNum);
	} while (b.getSpace(rowCol[0], rowCol[1]) != ' '); // Continue generating a random number until it is not a used space.

	return randNum; // Generate a space from 1-9 and return it.
}

// Converts an int from 1-9 into a row and column number.
array<int, 2> convertSpace(int space)
{
	array<int, 2> rowCol{ 0, 0 }; // Stores the row and column number in that specific order.

	if (space < 4 && space > 0)
		rowCol = { 0, space - 1 };

	else if (space < 7 && space > 0)
		rowCol = { 1, space - 4 };

	else if (space < 10 && space > 0)
		rowCol = { 2, space - 7 };

	else
		rowCol = { -1, -1 }; // Return all -1's to show that the user did not input a valid value.

	return rowCol;
}

// Converts a string with the board cordinates into an integer.
int convertSpace(board& b, string rowCol)
{
	string row = " ", col = " ";
	int colNum = 0;

	row = rowCol[0]; // Get the row letter from the string.
	col = rowCol[1]; // Get the column number from the string.

	try
	{
		colNum = stoi(col); // Convert the column string into a int.
	}

	catch (...)
	{
		findError(b, -2);
	}

	if (row[0] == 'A' || row[0] == 'a' && colNum < 4 && colNum > 0)
		return colNum; // Return spaces 1-3.

	else if (row[0] == 'B' || row[0] == 'b' && colNum < 4 && colNum > 0)
		return colNum + 3; // Return spaces 4-6.

	else if (row[0] == 'C' || row[0] == 'c' && colNum < 4 && colNum > 0)
		return colNum + 6; // Return spaces 7-9.

	else
		findError(b, -1); // Use the findError function to tell the user they entered an invalid value.

	return -1;
}