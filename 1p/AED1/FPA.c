#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FPA.h"

struct no {
    char strings[16];
    struct no *prox;
};

Fila cria_fp() {
    return NULL;
}

int fp_vazia(Fila fil) {
    return fil == NULL;
}

int insere(Fila *fil, char *string) {
    Fila N = (Fila) malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    strcpy(N->info, string);
    if (lista_vazia(*fil) || strcmp(string, (*fil)->strings) <= 0) {
        N->prox = *fil;
        *fil = N;
        return 1;
    }
    Fila aux = *fil;
    while (aux->prox != NULL && strcmp(string, aux->prox->strings) < 0)
        aux = aux->prox; 
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remover(Fila *fil, char *string) {
    if(fp_vazia(*fil)) 
        return 0;
    Fila aux = *fil;
    strcpy(string, aux->strings);
    *fil = aux->prox;
    free(aux); 
    return 1;
}