#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
   int canal1[2];
   int canal2[2];
   pid_t pid1, pid2;

   int y,z;   

   if ( pipe(canal1) == -1 ){ printf("Erro pipe()"); return -1; }
   if ( pipe(canal2) == -1 ){ printf("Erro pipe()"); return -1; }

   pid1=fork();
   if ( pid1 == 0 )
   {
	read(canal1[0],&y,sizeof(int));
	printf("Valor recebido pelo Filho1 do Filho2=%d\n",y); fflush(stdout);
	close(canal1[0]);
	y=5;
	write(canal2[1],&y,sizeof(int));
	close(canal2[1]);
   }
   else
   if (pid1 > 0 )
   {
     pid2=fork();
     if ( pid2 == 0 )
     {	
	y=3;
	write(canal1[1],&y,sizeof(int));
	close(canal1[1]);
	read(canal2[0],&y,sizeof(int));
	printf("Valor recebido pelo Filho2 do Filho1=%d\n",y); fflush(stdout);
     }
     else
     if (pid2 > 0 )
     {
	wait(&z);
	wait(&z);
     }		
    } 
 exit(0);
}
