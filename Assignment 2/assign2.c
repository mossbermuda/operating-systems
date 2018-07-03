/* assign1.c : 	Multithreaded Sudoku Solution Checker
 * OBJECTIVE:	Read in a user file as input. Use 1 thread to check that each column contains digits 1 through 9.
 *				Use 1 thread to check that each row contains digits 1 through 9. Use 9 threads to check that each 3x3 subgrid contains digits 1 through 9
 *				Program uses 11 threads in total.
 * Dalhousie University - June 27, 2018
 * CSCI 3120 - Operating Systems
 * Assignment 2 - Multithreaded Sudoku Solution Checker
 * Hamza Awan : B00638502
 * Peter Sousa:	B00652064
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <pthread.h>

 #define args 2 // Number of arguements should equal 2 with the input file given
 #define threadCount 11 // Number of threads

// structure for passing data to threads
 typedef struct {
 	int row;
 	int column;
 } parameters;

// stores the results of each validity test performed by each thread, corresponds to thread id
 int results[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
// default solution equals 1 (correct), 0 otherwise
 int solution = 1;

 int main(int argc, char **argv) {
 	pthread_t thread;
 	//Check if an arguement has been added to the program before continuing
 	if (argc == args) {
 		printf("Checking Solution...\n");
 		// Complete step 1 - 2 without threads
 		// STEP 1: read in file

 		// STEP 2: create thread to check columns validity
 		// STEP 3: create thread to check row validity
 		// STEP 4: create 9 threads to check each of the 9 subgrids for validity


 		// STEP 5: print results
 		// parent thread checks results to see if the solution is correct
 		for (int i = 0; i < threadCount; i++) {
 			// if not equal to 1 then invalid section found, therefore solution incorrect
 			if(results[i] != 1) {
 				solution = 0;
 				printf("Thread - %d found an error\n", i);
 			}
 		}
 		if(solution == 1) {
 			printf("Correct Solution\n");
 		}
 		else {
 			printf("Incorrect Solution \n");
 		}
 	}
 	else {
 		printf("Include file as input argument\n");
 	}

 	return 0;
 }