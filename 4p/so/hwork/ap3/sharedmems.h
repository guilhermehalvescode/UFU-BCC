#include <semaphore.h>
#define MAX 10
#define MAX_RANGE 1000
#define MEM_SZ_F1 sizeof(struct shared_area_f1)
#define MEM_SZ_F2 sizeof(struct shared_area_f2)

// static queue on shared mem with counter
struct queue {
  int queue[MAX], ini, cont;
};

struct shared_area_f1 {
	sem_t mutex;
	pid_t consumer_pid; // for signaling between p123 & p4
	int num;
	struct queue queue;
};

struct shared_area_f2 {
	sem_t mutex;
	int counter, reps[MAX_RANGE], p56qnt; // p7 statistics
	struct queue queue;
};

typedef struct shared_area_f1* Shared_area_f1;
typedef struct shared_area_f2* Shared_area_f2;
typedef struct queue* Queue;

void* gen_shared_area(key_t sm_key, int isF1);
int queue_full(Queue q);
int queue_empty(Queue q);
int queue_push(Queue q, int value);
int queue_pop(Queue q, int *value);