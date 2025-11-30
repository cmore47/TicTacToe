#pragma once
#include "board.hpp"

// Combines the various strings that contribute to the board and stores it in the boardBuffer[].
std::string drawBoard(board& b, char player, int row, int column);