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
   float c;
   char  d[5];	

   if ( pipe(canal) == -1 ){ printf("Erro pipe()"); return -1; }

   pid=fork();
   
   if ( pid == 0 )
   {
	read(canal[0],&b,sizeof(char));
	read(canal[0],&a,sizeof(int));
	read(canal[0],&c,sizeof(float));
	read(canal[0],d,sizeof(d));

	printf("Valores recebidos pelo Filho do Pai\n"); 
	printf("A=%d\nB=%c\nC=%f\nD=%s\n",a,b,c,d);
	fflush(stdout);
	close(canal[0]);
	exit(0);
   }
   else
   if (pid > 0 )
   {
	a=1;
	b='@';
	c=5.5;
	strcpy(d,"1234");

	write(canal[1],&a,sizeof(int));
	write(canal[1],&b,sizeof(char));
	write(canal[1],&c,sizeof(float));
	write(canal[1],d,sizeof(char)*5);
	close(canal[1]);

	wait(&z);

	exit(0);
   }
}
