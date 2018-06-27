#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// GeeksforGeeks.org/multithreading-c-2
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp) {
	sleep(5);
	printf("Printing GeeksQuiz from Thread \n");
	return NULL;
}

int main() {
	pthread_t thread_id;
	printf("Before Thread \n");
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	printf("Between Create and Join\n");
	pthread_join(thread_id, NULL);
	printf("After Thread \n");
	exit(0);
}