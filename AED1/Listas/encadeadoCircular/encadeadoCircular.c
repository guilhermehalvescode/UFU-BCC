#include <stdio.h>
#include <stdlib.h>
#include "encadeadoCircular.h"
//Estrutura para posicao de cada elemento
struct no {
    int info;
    struct no *prox;
};
//Cria a lista
Lista cria_lista() {
    return NULL;
};
//Verifica se a lista esta vazia
int lista_vazia(Lista list) {
    return list == NULL;
}
//Insere um elemento no final da lista
int insere_final(Lista *list, int elem) {
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;
    if(lista_vazia(*list)) {
        N->prox = N;
        *list = N;
    } else {
        N->prox = (*list)->prox;
        (*list)->prox = N;
        *list = N;
    }
    return 1;
}
//Insere um elemento no início de uma lista
int insere_inicio(Lista *list, int elem) {
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;
    if(lista_vazia(*list)) {
        N->prox = N;
        *list = N;
    } else {
        N->prox = (*list)->prox;
        (*list)->prox = N;
    }
    return 1;
}

//Remove um elemento do início da lista
int remove_inicio(Lista *list, int *elem) {
    if(lista_vazia(*list))
        return 0;
    Lista aux = (*list)->prox;
    *elem = aux->info;
    if(*list == (*list)->prox) 
        *list = NULL;
     else 
        (*list)->prox = aux->prox;
    free(aux);
    return 1;
}

//Remove um elemento do fim da lista 
int remove_final(Lista *list, int *elem) {
    if(lista_vazia(*list))
        return 0;
    *elem = (*list)->info;
    Lista aux = (*list)->prox;
    if(*list == (*list)->prox) {
        *list = NULL;
        free(aux);
    } else {
        while(aux->prox->prox != (*list)->prox) 
            aux = aux->prox;
        aux->prox = (*list)->prox;
        free(*list);
        *list = aux;
    }
    return 1;
}
//Obtem o valor do elemento de uma lista no indice especificado
int obtem_valor_elem(Lista list, int indice, int *elem) {
    if(indice < 0 || lista_vazia(list))
        return 0;
    Lista aux = list->prox;
    while(indice > 0 && aux->prox != list->prox) {
        aux = aux->prox;
        indice--;
    }
    if(!indice) {
        *elem = aux->info;
        return 1;
    }
    return 0;
}