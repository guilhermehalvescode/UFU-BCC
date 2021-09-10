#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "sharedmems.h"
#include <sys/types.h>
#include <sys/shm.h>

void p123(Shared_area_f1 sm_f1_ptr);
void p4(Shared_area_f1 sm_f1_ptr, int pipeEntrance0, int pipeEntrance1);
void p56(Shared_area_f2 sm_f2_ptr, int pipeExit);
void p7(Shared_area_f2 sm_f2_ptr);