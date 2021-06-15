#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void imprimir_fila(Queue fil) {
    if(queue_empty(fil)) {
        printf("\n----FILA VAZIA----\n");
        return;
    } 
    char v[20][10];
    printf("\n----FILA----\n");
    int i = 0;
    while(queue_pop(fil, v[i])) {
        if(i != 0) printf(" ");
        printf("[%s]", v[i]);
        i++;
    }
    printf("\n");
    int j;
    for(j = 0; j < i; j++) 
        queue_push(fil, v[j]);
    
}

void remove_fila(Queue fil) {
    char value[10];
    if(queue_pop(fil, value)) 
        printf("\nElemento %s foi removido da fila!!\n", value);
    else
        printf("\nNao e possivel remover da fila!\n");
}

int main() {
    char vet[4][20] = {"casa", "moto", "bicicleta", "quadro"};
    Queue queue = queue_start();
    if(queue == NULL) return 1;
    imprimir_fila(queue);
    int i;
    for(i = 0; i < 4; i++) {
        if(!queue_push(queue, vet[i])) 
            break;
    }
    imprimir_fila(queue);
    remove_fila(queue);
    imprimir_fila(queue);
    return 0;
}