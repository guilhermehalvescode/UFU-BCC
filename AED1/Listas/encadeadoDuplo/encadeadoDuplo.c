#include <stdio.h>
#include <stdlib.h>
#include "encadeadoDuplo.h"
//estrutura para posicao de cada elemento
struct no {
    int info;
    Lista prox, ant;
};
//cria a lista devolvendo NULL para uma lista vazia
Lista cria_lista() {
    return NULL;
};
//verifica se a lista esta vazia olhando se o ponteiro da aplica��o aponta para NULL
int lista_vazia(Lista list) {
    return list == NULL;
}

//insere um elemento no comeco da lista
int insere_elem(Lista *list, int elem) {
    //aloca um no da lista
    Lista N = (Lista) malloc(sizeof(struct no));
    //verifica se a alocacao foi bem sucedida
    if(N == NULL)
        return 0;
    //insere um info em no
    N->info = elem;
    //novo nó recebe como antecessor NULL
    N->ant = NULL;
    //insere a posicao para o proximo elemento da lista
    N->prox = *list;
    if(!lista_vazia(*list)) 
        (*list)->ant = N;
    //passa para a aplicacao o endereco do inicio da lista
    *list = N;
    //sucesso, retorna flag 1
    return 1;
}

//insere um elemento de forma ordenada na lista
int insere_ord(Lista *list, int elem) {
    //aloca um no da lista
    Lista N = (Lista) malloc(sizeof(struct no));
    //verifica se a alocacao foi bem sucedida
    if(N == NULL)
        return 0;
    N->info = elem;
    //insere no inicio
    if(lista_vazia(*list) || (*list)->info >= elem) {
        N->ant = NULL;
        N->prox = *list;
        if(!lista_vazia(*list))
            (*list)->ant = N;
        *list = N;
        return 1;
    }
    Lista aux = *list;
    while(aux->prox != NULL && aux->info < elem) 
        aux = aux->prox;
    //insere no final
    if(aux->prox == NULL && aux->info < elem) {
        N->prox = NULL;
        N->ant = aux;
        aux->prox = N;
        return 1;
    }
    //insere no meio da lista
    N->prox = aux;
    N->ant = aux->ant;
    aux->ant = N;
    N->ant->prox = N;
    //sucesso, retorna flag 1
    return 1;
}

//remove um det elemento da lista
int remove_elem(Lista *list, int elem) {
    //se a lista estiver vazia nao ha como remover
    if(lista_vazia(*list))
        return 0;
    //ponteiro para o primeiro no
    Lista aux = *list;
    //percorrendo lista
    while(aux->prox != NULL && aux->info != elem)
        aux = aux->prox; // avanca na lista
    //elemento nao esta na lista
    if(aux->info != elem) 
        return 0;
    //remove no da lista
    //verifica se tem elemento depois do qual quer remover
    if(aux->prox != NULL) aux->prox->ant = aux->ant;
    //verifica se tem elemento antes do qual quer remover
    if(aux->ant != NULL) aux->ant->prox = aux->prox;
    //verifica se esta no início o elemento que quer remover
    if(aux == *list) *list = aux->prox;
    free(aux); //libera memoria alocada do removido
    return 1;
}

//remove um det elemento da lista
int remove_ord(Lista *list, int elem) {
    //se a lista estiver vazia nao ha como remover
    if(lista_vazia(*list))
        return 0;
    //olha se o elemento pode estar na lista pelo começo dela
    if((*list)->info > elem) 
        return 0;
    //ponteiro para o primeiro no
    Lista aux = *list;
    //percorrendo lista
    while(aux->prox != NULL && aux->info < elem)
        aux = aux->prox; // avanca na lista
    //elemento nao esta na lista
    if(aux->info > elem) 
        return 0;
    //remove no da lista
    //verifica se tem elemento depois do qual quer remover
    if(aux->prox != NULL) aux->prox->ant = aux->ant;
    //verifica se tem elemento antes do qual quer remover
    if(aux->ant != NULL) aux->ant->prox = aux->prox;
    //verifica se esta no início o elemento que quer remover
    if(aux == *list) *list = aux->prox;
    free(aux); //libera memoria alocada do removido
    return 1;
}
//inefeciente para consultas, pois para cada posicao
//deve percorter a lista novamente
//o melhor seria retorna um ponteiro para o vetor com os dados da lista
//obtem o valor na posicao indice da lista
int obtem_valor_elem(Lista list, int indice, int *elem) {
    //aumenta para andar indice vezes na lista
    //verifica se a lista e valida
    if(lista_vazia(list) || indice < 0)
        return 0;
    //percorrendo lista
    while(list != NULL && indice--)
        list = list->prox; // avanca na lista
    //verifica se chegou fora da lista
    if(list == NULL)
        return 0;
    //retorna o valor do no em elem
    *elem = list->info;
    return 1;
}