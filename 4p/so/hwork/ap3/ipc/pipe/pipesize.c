#include <stdio.h>
#include <stdlib.h>

main()
{
	char c=0;
	int fd[2];
	unsigned long i=0;
	pipe(fd);
	
	while (1){
	 if (write(fd[1],&c,1) <= 0) {printf("Erro"); break;}
	 i++;
	 printf("I=%ld\n",i); fflush(stdout);
	}
}
