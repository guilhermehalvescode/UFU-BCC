#include <stdio.h>
#include <stdlib.h>
#include "listaest.h"
#define MAX 20

//estrutura para a lista
struct lista {
    float no[MAX];
    int size;
};

//metodo que cria uma lista
Lista criar_lista() {
    Lista list;
    list = (Lista) malloc(sizeof(struct lista));
    //se a aloca��o for mal sucedida, nao inicializa o tamanho com 0
    if(list != NULL) {
        list->size = 0;
    }
    return list;
}

int lista_tam(Lista list) {
    if(list == NULL)
        return 0;
    return list->size;
}

//procedimento que verifica se a lista esta vazia
int lista_vazia(Lista list){
    return list->size == 0;
}

//procedimento que verifica se a lista esta cheia
int lista_cheia(Lista list){
    return list->size == MAX;
}

//procedimento que insere um elemento no final da lista
int insere_elem(Lista list, float elem) {
    //verifica se a lista � v�lida
    if(list == NULL || lista_cheia(list))
        return 0;
    //insere no final da lista e aumenta seu tamanho
    list->no[list->size] = elem;
    list->size++;
    return 1;
}

//procedimento que remove um determinado elemento de uma lista
int remove_elem(Lista list, float elem) {
    //verifica se a determinada lista � v�lida
    if(list == NULL || lista_vazia(list))
        return 0;
    int i, aux = 0;
    //percorre at� encontrar a posi��o do elemento para remove-lo
    while(aux < list->size && list->no[aux] != elem)
        aux++;
    //verifica se a lista nao chegou ao final depois de procurar o elem nela
    if(aux == list->size)
        return 0;
    //realiza o deslocamento para apagar o elemento na posi��o aux
    for(i = aux + 1; i < list->size; i++)
        list->no[i - 1] = list->no[i];
    //diminui o tamanho da lista
    list->size--;
    return 1;
}

int limpa_lista(Lista list) {
    //verifica se a lista � v�lida
    if(list == NULL) {
        return 0;
    }
    //lista limpada quer dizer que a quantidade de elementos � nula
    list->size = 0;
    return 1;
}

int get_posicao(Lista list, int i, float* var) {
    //verifica algum erro nos parametros da fun��o
    if(var == NULL || list == NULL || i < 0 || i > list->size - 1)
        return 0;
    //atribui em var o valor da posi��o solicitada
    *var = list->no[i];
    return 1;
}



