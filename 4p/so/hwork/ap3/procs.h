#include <signal.h>
#include <pthread.h>
#include "staticqueue.h"
#include <sys/types.h>

// global var to p4 signal problem
// it's read only, once is set by master proc
// so no need to treat concurrency
Shared_area sm_f1_ptr;

void p123(pid_t pid_consumer);
void p4(int* p0, int* p1);