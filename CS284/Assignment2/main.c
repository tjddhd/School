/////////////////////////////////////////////////////
// Thomas Dolan
// CS284 
// Sriram Chelleppan
// Assignment 2
/////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

typedef struct 
{
	char* file;
	int num;
} params;
void *thread_routine(void *params);

int main ( int argc, char *argv[] )
{
    if ( argc != 4 ) // argc should be 4(meaning 3 arguments passed) for correct execution
    {
		printf("You did not pass the right amount of arguments\n");
		exit(0);
	}

	//variable declaration and assignment
	pthread_t father, mother, daughter;
	params f, m, d;
	f.file = argv[1];
	m.file = argv[2];
	d.file = argv[3];
	f.num = 1;
	m.num = 2;
	d.num = 3;
	
	//thread creation
	if(pthread_create(&father, NULL, thread_routine,NULL) != 0)
	{
		printf("Error creating father thread\n");
	}
	if(pthread_create(&mother, NULL, thread_routine,NULL) != 0)
	{
		printf("Error creating mother thread\n");
	}
	if(pthread_create(&daughter, NULL, thread_routine,NULL) != 0)
	{
		printf("Error creating daughter thread\n");
	}
	
	//thread joins
	pthread_join(father, NULL);
	pthread_join(mother, NULL);
	pthread_join(daughter, NULL);
	
	exit(0);
}
//thread routines
void *thread_routine(void *params) 
{
}