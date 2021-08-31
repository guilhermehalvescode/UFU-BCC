#include <stdlib.h>
#include <signal.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int aleNum;

  while(1) {
    //gen aleatory val bet [1, 1000]
    aleNum = 1 + (rand() % 1000);
    //insert in shared mem
    if(fila_cheia) {
      kill(pid_p4, SIGUSR1);
    }
  } 
  return 0;
}