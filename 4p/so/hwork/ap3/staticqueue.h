#include <semaphore.h>
#define MEM_SZ sizeof(struct shared_area)
#define MAX 10

// static queue on shared mem with counter
struct queue {
  int queue[MAX], ini, cont;
};

struct shared_area {
	sem_t mutex;
	int num;
	struct queue queue;
	pid_t consumer_pid;
};

typedef struct shared_area* Shared_area;

Shared_area gen_shared_queue_area(key_t sm_key);
int queue_full(Shared_area shared_mem);
int queue_empty(Shared_area shared_mem);
int queue_push(Shared_area shared_mem, int value);
int queue_pop(Shared_area shared_mem, int *value);