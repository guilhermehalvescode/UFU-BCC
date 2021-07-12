typedef struct node* DinStack;

DinStack dstack_start();
int dempty_stack(DinStack);
int dpush(DinStack*, char value);
int dpop(DinStack*, char *value);
int dget_top(DinStack*, char *value);
int esvazia_pilha(DinStack*);