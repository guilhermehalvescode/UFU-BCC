#include <stdio.h>
#include <stdlib.h>
#include "dinamicStackCHAR.h"

struct node {
    char info;
    struct node* next;
};

DinStack dstack_start() {
    return NULL;
}

int dempty_stack(DinStack stk) {
    return stk == NULL;
}

int dpush(DinStack *stk, char value) {
    DinStack node = (DinStack) malloc(sizeof(struct node));
    if(node == NULL)
        return 0;
    node->info = value;
    node->next = *stk;
    *stk = node;
    return 1;
}

int dpop(DinStack *stk, char *value) {
    if(dempty_stack(*stk))
        return 0;
    DinStack aux = *stk;
    *value = aux->info;
    *stk = aux->next;
    free(aux);
    return 1;
}

int dget_top(DinStack *stk, char *value) {
    if(dempty_stack(*stk))
        return 0;
    *value = (*stk)->info;
    return 1;
}

int esvazia_pilha(DinStack *stk) {
    if(*stk == NULL) return 0;
    DinStack aux;
    while(*stk != NULL) {
        aux = (*stk)->next;
        free(*stk);
        *stk = aux;
    }
    return 1;
}