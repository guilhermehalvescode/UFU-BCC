#include <stdlib.h>
#include <stdio.h>
#include "staticStack.h"
#define MAX 20

struct vet {
    int v[MAX];
    int top;
};

staticStack sstack_start() {
    staticStack stk = (staticStack) malloc(sizeof(struct vet));
    if(stk != NULL)  
        stk->top = 0;
    return stk;
}

int sempty_stack(staticStack stk) {
    return !(stk->top);
}

int sfull_stack(staticStack stk){
    return stk->top == MAX;
}

int spush(staticStack stk, int value) {
    if(stk == NULL || sfull_stack(stk))
        return 0;
    stk->v[stk->top] = value;
    (stk->top)++;
    return 1;
}

int spop(staticStack stk, int *value) {
    if(stk == NULL || sempty_stack(stk))
        return 0;
    (stk->top)--;
    *value = stk->v[stk->top];
    return 1;
}

int sget_top(staticStack stk, int *value) {
    if(stk == NULL || sempty_stack(stk))
        return 0;
    *value = stk->v[(stk->top) - 1];
}