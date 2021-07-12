typedef struct node* DinStack;

DinStack dstack_start();
int dempty_stack(DinStack);
int dpush(DinStack*, int value);
int dpop(DinStack*, int *value);
int dget_top(DinStack*, int *value);