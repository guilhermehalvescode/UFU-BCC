#include <stdio.h>
#include <stdlib.h>
#include "dinamicStackFLOAT.h"

struct node {
    float info;
    struct node* next;
};

FloatStack start_stk() {
    return NULL;
}

int stack_empty(FloatStack stk) {
    return stk == NULL;
}

int stack_push(FloatStack *stk, float value) {
    FloatStack node = (FloatStack) malloc(sizeof(struct node));
    if(node == NULL)
        return 0;
    node->info = value;
    node->next = *stk;
    *stk = node;
    return 1;
}

int stack_pop(FloatStack *stk, float *value) {
    if(stack_empty(*stk))
        return 0;
    FloatStack aux = *stk;
    *value = aux->info;
    *stk = aux->next;
    free(aux);
    return 1;
}

int stack_top(FloatStack *stk, float *value) {
    if(stack_empty(*stk))
        return 0;
    *value = (*stk)->info;
    return 1;
}

int free_stack(FloatStack *stk) {
    if(*stk == NULL) return 0;
    FloatStack aux;
    while(*stk != NULL) {
        aux = (*stk)->next;
        free(*stk);
        *stk = aux;
    }
    return 1;
}