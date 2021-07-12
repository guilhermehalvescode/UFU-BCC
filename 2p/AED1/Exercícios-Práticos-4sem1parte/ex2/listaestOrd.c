#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaestOrd.h"
#define MAX 20

struct bebida {
    char nome[20];
    int volume;
    float preco;
};

//estrutura para a lista
struct lista {
    struct bebida no[MAX];
    int size;
};

int maior(char *nome1, char *nome2, int volume1, int volume2) {
    int res = strcmp(nome1, nome2);
    if(res) 
        return res < 0;
    return volume2 >= volume1;
}

int verifica(char *nome, int volume, float preco) {
    return nome == NULL || strlen(nome) > MAX - 1 || volume < 0 || preco < 0;
}

//metodo que cria uma lista
Lista inicializar_lista() {
    Lista list;
    list = (Lista) malloc(sizeof(struct lista));
    //se a aloca��o for mal sucedida, nao inicializa o tamanho com 0
    if(list != NULL) {
        list->size = 0;
    }
    return list;
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
int insere_ord(Lista list, char *nome, int volume, float preco) {
    //verifica se a lista � v�lida
    if(list == NULL || lista_cheia(list) || verifica(nome, volume, preco))
        return 0;
    struct bebida beb;
    strcpy(beb.nome, nome);
    beb.volume = volume;
    beb.preco = preco;
    //verifica se o elemento pode ser colocado no inicio ou no final
    if(lista_vazia(list) || maior(list->no[list->size-1].nome, nome, list->no[list->size-1].volume, volume)) {
        list->no[list->size] = beb;
    } else {
        int i, aux = 0;
        while(maior(list->no[aux].nome, nome, list->no[aux].volume, volume)) // procura indice onde deve colocar o elemento
            aux++;
        for(i = list->size; i > aux; i--)
            list->no[i] = list->no[i - 1]; //desloca elementos na lista
        list->no[aux] = beb; //inclui elemento na lista
    }
    //aumenta o tamanho da lista
    list->size++;
    return 1;
}
//procedimento que remove um determinado elemento de uma lista
int remove_ord(Lista list, char *nome) {
    //verifica se a determinada lista � v�lida e se o elemento nao esta nas pontas da lista
    if(list == NULL || lista_vazia(list) || strcmp(list->no[0].nome, nome) > 0 || strcmp(list->no[list->size - 1].nome, nome) < 0)
        return 0;
    int i, aux = 0;
    //percorre at� encontrar a posi��o do elemento para remove-lo
    while(aux < list->size && strcmp(list->no[aux].nome, nome) < 0)
        aux++;
    //verifica se a lista nao chegou ao final e se o elem n�o � menor que a posi��o procurada
    if(aux == list->size || strcmp(list->no[aux].nome, nome) > 0)
        return 0;
    //realiza o deslocamento para apagar o elemento na posi��o aux
    for(i = aux + 1; i < list->size; i++)
        list->no[i - 1] = list->no[i];
    //diminui o tamanho da lista
    list->size--;
    return 1;
}

//procedimento que retorna o elemento da posi��o solicitada
int get_pos(Lista list, int i, char *nome, int *volume, float *preco) {
    //verifica algum erro nos parametros da fun��o
    if(list == NULL || i < 0 || i > list->size - 1 || verifica(nome, *volume, *preco))
        return 0;
    //atribui em var o valor da posi��o solicitada
    strcpy(nome, list->no[i].nome);
    *volume = list->no[i].volume;
    *preco = list->no[i].preco;
    return 1;
}



