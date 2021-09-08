#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include "staticqueue.h"
#include <sys/types.h>

// global var to p4 signal problem
// it's read only, once is set by master proc
// so no need to treat concurrency
// Shared_area sm_f1_ptr;

void p123(Shared_area sm_f1_ptr, int id);
void p4(Shared_area sm_f1_ptr, int* pipe0, int* pipe1);