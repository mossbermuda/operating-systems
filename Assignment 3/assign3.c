/* assign3.c : 	The Doctor on Night Duty
 * OBJECTIVE:	There exists 1 doctor on duty to treat n patients.
 *				If no patients need treatment the doctor sleeps, else they treat them.
 *				If the doctor is sleeping the patient wakes up the doctor and begins being treated immediately.
 *				If the doctor is busy the patient must take a seat and wait till the doctor is free.
 *				Patients get coffee if they don't need treatment or there aren't enough seats left in the waiting area.
 *				The program uses threads to create the doctor and n patients. Mutex locks are used to prevent deadlock and protect resources.
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
 #include <semaphore.h>

 #define args 3 // Number of arguements should equal 2 with the input file given
 #define coffeeBreak 5 // Max time for a patient's coffee break
 #define treatmentTime 7 // Max time for a patient's coffee break

 int patients = 0;
 int finishedFlag = 0;
 int seats = 0;
 int doctorAvailable = 0;
 int doctorTreating = 0;
 pthread_mutex_t mutexPId = PTHREAD_MUTEX_INITIALIZER;
 pthread_mutex_t mutexSeats = PTHREAD_MUTEX_INITIALIZER;
 pthread_mutex_t mutexTreatment = PTHREAD_MUTEX_INITIALIZER;

 void treatPatient();
 void *beginNap();
 void getCoffee(int id);
 void *initPatient();
 void getTreatment(int id);

 
 // Idle function for the doctor thread. This is the doctor's initial function and it called when no patients to help
 // function calls treatPatient() if doctorAvailable flag is changed 
 void *beginNap() {
 	printf("Doctor Sleeping...\n");
 	while (doctorAvailable == 0) {
 		// Sleep
 		// If no more patients to treat exit
 		if(finishedFlag == patients && finishedFlag != 0) {
 			exit(0);
 		}
 	}
 	treatPatient();
 	return NULL;
 }

// Function will occur when a patient obtains a lock for the doctor, making the doctor unable to treat other patients or nap until the treatment is complete
 void treatPatient() {
 	int treatmentLength = rand() % treatmentTime;
 	treatmentLength += 3;
 	pthread_mutex_lock (&mutexSeats);
 	seats++;
 	printf("Doctor treating patient for %d seconds. Seats Left = %d\n", treatmentLength, seats);
 	pthread_mutex_unlock (&mutexSeats);
 	printf("Patient %d getting treated\n", doctorTreating);
 	sleep(treatmentLength);
 	doctorAvailable = 0;
 	doctorTreating = 0;
 	pthread_mutex_unlock (&mutexTreatment);
 	finishedFlag++;
	printf("Patients left: %d\n", (patients - finishedFlag));
 	beginNap();
 }

// Function initially called by each patient. Waits for a random amount of time then attempts to seek help from the doctor
 void *initPatient() {
 	pthread_mutex_lock (&mutexPId);
 	patients++;
 	int id = patients;
 	pthread_mutex_unlock (&mutexPId);
 	int breakLength = rand() % coffeeBreak;
 	breakLength++;
 	printf("\tPatient %d drinking coffee for %d seconds\n", id, breakLength);
 	sleep(breakLength);
 	getTreatment(id);
 	return NULL;
 }

// No more seats available so patient takes another coffee break
 void getCoffee(int id) {
 	int breakLength = rand() % coffeeBreak;
 	breakLength++;
 	printf("\tPatient %d drinking coffee for %d seconds\n", id, breakLength);
 	sleep(breakLength);
 	getTreatment(id);
 }

// Patient Attempts to get treatment
 void getTreatment(int id) {
 	if(seats <= 0) {
 		// no seats left in waiting room
 		printf("\t\t\tPatient %d will try again.\n", id);
 		getCoffee(id);
 	}
 	else {
 		// Get a seat and wait for treatment
 		pthread_mutex_lock (&mutexSeats);
 		if(seats <= 0) {
 			pthread_mutex_unlock (&mutexSeats);
 			getCoffee(id);
 		}
 		else {
 			seats--;
	 		printf("\t\tPatient %d waiting. Seats Left = %d\n", id, seats);
	 		pthread_mutex_unlock (&mutexSeats);
		 	pthread_mutex_lock (&mutexTreatment);
		 	doctorAvailable = 1;
		 	doctorTreating = id;
 		}
 	}
 }

 int main(int argc, char **argv) {
 	pthread_t doctorThread, patientThread;
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
 		seats = seatCount;
 		// Continue if values for patient and seat count are valid
 		if(patientCount > 0 && seatCount > 0) {
 			// Print argument values
 			printf("Patient Count: %d\nSeat Count: %d\n", patientCount, seatCount);

 			//Initalize Doctor pthread
 			pthread_create(&doctorThread, NULL, beginNap, NULL);

 			//Initalize Patient Threads
 			for (threadID = 1; threadID <= patientCount; threadID++) {
 				pthread_create(&patientThread, NULL, initPatient, NULL);
 			}
 			
 			pthread_join(patientThread, NULL);
 			pthread_join(doctorThread, NULL);

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