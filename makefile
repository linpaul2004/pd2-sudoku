solve: Sudoku.o solve.cpp
	g++ -o solve Sudoku.o solve.cpp
Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -o Sudoku.o
