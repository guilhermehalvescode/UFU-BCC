#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "FILA.h"

struct queue {
    struct alunos info;
    struct node* prox;
};

Fila cria_fila() {
    return NULL;
}

int fila_vazia(Fila q) {
    return q == NULL;
}

int insere(Fila *q, struct alunos elem) {
    Fila node = (Fila) malloc(sizeof(struct queue));
    if(node == NULL) 
        return 0;
    node->info = elem;
    if(fila_vazia(*q)) {
        node->prox = node;
        *q = node;
    } else {
        node->prox = (*q)->prox;
        (*q)->prox = node;
        *q = node;
    }
    return 1;
}

int remover(Fila *q, struct alunos *elem) {
    if(fila_vazia(*q)) 
        return 0;
    Fila aux = (*q)->prox;
    *elem = aux->info;
    if(*q == (*q)->prox) 
        *q = NULL;
    else
        (*q)->prox = aux->prox;
    free(aux);
    return 1;
}