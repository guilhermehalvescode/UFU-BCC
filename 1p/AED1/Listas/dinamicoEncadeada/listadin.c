#include <stdio.h>
#include <stdlib.h>
#include "listadin.h"
//estrutura para posicao de cada elemento
struct no {
    char caractere;
    struct no* prox;
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
int insere_elem(Lista *list, char elem) {
    //aloca um no da lista
    Lista N = (Lista) malloc(sizeof(struct no));
    //verifica se a alocacao foi bem sucedida
    if(N == NULL)
        return 0;
    //insere um caractere em no
    N->caractere = elem;
    //insere a posicao para o proximo elemento da lista
    N->prox = *list;
    //passa para a aplicacao o endereco do inicio da lista
    *list = N;
    //sucesso, retorna flag 1
    return 1;
}

//remove um det elemento da lista
int remove_elem(Lista *list, char elem) {
    //se a lista estiver vazia nao ha como remover
    if(lista_vazia(*list))
        return 0;
    //ponteiro para o primeiro no
    Lista aux = *list;
    //remove o elemento se este estiver no inicio da lista
    if(elem == (*list)->caractere) {
        *list = aux->prox;
        free(aux);
        return 1;
    }
    //percorrendo lista
    while(aux->prox != NULL && aux->prox->caractere != elem)
        aux = aux->prox; // avanca na lista
    //verifica se o elemento nao esta na lista
    if(aux->prox == NULL)
        return 0;
    //remove no da lista
    Lista aux2 = aux->prox; //aponta o no a ser removido
    aux->prox = aux2->prox; //retira no da lista
    free(aux2); // libera memoria alocada;
    return 1;
}

//inefeciente para consultas, pois para cada posicao
//deve percorter a lista novamente
//o melhor seria retorna um ponteiro para o vetor com os dados da lista
//obtem o valor na posicao indice da lista
int obtem_posicao(Lista list, int indice, char *carac) {
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
    //retorna o valor do no em carac
    *carac = list->caractere;
    return 1;
}
//limpa a lista
int limpa_lista(Lista *list) {
    //inicializa aux com o inicio da lista
    Lista aux = *list, aux2;
    //libera os elementos conforme percorre a lista
    while(aux != NULL) {
        aux2 = aux->prox; //variavel auxiliar
        free(aux); //libera o no na lista
        aux = aux2; //passa para o proximo no
    }
    //a lista e limpada, entao ela aponta pra NULL
    *list = NULL;
    return 1;
}
