#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pids[500];
  int i, status = 0;
  for(i = 0; i < 500; i++) {
    pids[i] = vfork();
    if(!pids[i]) {
      return execve("./a.out", NULL, NULL); // if pid[i] == 0, child process created successfully
    } 
  }
  return waitpid(-1, &status, WNOHANG);
}