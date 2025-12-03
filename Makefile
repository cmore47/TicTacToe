CC   := g++        # Compiler
XCC  := -std=c++2a # Compiler options
SRC  := source/*.cpp
INC  := include/

# Compiles as debug if no build mode is selected
auto: debug

# Compiles the release build of the program
release:
	${CC} ${SRC} ${XCC} -I ${INC} -o bin/release/tictactoe-release -O2

# Compiles the debug build of the program
debug:
	${CC} ${SRC} ${XCC} -I ${INC} -o bin/debug/tictactoe-debug -Og