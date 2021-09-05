#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */


/* prototype for thread routine */
void* handler ( void *ptr );

long int counter; /* shared variable */

int main()
{
    int j, cont=0; /* argument to threads */
    pthread_t threads[10];
    do{
       cont++;
       counter=0;   
       for(j=0;j<10;j++)
       {    
           pthread_create (&threads[j], NULL, handler, NULL);
       }
       for(j=0;j<10;j++)
          pthread_join(threads[j], NULL);

    }while ( counter == 10);
	
    printf("Counter Value: %d  CONT=%d\n", counter, cont);              
    exit(0);
} 



void* handler ( void *ptr )
{
    int x, i; 
    counter=counter+1;
    pthread_exit(0); /* exit thread */
}

