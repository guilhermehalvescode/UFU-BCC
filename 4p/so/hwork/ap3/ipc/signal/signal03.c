#include <signal.h>
#include <stdio.h>

main()
{
   while(1)
   {
	kill(10886, 19);
	sleep(3);	
	kill(10886, SIGCONT);
	sleep(3);	
   }
} 
