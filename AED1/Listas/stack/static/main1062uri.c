#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1010

int n, income[MAX], outcome[MAX];
struct vet {
    int v[MAX];
    int top;
};
typedef struct vet* staticStack;

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

int sameVet(int *vet1, int *vet2) {
    int i = 0;
    while(vet1[i] == vet2[i]) i++;
    return i == n;
}

void verify(int *income, int *outcome, staticStack stk) {
    int i = 0, j = 0;
    int temp[MAX], top;
    while(!sameVet(temp, outcome) && i < n) {
        do {
            spush(stk, income[j]);
            j++;
            sget_top(stk, &top);
        } while(outcome[i] != top && j < n);
        while(outcome[i] == top && i < n) {
            spop(stk, &top);
            temp[i] = top;
            i++;
            sget_top(stk, &top);
        }
        if(j == n) 
            break;
    }
    if(!sameVet(temp, outcome))
        printf("No\n");
    else
        printf("Yes\n");
    while(spop(stk, &top));
}

void inicializa(){ 
    int i;
    for(i = 0; i < MAX; i++) {
        income[i] = 0;
        outcome[i] = 0;
    }
}
int main() {
    int i, first = 1;
    staticStack stack = sstack_start();
    if(stack == NULL) return 0;
    while (1) {
        scanf(" %d", &n);
        if(!n) break;
        if(!first) printf("\n");
        while(1) {
            scanf(" %d", &i);
            if(i == 0) break;
            inicializa();
            income[0] = 1;
            outcome[0] = i;
            for(i = 1; i < n; i++) {
                income[i] = i + 1;
                scanf(" %d", outcome + i);
            }        
            verify(income, outcome, stack);
        }
        if(first) first = 0;
    }
    return 0;
}