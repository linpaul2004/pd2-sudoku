all: Sudoku.o solve.cpp give.cpp
	g++ -o solve Sudoku.o solve.cpp
	g++ -o give Sudoku.o give.cpp
Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -o Sudoku.o
