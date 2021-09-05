#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
   int canal[2];
   pid_t pid;

   int   a, z;
   char  b;

   if ( pipe(canal) == -1 ){ printf("Erro pipe()"); return -1; }

   pid=fork();
   
   if ( pid == 0 )
   {
	read(canal[0],&a,sizeof(int));
	read(canal[0],&b,sizeof(char));

	printf("Valores recebidos pelo Filho do Pai\n"); 
	printf("A=%d\nB=%c\n",a,b);
	fflush(stdout);
	close(canal[0]);
	exit(0);
   }
   else
   if (pid > 0 )
   {
	a=1;
	b='@';

	write(canal[1],&b,sizeof(char));
	write(canal[1],&a,sizeof(int));
	close(canal[1]);

	wait(&z);

	exit(0);
   }
}
