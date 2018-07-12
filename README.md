 *Dalhousie University*\
 *Summer 2018*
# CSCI 3120 - Operating Systems
 **Peter Sousa -  B00652064**\
 **Hamza Awan - B00638502**\
**Description:** Repository intended for work on assignments throughout the semester

## Assignment 2: Multithreaded Sudoku Solution Checker
*Language - C*\
Completed June 27, 2018\
**OBJECTIVE**\
Read in a user file as input. Use 1 thread to check that each column contains digits 1 through 9. Use 1 thread to check that each row contains digits 1 through 9. Use 9 threads to check that each 3x3 subgrid contains digits 1 through 9. The program uses 11 threads in total.

**Description**\
Program takes a .txt file as an argument. It will exit if no argument is given. The .txt file is read and stored in a 2D array (sudokuGrid) which is later accessed during validation. Using threads the program checks whether the rows, columns, and sub grids are correct. A function is used to validate all columns, another is used to validate all rows, and lastly one is used to check a specific 	sub grid.

**To Compile**\
Using a unix/linux environment run command 

    gcc -o program assign2.c
	
**To Run**\
Run command 

    ./program [name of .txt file with sudoku grid]

**Output**\
Program will output the filename that was opened, the sudoku grid that was inside it, whether each of the 11 threads validated their portion of the grid, and lastly whether the overall solution for the sudoku grid is correct or incorrect.

## Assignment 3: The Doctor on Night Duty
*Language - C*\

