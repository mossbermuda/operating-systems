README
Dalhousie University - June 27, 2018
CSCI 3120 - Operating Systems
Assignment 2 - Multithreaded Sudoku Solution Checker
Hamza Awan : 	B00638502
Peter Sousa :	B00652064

Contributions:
	Peter - Reading in File and storing it
		Column/Row Validation Check
		
	Hamza - Subgrid Validation
		Pthread Implementation

Program Instructions:
Description
	Program takes a .txt file as an argument. It will exit if no argument is given.
	The .txt file is read and stored in a 2D array (sudokuGrid) which is later 
	accessed during validation. Using threads the program checks whether the rows,
	columns, and sub grids are correct. A function is used to validate all columns, 	another is used to validate all rows, and lastly one is used to check a specific 	sub grid.

To Compile
	using a unix/linux environment run command 
		gcc -o program assign2.c
	
To Run
	run command 
		./program [name of .txt file with sudoku grid]

Output
	program will output the filename that was opened, the sudoku grid that was inside 	it, whether each of the 11 threads validated their portion of the grid, and lastly 	whether the overall solution for the sudoku grid is correct or incorrect