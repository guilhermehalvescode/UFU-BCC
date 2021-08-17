#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pids[500];
  int i, status = 0;
  for(i = 0; i < 500; i++) {
    pids[i] = fork();
    if(!pids[i]) return 0; // if pid[i] == 0, child process created successfully
  }
  return waitpid(-1, &status, WNOHANG);
}