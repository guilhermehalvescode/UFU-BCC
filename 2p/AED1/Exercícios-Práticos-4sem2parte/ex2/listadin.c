#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadin.h"

struct info {
    unsigned int matricula;
    char nome[20];
    float media;
    int faltas;
};

int valida(char *nome, float media, int faltas) {
    return strlen(nome) > 19 || media < 0 || faltas < 0;
}

//estrutura para posicao de cada elemento
struct no {
    struct info aluno; 
    struct no* prox;
};
//cria a lista devolvendo NULL para uma lista vazia
Lista inicializar_lista() {
    return NULL;
};
//verifica se a lista esta vazia olhando se o ponteiro da aplica��o aponta para NULL
int lista_vazia(Lista list) {
    return list == NULL;
}

//insere um elemento no comeco da lista
int insere_elem(Lista *list, unsigned int matricula, char *nome, float media, int faltas) {
    //aloca um no da lista
    if(valida(nome, media, faltas)) 
        return 0;

    Lista N = (Lista) malloc(sizeof(struct no));
    //verifica se a alocacao foi bem sucedida
    if(N == NULL)
        return 0;
    //insere um aluno no no
    N->aluno.matricula = matricula;
    strcpy(N->aluno.nome, nome);
    N->aluno.media = media;
    N->aluno.faltas = faltas;
    //insere a posicao para o proximo elemento da lista
    N->prox = *list;
    //passa para a aplicacao o endereco do inicio da lista
    *list = N;
    //sucesso, retorna flag 1
    return 1;
}

//remove um det elemento da lista
int remove_elem(Lista *list, unsigned int matricula) {
    //se a lista estiver vazia nao ha como remover
    if(lista_vazia(*list))
        return 0;
    //ponteiro para o primeiro no
    Lista aux = *list;
    //remove o elemento se este estiver no inicio da lista
    if(matricula == (*list)->aluno.matricula) {
        *list = aux->prox;
        free(aux);
        return 1;
    }
    //percorrendo lista
    while(aux->prox != NULL && aux->prox->aluno.matricula != matricula)
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
int get_pos(Lista list, int indice, unsigned int *matricula, char *nome, float *media, int *faltas) {
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
    *matricula = list->aluno.matricula;
    strcpy(nome, list->aluno.nome);
    *media = list->aluno.media;
    *faltas = list->aluno.faltas;
    return 1;
}

int size_lista(Lista list) {
    int tam = 0;
    if(lista_vazia(list))
        return tam;
    while(list != NULL) {
        list = list->prox;
        tam++;
    }
    return tam;
}