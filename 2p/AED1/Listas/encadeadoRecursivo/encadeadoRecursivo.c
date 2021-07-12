#include <stdio.h>
#include <stdlib.h>
#include "encadeadoRecursivo.h"
//estrutura para posicao de cada elemento
struct no {
    double info;
    Lista prox;
};
//cria a lista devolvendo NULL para uma lista vazia
Lista cria_lista() {
    return NULL;
};
//verifica se a lista esta vazia olhando se o ponteiro da aplica��o aponta para NULL
int lista_vazia(Lista list) {
    return list == NULL;
}
//Insere de forma ordenada utilizando a técnica recursiva
int insere_ord(Lista *list, double elem) {
    if(lista_vazia(*list) || elem <= (*list)->info) {
        Lista N = (Lista) malloc(sizeof(struct no));
        if(N == NULL)
            return 0;
        N->info = elem;
        N->prox = *list;
        *list = N;
        return 1;
    }
    return insere_ord(&((*list)->prox), elem); 
}

//Remove de forma ordenada utilizando a técnica recursiva
int remove_ord(Lista *list, double elem) {
    if(lista_vazia(*list) || elem < (*list)->info) 
        return 0;
    if(elem == (*list)->info) {
        Lista aux = (*list)->prox;
        (*list)->prox = aux->prox;
        free(aux);
        return 1;
    }
    return remove_ord(&((*list)->prox), elem); 
}

//Obtem um determinado elemento em um indice
int obtem_elem(Lista list, int pos, double *var) {
    if(lista_vazia(list) || pos < 0)
        return 0;
    //Condição de parada (se o indice for 0) retorna o elemento que está no inicio
    if(pos == 0) {
        *var = list->info;
        return 1;
    }
    //Se for em pos, está em pos-1
    return obtem_elem(list->prox, pos - 1, var);
}