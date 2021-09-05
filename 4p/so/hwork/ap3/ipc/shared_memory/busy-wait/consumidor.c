#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>


#define MEM_SZ 4096
#define BUFF_SZ MEM_SZ-sizeof(int)

struct shared_area{	
	int num;
	char buffer[BUFF_SZ];
}

main()
{
  	int i;
	key_t key=1234;
	struct shared_area *shared_area_ptr;
	void *shared_memory = (void *)0;
	int shmid;

	shmid = shmget(key,MEM_SZ,0666|IPC_CREAT);
	if ( shmid == -1 )
	{
		printf("shmget falhou\n");
		exit(-1);
	}
	
	printf("shmid=%d\n",shmid);
	
	shared_memory = shmat(shmid,(void*)0,0);
	
	if (shared_memory == (void *) -1 )
	{
		printf("shmat falhou\n");
		exit(-1);
	}
		
	printf("Memoria compartilhada no endereco=%p\n", shared_memory);

	shared_area_ptr = (struct shared_area *) shared_memory;

	shared_area_ptr->num=0;
	for(i=0;i<BUFF_SZ;i++)
		shared_area_ptr->buffer[i]=0;
	
	for(;;)
	{
		if ( shared_area_ptr->num !=  0 )
		{
			for(i=0;i<shared_area_ptr->num;i++)
				printf("%c",shared_area_ptr->buffer[i]);
			printf("\nConsumiu %d bytes\n",i); 
			shared_area_ptr->num=0;
		}	
	}

        exit(0);
}


	
	
