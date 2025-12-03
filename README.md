# TicTacToe
A C++ implementation of the famous TicTacToe game. It includes two game modes, one for playing against a computer player, and another to play against another human player.

## Controls
 - Enter "P" or "p" for player vs player mode, and "C" or "c" for computer vs player mode
 - Enter a row and column number (ex. a1, b3, c1, etc.) to input your space, make sure to include the row (a, b, or c) and column number (1, 2, or 3).
 - Enter "Y" or "y" to continue playing the same mode, or "N" or "n" to quit the program.

## Build
The project only requires a C++ compiler with the C++20 standard to compile. To use the given Makefile, you will need the latest version of g++ and Make. No external libraries or OS specific headers are included, thus it can be compiled for any modern system running Windows, Linux, or MacOS. **Note that The ANSI escape codes for the colors may not work for all terminals!** Please use a terminal that supports these escape codes, otherwise you will see the escape codes in the output. To build the project with the Makefile, run:

 1. `make release`
 2. `make debug`

These build the release binary and debug binary in their respective folders (`bin/release` or `bin/debug`). The debug profile is automatically selected if you just use `make` by itself.

## Demo Video
[![Watch the demo video](https://img.youtube.com/vi/pK-ALHk5zVg/maxresdefault.jpg)](https://youtu.be/pK-ALHk5zVg)
