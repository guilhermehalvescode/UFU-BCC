#include <stdio.h>
#include <stdlib.h>
#include "listaestOrd.h"
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
//procedimento que retorna o tamanho atual de uma lista
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
int insere_ord(Lista list, float elem) {
    //verifica se a lista � v�lida
    if(list == NULL || lista_cheia(list))
        return 0;
    //verifica se o elemento pode ser colocado no inicio ou no final
    if(lista_vazia(list) == 1 || elem >= list->no[list->size - 1]) {
        list->no[list->size] = elem;
    } else {
        int i, aux = 0;
        while(elem >= list->no[aux]) // procura indice onde deve colocar o elemento
            aux++;
        for(i = list->size; i > aux; i--)
            list->no[i] = list->no[i - 1]; //desloca elementos na lista
        list->no[aux] = elem; //inclui elemento na lista
    }
    //aumenta o tamanho da lista
    list->size++;
    return 1;
}
//procedimento que remove um determinado elemento de uma lista
int remove_ord(Lista list, float elem) {
    //verifica se a determinada lista � v�lida e se o elemento esta nas pontas da lista
    if(list == NULL || lista_vazia(list) || elem < list->no[0] || elem > list->no[list->size - 1])
        return 0;
    int i, aux = 0;
    //percorre at� encontrar a posi��o do elemento para remove-lo
    while(aux < list->size && list->no[aux] < elem)
        aux++;
    //verifica se a lista nao chegou ao final e se o elem n�o � menor que a posi��o procurada
    if(aux == list->size || list->no[aux] > elem)
        return 0;
    //realiza o deslocamento para apagar o elemento na posi��o aux
    for(i = aux + 1; i < list->size; i++)
        list->no[i - 1] = list->no[i];
    //diminui o tamanho da lista
    list->size--;
    return 1;
}
//procedimento que limpa uma lista
int limpa_lista(Lista list) {
    //verifica se a lista � v�lida
    if(list == NULL) {
        return 0;
    }
    //lista limpada quer dizer que a quantidade de elementos � nula
    list->size = 0;
    return 1;
}
//procedimento que retorna o elemento da posi��o solicitada
int get_posicao(Lista list, int i, float* var) {
    //verifica algum erro nos parametros da fun��o
    if(var == NULL || list == NULL || i < 0 || i > list->size - 1)
        return 0;
    //atribui em var o valor da posi��o solicitada
    *var = list->no[i];
    return 1;
}



