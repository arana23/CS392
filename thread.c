//I pledge my honor that I have abided by the Stevens Honor System.
// Aparajita Rana
#include <stdio.h>
#include <pthread.h>

//Inside the program declare a global variable counter with initial value 0
int counter=0;

//given run_thread function
void* run_thread(void * noarg){
	int i = 0;
	for( i = 0; i < 1000000; i++){
		counter++;
	}
	 pthread_exit(NULL);
	return NULL;
}

int main(){
	//Start two child threads with pthread_create()
	pthread_t thread_one;
	pthread_t thread_two;

	pthread_create(&thread_one, NULL, run_thread, NULL);
	pthread_create(&thread_two, NULL, run_thread, NULL);

	//use pthread_join() to wait for the two threads to finish
	pthread_join(thread_one, NULL);
	pthread_join(thread_two, NULL);

	//Print the final value of counter with printf()
	printf("Final counter value: %d\n", counter);
}