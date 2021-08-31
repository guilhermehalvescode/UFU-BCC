#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#define N_PIPES 2

void f1Consumer(int p) {
  //while f1 not empty
  //remove values and send to pipes
  while()
}

int main() {
  int pipes[N_PIPES][2];
  if(pipe(pipes[0])) exit(1);
  if(pipe(pipes[1])) exit(1);
  signal(SIGUSR1, f1Consumer);
  while(1);
  return 0;
}