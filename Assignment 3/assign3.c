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

 int main(int argc, char **argv) {
 	return 0;
 }