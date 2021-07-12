#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaest.h"
#define MAX 20
#define TAM 11

//estrutura para a lista
struct lista {
    char no[MAX][TAM];
    int size;
};

//metodo que cria uma lista
Lista inicializar_lista() {
    Lista list;
    list = (Lista) malloc(sizeof(struct lista));
    //se a aloca��o for mal sucedida, nao inicializa o tamanho com 0
    if(list != NULL) {
        int i, j;
        for(i = 0; i < MAX; i ++) {
            for(j = 0; j < TAM; j++) {
                list->no[i][j] = '\0';
            }
        }
        list->size = 0;
    }
    return list;
}

//Procedimento que verifica se a lista esta vazia
int lista_vazia(Lista list){
    return list->size == 0;
}

//procedimento que verifica se a lista esta cheia
int lista_cheia(Lista list){
    return list->size == MAX;
}

//Procedimento que insere um elemento no final da lista
int insere_elem(Lista list, char *elem) {
    //verifica se a lista � v�lida
    if(list == NULL || lista_cheia(list) || strlen(elem) > TAM - 1)
        return 0;
    //insere no final da lista e aumenta seu tamanho
    strcpy(list->no[list->size], elem);
    list->size++;
    return 1;
}

//procedimento que remove um determinado elemento de uma lista
int remove_elem(Lista list, char *elem) {
    //verifica se a determinada lista � v�lida
    if(list == NULL || lista_vazia(list) || strlen(elem) > TAM - 1)
        return 0;
    int i, aux = 0;
    //percorre at� encontrar a posi��o do elemento para remove-lo
    while(aux < list->size && strcmp(elem, list->no[aux]))
        aux++;
    //verifica se a lista nao chegou ao final depois de procurar o elem nela
    if(aux == list->size)
        return 0;
    //realiza o deslocamento para apagar o elemento na posi��o aux
    for(i = aux + 1; i < list->size; i++)
        strcpy(list->no[i - 1], list->no[i]);
    //diminui o tamanho da lista
    list->size--;
    return 1;
}

int get_pos(Lista list, int i, char *var) {
    //verifica algum erro nos parametros da fun��o
    if(var == NULL || list == NULL || i < 0 || i > list->size - 1)
        return 0;
    //atribui em var o valor da posi��o solicitada
    strcpy(var, list->no[i]);
    return 1;
}



