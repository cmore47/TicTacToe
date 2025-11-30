#pragma once

// Gets the space the human player inputs.
int getHumanSpace(board& b);

// Generates the computer players space.
int getComSpace(board& b);

// Converts an int from 1-9 into a row and column number.
std::array<int, 2> convertSpace(int space);

// Converts a string with the board cordinates into an integer.
int convertSpace(board& b, std::string rowCol);