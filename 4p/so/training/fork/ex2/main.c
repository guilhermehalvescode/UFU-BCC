#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int i;
  pid_t pids[5];
  for(i = 0; i < 5; i++) {
    pids[i] = vfork();
    if(pids[i] == 0) {
      execve("./extern.out", NULL, NULL);
      return 0;
    } else if(pids[i] < 0) return 0;
  }
  return waitpid(-1, NULL, WNOHANG);
}