/* 
--Justificativa do aluno sobre a escolha do TAD--
    Para o problema de Josephus, como se trata de uma roda com remoções de pessoas
através de sorteios, utilizei uma lista encadeada(devido a quantidade grande quantidade 
de remoções ao decorrer do programa), com o comportamento circular(para que a ideia de roda
ocorra com maior facilidade, e seja possível percorrer a lista na forma de um círculo, já que
é necessário passar do fim para o início da lista várias vezes). Cogitei em usar a técnica de nó cabeçalho 
para o problema, mas conclui que não seria necessário, já que ia tornar a implementação mais difícil 
pelo fato de ser circular, e também, percorrer a lista uma vez para saber seu tamanho já é 
suficiente para descartar o uso do nó cabeçalho para esse problema.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
//Estrutura para posicao de cada elemento
struct no {
    char nomeSoldado[50];
    struct no *prox;
};
//Cria a lista
Lista cria_lista() {
    return NULL;
};
//Verifica se a lista esta vazia
int lista_vazia(Lista list) {
    return list == NULL;
}

//Retorna o tamanho da lista
int lista_tam(Lista list) {
    if(lista_vazia(list))
        return 0;
    //se nao esta vazia, tem pelo menos 1
    int cont = 1;
    Lista aux = list->prox;
    while(aux->prox != list->prox) {
        aux = aux->prox;
        cont++;
    }
    return cont;
}
//Insere um elemento no final da lista
int insere_nome(Lista *list, char* nome) {
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    
    strcpy(N->nomeSoldado, nome);
    if(lista_vazia(*list)) {
        N->prox = N;
        *list = N;
    } else {
        N->prox = (*list)->prox;
        (*list)->prox = N;
        *list = N;
    }
    return 1;
}
//Remove um elemento em uma determinada posição
int remove_pos(Lista *list, int pos, char* nome) {
    if(lista_vazia(*list)) 
        return 0;
    //Percorro até a posição pos
    while(pos > 0) {
        *list = (*list)->prox;
        pos--;
    }
    //Retorna o nome removido
    strcpy(nome, (*list)->prox->nomeSoldado);
    Lista aux2 = (*list)->prox;
    (*list)->prox = aux2->prox;
    free(aux2);
    return 1;
}

//Avança a lista pos posições
int avanca_lista(Lista *list, int pos){
    if(lista_vazia(*list) || pos < 0) 
        return 0;
    //Anda até pos
    while(pos > 0) {
        *list = (*list)->prox;
        pos--;
    }
    return 1;
}
//Avança a lista até um nome
int avanca_lista_nome(Lista *list, char *name){
    if(lista_vazia(*list)) 
        return 0;
    Lista aux = *list;
    //Se nao for no inicio, o soldado com o nome deve estar para frente
    if(strcmp((*list)->prox->nomeSoldado, name)) {
        aux = (*list)->prox;
        while (aux->prox != (*list)->prox && strcmp(aux->prox->nomeSoldado, name)) 
            aux = aux->prox;
        //Soldado nao foi encontrado
        if(aux->prox == (*list)->prox) {
            return 0;
        }
        *list = aux;
    }
    return 1;
}
//Obtem o valor do elemento de uma lista no indice especificado
int obtem_valor_elem(Lista list, int indice, char *elem) {
    if(indice < 0 || lista_vazia(list))
        return 0;
    Lista aux = list->prox;
    while(indice > 0 && aux->prox != list->prox) {
        aux = aux->prox;
        indice--;
    }
    if(!indice) {
        strcpy(elem, aux->nomeSoldado);
        return 1;
    }
    return 0;
}