#include <stdio.h>
#include <stdlib.h>
#include "dinamicStack.h"

struct node {
    int info;
    struct node* next;
};

DinStack dstack_start() {
    return NULL;
}

int dempty_stack(DinStack stk) {
    return stk == NULL;
}

int dpush(DinStack *stk, int value) {
    DinStack node = (DinStack) malloc(sizeof(struct node));
    if(node == NULL)
        return 0;
    node->info = value;
    node->next = *stk;
    *stk = node;
    return 1;
}

int dpop(DinStack *stk, int *value) {
    if(dempty_stack(*stk))
        return 0;
    DinStack aux = *stk;
    *value = aux->info;
    *stk = aux->next;
    free(aux);
    return 1;
}

int dget_top(DinStack *stk, int *value) {
    if(dempty_stack(*stk))
        return 0;
    *value = (*stk)->info;
    return 1;
}