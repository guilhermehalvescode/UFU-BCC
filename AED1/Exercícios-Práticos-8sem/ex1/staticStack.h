typedef struct vet* staticStack;

staticStack sstack_start();
int sempty_stack(staticStack);
int sfull_stack(staticStack);
int spush(staticStack, int value);
int spop(staticStack, int *value);
int sget_top(staticStack, int *value);