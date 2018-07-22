/* assign3.c : 	The Doctor on Night Duty
 * OBJECTIVE:	There exists 1 doctor on duty to treat n patients.
 *				If no patients need treatment the doctor sleeps, else they treat them.
 *				If the doctor is sleeping the patient wakes up the doctor and begins being treated immediately.
 *				If the doctor is busy the patient must take a seat and wait till the doctor is free.
 *				Patients get coffee if they don't need treatment or there aren't enough seats left in the waiting area.
 *				The program uses threads to create the doctor and n patients. Semaphores and mutex locks are used to prevent deadlock.
 * Dalhousie University - July 12, 2018
 * CSCI 3120 - Operating Systems
 * Assignment 3 - The Doctor on Night Duty
 * Hamza Awan : B00638502
 * Peter Sousa:	B00652064
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <pthread.h>
 #include <string.h>

 #define args 3 // Number of arguements should equal 2 with the input file given
 #define coffeeBreak 10 // Max time for a patient's coffee break

 // Idle function for the doctor thread. This is the doctor's initial function and it called when no patients to help 
 void *beginNap() {
 	printf("Doctor Napping...\n");
 	return NULL;
 }

// Function will occur when a patient obtains a lock for the doctor, making the doctor unable to treat other patients or nap until the treatment is complete
 void treatPatient() {

 }

// Function initially called by each patient. Waits for a random amount of time then attempts to seek help from the doctor
 void *getCoffee(void *vargp) {
 	int *myid = (int *)vargp;
 	int breakLength = rand() % coffeeBreak;
 	printf("Patient %d getting coffee for %d seconds\n", *myid, breakLength);
 	sleep(breakLength);
 	printf("Patient %d break over\n", *myid);
 	return NULL;
 }

// Function to be called after patient is finished having coffee. 
// The patient will enter the queue of waiting chairs, if they are first in the queue they will seek treatment when the doctor is available
 void enterWaitingRoom() {
 	
 }

// Patient will obtain a lock for the doctor and will get treatment for some random period of time. Once complete they will return to having coffee.
 void getTreatment() {
 	
 }

 int main(int argc, char **argv) {
 	pthread_t thread;
 	int patientCount;
 	int seatCount;
 	int threadID;
 	char buffer[16];
 	//Check if 2 arguements have been added to the program before continuing
 	if (argc == args) {
 		// Collect and store the inputted argument values
 		strcpy(buffer, argv[1]);
 		patientCount = atoi(buffer);
 		bzero(buffer, 16);
 		strcpy(buffer, argv[2]);
 		seatCount = atoi(buffer);
 		// Continue if values for patient and seat count are valid
 		if(patientCount > 0 && seatCount > 0) {
 			// Print argument values
 			printf("Patient Count: %d\nSeat Count: %d\n", patientCount, seatCount);

 			//Initalize Doctor pthread
 			pthread_create(&thread, NULL, beginNap, (void *)&threadID);
 			

 			//Initalize Patient Threads
 			for (threadID = 0; threadID < patientCount; threadID++) {
 				pthread_create(&thread, NULL, getCoffee, (void *)&threadID);
 				pthread_join(thread, NULL);
 			}

 			pthread_exit(NULL);

 		}
 		else {
 			printf("ERROR\nInclude 2 arguements when running program\nArgument 1 - Patient Count (Integer)\nArguement 2 - Seat Count (Integer)\n");
 		}
 	}
 	else {
 		printf("ERROR\nInclude 2 arguements when running program\nArgument 1 - Patient Count (Integer)\nArguement 2 - Seat Count (Integer)\n");
 	}

 	return 0;
 }