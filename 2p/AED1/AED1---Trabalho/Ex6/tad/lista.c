#include <stdio.h>
#include <stdlib.h>
#include "..\headers\lista.h"

struct no{
    int info;
    Lista prox;
    Lista ant;
};

//Retorna NULL
Lista criar_lista(){
    return NULL;
}

//Chega se a lista está vazia
//(0 = NÃO VAZIA; 1 = VAZIA)
int lista_vazia(Lista lista){
    if(lista == NULL)
        return 1;
    return 0;
}

//Insere elem em *lista de forma não ordenada
//(0 = ERRO NA ALOCAÇÃO DE ESPAÇO; 1 = ELEMENTO INSERIDO)
int insere_elem(Lista *lista, int elem){
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL)
        return 0;

    N->info = elem;
    N->ant = NULL;
    N->prox = (*lista);

    if (lista_vazia(*lista) == 0)
        (*lista)->ant = N;

    (*lista) = N;

    return 1;
}

//Remove elem de *lista (não ordenado)
int remove_elem(Lista *lista, int elem){
    if (lista_vazia(*lista) == 1)
        return 0;
    Lista aux = (*lista);

    while (aux->prox != NULL && aux->info != elem)
        aux = aux->prox;

    if (aux->info != elem)
        return 0;

    if (aux->prox != NULL)    
        aux->prox->ant = aux->ant;
    
    if (aux->ant != NULL)
        aux->ant->prox = aux->prox;

    if (aux == (*lista))
        (*lista) = aux->prox;

    free(aux);
    return 1;
}

//Retorna por referencia em elem o valor de um elemento de lista na posicao pos
int obtem_valor(Lista *lista, int *elem, size_t pos){
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

//Retorna o tamanho da lista (quantidade de elementos)
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

//Remove todas as ocorrências de elem em *lista
//(Retorna a quantidade de elementos removidos)
int remover_todos(Lista *lista, int elem){
    if (lista_vazia(*lista))
        return 0;

    int removido = 0; //Indica se foi removido um elemento da lista ou não

    while (remove_elem(&(*lista), elem) == 1)
        removido++;

    return removido;
}

//Remove o maior elemento encontrado em *lista
//(0 = LISTA VAZIA OU ERRO DESCONHECIDO; 1 = ELEMENTO REMOVIDO)
int remove_maior(Lista *lista){
    if (lista_vazia(*lista) == 1)
        return 0;
    Lista aux = (*lista);
    int maior;

    while (aux->prox != NULL) {
        if (aux->ant == NULL)
            maior = aux->info;
        else if (aux->info > maior)
            maior = aux->info;
        aux = aux->prox;
    }

    remove_elem(&(*lista), maior);
    
    return 1;
}

//Esvazia *lista (0 = FALHA; 1 = SUCESSO)
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

//Insere os elementos de *lista em *_inverso em ordem inversa
//(0 = FALHA AO INSERIR OS ELEMENTOS; 1 = LISTA INVERTIDA)
int inverter_lista(Lista *lista, Lista *_inverso){
    if (lista_vazia(*lista) == 1)
        return 0;
    
    Lista aux = (*lista);
    while (aux != NULL) {
        if (insere_elem(&(*_inverso), aux->info) == 0)
            return 0;
        aux = aux->prox;
    }
    return 1;
}

//Insere os elementos de *lista que são multiplos de 3 em _multiplos
//(0 = FALHA; 1 = SUCESSO)
int multiplos_tres(Lista *lista, Lista *_multiplos){
    if (lista_vazia(*lista) == 1)
        return 0;
    if (lista_vazia(*_multiplos) == 0) {
        if (esvaziar_lista(&(*_multiplos)) == 0)
            return 0;
    }

    Lista aux = (*lista);
    while (aux != NULL) {
        if (aux->info % 3 == 0) {
            if (insere_elem(&(*_multiplos), aux->info) == 0)
                return 0;
        }
        aux = aux->prox;
    }
    return 1;
}