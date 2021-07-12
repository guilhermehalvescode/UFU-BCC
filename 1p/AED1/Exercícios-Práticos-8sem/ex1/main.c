#include <stdio.h>
#include <stdlib.h>
#include "staticStack.h"

void imprimir_pilha(staticStack stk) {
    if(sempty_stack(stk)) {
        printf("\n----PILHA VAZIA----\n");
        return;
    } 
    int valor, v[20] = {0};
    printf("\n----PILHA----\n");
    int i = 0;
    while(spop(stk, &valor)) {
        if(i != 0) printf(" ");
        printf("[%d]", valor);
        v[i] = valor;
        i++;
    }
    printf("\n");
    for(i = i - 1; i >= 0; i--) 
        spush(stk, v[i]);
    
}

void inserindo(staticStack stk, int *vet) {
    int i;
    for(i = 0; i < 11; i++) {
        if(!spush(stk, vet[i])) 
            break;
    }
}

void remove_pilha(staticStack stk) {
    int value;
    if(spop(stk, &value)) 
        printf("\nElemento %d foi removido da lista!!\n", value);
    else
        printf("\nNao e possivel remover da lista!\n");
}

int main() {
    int vet[20] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};
    staticStack stack;
    stack = sstack_start();
    if(stack == NULL) return 1;
    imprimir_pilha(stack);
    inserindo(stack, vet);
    imprimir_pilha(stack);
    remove_pilha(stack);
    imprimir_pilha(stack);
    int value;
    sget_top(stack, &value);
    printf("\nValor do topo: %d\n", value);
    imprimir_pilha(stack);
    return 0;
}