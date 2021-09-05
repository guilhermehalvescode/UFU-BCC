#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <semaphore.h>  /* Semaphore */


/* prototype for thread routine */
void* handler ( void *ptr );

long int counter, cont=0; /* shared variable */
sem_t mutex;

int main()
{
    int j; /* argument to threads */
    pthread_t threads[10];
    sem_init(&mutex, 0, 1); 
    do{
       cont++;
       counter=0;   
       for(j=0;j<10;j++)
       {    
           pthread_create (&threads[j], NULL, handler, NULL);
       }
       for(j=0;j<10;j++)
          pthread_join(threads[j], NULL);

    }while (counter == 10 && cont < 50000);
	
    sem_destroy(&mutex);	
    printf("Counter Value: %d  CONT=%d\n", counter, cont);              
    exit(0);
} 



void* handler ( void *ptr )
{
    int x, i; 
    sem_wait(&mutex);
   	 counter=counter+1;
    sem_post(&mutex);
    pthread_exit(0); /* exit thread */
}

