#include <unistd.h>
#include <signal.h>
#include <stdio.h>

main()
{
	int i=0;
	while(1) { sleep(30); printf("Passou\n");}
} 
