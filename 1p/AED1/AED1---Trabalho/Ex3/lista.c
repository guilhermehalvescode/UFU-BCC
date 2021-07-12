#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
    float info; //Informação que será guardada pelo no
    struct no *prox; //Enderço do nó sucessor
};

Lista criar_lista(){
    return NULL;
}

//Verifica se lista está vazia
int lista_vazia(Lista lista){
    if (lista == NULL)
        return 1; //Vazia
    else
        return 0; //Não é vazia
}

//Insere elem em lista de maneira ordenada (1 = INSERIDO; 0 = FALHA)
int insere_ord(Lista *lista, float elem){ //Ordenado
    //Envolve o percorrimento da lista
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;
    if (lista_vazia(*lista) || elem >= (*lista)->info) {
        N->prox = *lista;
        *lista = N;
        return 1;
    }
    //Percorrimento da lista
    Lista aux = *lista; //Aponta para o 1º no
    while (aux->prox != NULL && aux->prox->info > elem)
        aux = aux->prox; //Avança
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

//Remove o elem de lista de maneira ordenada (1 = REMOVIDO; 0 = FALHA)
int remove_ord(Lista *lista, float elem){ //Ordenado
    if (lista_vazia(*lista) == 1 || elem > (*lista)->info)
        return 0;
    Lista aux = *lista; //Aponta para o 1º no
    if (elem == (*lista)->info) {
        *lista = aux->prox;
        free(aux);
        return 1;
    }

    while (aux->prox != NULL && aux->prox->info > elem)
        aux = aux->prox; //Avança
    if (aux->prox == NULL || aux->prox->info < elem)
        return 0;
    Lista aux_2 = aux->prox; //Aponta para no a ser removido
    aux->prox = aux_2->prox; //Retira no da lista
    return 1;
}

//Retorna por referência em elem o elemente de lista na posição pos
int obtem_valor(Lista *lista, float *elem, size_t pos){
    if(pos < 0 || lista_vazia(*lista) == 1)
        return 0;
    size_t i = 0;
    Lista aux = (*lista);
    
    while (i < pos && aux->prox != NULL) {
        aux = aux->prox;
        i++;
    }

    if (i != pos)
        return 0;

    *elem = aux->info;
    return 1; 
}

//Limpa lista (1 = LIMPO; 0 = FALHA)
int esvaziar_lista(Lista *lista){
    if (lista_vazia(*lista) == 1)
        return 0;

    while ((*lista)->prox != NULL) {
        Lista aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
    free(*lista);
    *lista = NULL;
    return 1;
}

//Remove o elemento na posição pos de lista (1 = REMOVIDO; 0 = FALHA)
int remove_pos(Lista *lista, size_t pos, float *elem){
    size_t i = 1; //Começa a verificar partindo do elemento 1 (primeiro)
    Lista aux = *lista; //Aponta para o primeiro no

    if (lista_vazia(*lista) == 1)
       return 0;
    if (pos == 1) {
        *elem = (*lista)->info;
        *lista = aux->prox;
        return 1;
    }
    //While e feito de modo para que o elem a ser removido seja o aux->prox
    while (aux->prox != NULL && i < pos-1) { //Se nao chegou na pos desejada e o prox elemento é valido: avançar
        aux = aux->prox; //avança o element
        i++; //incrementa a poscls
    }
    if (i != pos-1) //Caso saia do while anterior sem chegar na pos desejada: erro
        return 0;
    *elem = aux->prox->info;
    Lista aux_2 = aux->prox; //Aponta para no a ser removido
    aux->prox = aux_2->prox; //Retira no da lista
    return 1;
}

//Compara lista_1 com lista_2 (1 = IGUAIS; 0 = DIFERENTES)
int listas_iguais(Lista *lista_1, Lista *lista_2){
    if (lista_vazia(*lista_1) == 1 || lista_vazia(*lista_2) == 1)
        return 0;

    Lista aux_1 = (*lista_1);
    Lista aux_2 = (*lista_2);

    while (((aux_1)->prox != NULL && (aux_2)->prox != NULL) 
    && ((aux_1)->info == (aux_2)->info)) {
        (aux_1) = (aux_1)->prox;
        (aux_2) = (aux_2)->prox;
    }

    if ((aux_1)->info == (aux_2)->info && ((aux_1)->prox != NULL && (aux_2)->prox != NULL))
        return 1;

    return 0;
}

//Retorna por referência (em *elem) o elemento de maior valor em lista (1 = SUCESSO; 0 = FALHA)
int maior_valor(Lista *lista, float *elem){
    if (lista_vazia(*lista) == 1)
        return 0;
    
    //Como a lista é ordenada de maneira decrescente, o maior valor está no primeiro nó da lista
    *elem = (*lista)->info;
    return 1;
}

//Retorna o número de elementos presentes na lista;
int tamanho_lista(Lista *lista){
    int tam = 0;
    if (lista_vazia(*lista) == 1)
        return tam;
    Lista aux = (*lista);
    tam = 1;
    while ((aux)->prox != NULL) {
        (aux) = (aux)->prox;
        tam++;
    }
    return tam;
}

//Retorna um ponteiro para a lista resultante da intercalação de lista_1 e lista_2 (NULL = FALHA)
int intercalar_listas(Lista *lista_1, Lista *lista_2, Lista *lista_3){
    Lista aux_1 = (*lista_1);
    Lista aux_2 = (*lista_2);
    if (lista_vazia(aux_1) == 1 || lista_vazia(aux_2) == 1)
        return 0;

    for (size_t i = 0; i < tamanho_lista(lista_1); i++) {
        if (insere_ord(&(*lista_3), aux_1->info) == 0)
            return 0;
        aux_1 = aux_1->prox;
    }

    for (size_t i = 0; i < tamanho_lista(lista_2); i++) {
        if (insere_ord(&(*lista_3), aux_2->info) == 0)
            return 0;
        aux_2 = aux_2->prox;
    }
    
    return 1;
}