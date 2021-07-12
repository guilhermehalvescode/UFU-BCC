#include <stdio.h>
#include <stdlib.h>
#include "void.h"

struct no {
    int tipo;
    void *info;
    struct no* prox;
};

Lista cria_lista() {
    return NULL;
};

int lista_vazia(Lista list) {
    return list == NULL;
}

int insere_elem(Lista *list, float nota, char conceito, int key) {
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL || (key != 0 && key != 1))
        return 0;
    N->tipo = key;
    if(key) {
        char *c = (char*) malloc(sizeof(char));
        if(c == NULL) return 0;
        *c = conceito;
        N->info = c;
    } else {
        float *n = (float*) malloc(sizeof(float));
        if(n == NULL) return 0;
        *n = nota;
        N->info = n;
    }
    N->prox = *list;
    *list = N;
    return 1;
}

int remove_elem(Lista *list, float nota, char conceito) {
    if(lista_vazia(*list))
        return -1;
    Lista aux = *list;
    if((*list)->tipo) {
        if(conceito == *((char*) (*list)->info)) {
            *list = aux->prox;
            free(aux);
            return 1; 
        }
    } else {
        if(nota == *((float*) (*list)->info)) {
            *list = aux->prox;
            free(aux);
            return 0; 
        }
    }
    while(aux->prox != NULL) {
        if(aux->prox->tipo) {
            if(*((char*) aux->prox->info) == conceito)
                break;
        } else {
            if(*((float*) aux->prox->info) == nota)
                break;
        }
        aux = aux->prox;
    }
    if(aux->prox == NULL)
        return -1;
    int flag = aux->prox->tipo;
    Lista aux2 = aux->prox; 
    aux->prox = aux2->prox; 
    free(aux2); 
    return flag;
}

int obtem_posicao(Lista list, int indice, float* var, char* letra) {
    if(lista_vazia(list) || indice < 0)
        return -1;

    while(list != NULL && indice--)
        list = list->prox; 

    if(list == NULL)
        return -1;
    if(list->tipo) {
        *letra = *((char*) list->info);
        return 1;
    }
    *var = *((float*) list->info);
    return 0;
}