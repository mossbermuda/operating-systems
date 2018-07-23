README
Dalhousie University - July 12, 2018
CSCI 3120 - Operating Systems
Assignment 3 - The Doctor on Night Duty
Hamza Awan : 	B00638502
Peter Sousa :	B00652064

Contributions:
	Peter - main()
		beginNap()
		treatPatient()
		
	Hamza - initPatient()
		getCoffee()
		getTreatment()

Program Instructions:
Description
	The program is intended to mimic a doctors office. Having the number of patients 	being an argument to the program. Patients begin by having a coffee for some 		random amount of time and then attempt to get a seat in the waiting area. If a 		seat is available the patient will then attempt to get control of a mutex lock 		responsible for protecting and controlling the doctor-treatment resource/		functionality. After getting control of the lock it is then released after the 		treatment period has ended, allowing any other patients in the "waiting area" to 	gain access of the doctor's mutex lock. If a seat is unavailable the patient goes 	on another coffee break for some random period of time and attempts to find a seat 	again. As the program runs the state and actions that each thread (the doctor or 	each patient) are performing.
	

To Compile
	using a unix/linux environment run command 
		gcc -o program assign3.c
	
To Run
	The program takes two integer arguments when executed on the command line.
	The 1st argument is the patient count and the 2nd argument is the seat count
	run command 
		./program (INTEGER) (INTEGER)

Output

	Output will display the current state of the program as the doctor treats 		patients, as patients enter the waiting area, and as patients take coffee breaks.
	