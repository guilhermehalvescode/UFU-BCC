#include <stdio.h>
#include <stdlib.h>
#include "noCabecalhoOrdenado.h"

struct no {
    int info;
    struct no* prox;
};
//Cria a lista com no cabeçalho inicializado
Lista cria_lista() {
    Lista no;
    no = (Lista) malloc(sizeof(struct no));
    if(no != NULL) {
        no->info = 0;
        no->prox = NULL;
    }
    return no;
}

//Verifica se a lista se encontra vazia
int lista_vazia(Lista list) {
    return list->prox == NULL;
}

//Insere de forma ordenada um elemento em uma lista
int insere_ord(Lista list, int elem) {
    Lista no = (Lista) malloc(sizeof(struct no));
    if(no == NULL || list == NULL)
        return 0;
    no->info = elem;    
    Lista aux = list;
    while(aux->prox != NULL && aux->prox->info < elem) 
        aux = aux->prox;
    no->prox = aux->prox;
    aux->prox = no;
    list->info++;
    return 1;
}

//Remove um elemento da lista ordenada
int remove_ord(Lista list, int elem) {
    if(lista_vazia(list)) 
        return 0;
    Lista aux = list;
    while(aux->prox != NULL && aux->prox->info < elem) 
        aux = aux->prox;
    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    list->info--;
    return 1;
}

//Obtem o valor do elemento no indice especificado
int obtem_valor_elem(Lista list, int indice, int *elem) {
    if(indice < 0 || indice > list->info - 1 || list == NULL)
        return 0;
    Lista aux = list->prox;
    while(indice > 0) {
        aux = aux->prox;
        indice--;
    }
    *elem = aux->info;
    return 1;
}