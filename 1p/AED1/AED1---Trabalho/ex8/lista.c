/*
--Justificativa do aluno sobre a escolha do TAD--
    Para o tratamento de um polinomo, utilizei uma lista encadeada(devido a quantidade grande quantidade 
de remoções ao decorrer do programa), com o comportamento ordenado crescente(para organizar os polinomios 
conforme o grau do exponte de seus termos). Além da funções genéricas implementadas em aula,
escolhi implementar uma função que verifica se determinado elemento se encontra na lista,
o que auxilia verificar ao inserir um polinomio, se um de mesmo grau já existe, o que permite
realizar a soma entre esses dois. 
 */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
//estrutura para posicao de cada elemento
struct no {
    int expoente, coeficiente;
    struct no *prox;
};

//cria a lista devolvendo NULL para uma lista vazia
Lista cria_lista() {
    return NULL;
};
//verifica se a lista esta vazia olhando se o ponteiro da aplica��o aponta para NULL
int lista_vazia(Lista list) {
    return list == NULL;
}

//insere um elemento de forma ordenada na lista
int insere_ord(Lista *list, int expo, int coefic) {
    //aloca um no da lista
    Lista N = (Lista)malloc(sizeof(struct no));
    //verifica se a alocacao foi bem sucedida
    if (N == NULL)
        return 0;
    //insere um caractere em no
    N->expoente = expo;
    N->coeficiente = coefic;
    //verifica se o local de insercao e no inicio da lista
    if (lista_vazia(*list) || expo <= (*list)->expoente) {
        //faz o no criado apontar pro 1 no da lista
        N->prox = *list;
        //faz a lista apontar para o no atual
        *list = N;
        return 1;
    }
    //percorrendo lista
    Lista aux = *list; //faz aux apontar pro 1 no
    while (aux->prox != NULL && aux->prox->expoente < expo)
        aux = aux->prox; // avanca na lista
    //insere na lista
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

//remove um det elemento da lista
int remove_ord(Lista *list, int expo) {
    //se a lista estiver vazia e o elemento nao estiver no inicio
    //nao ha como remover
    if(lista_vazia(*list) || expo < (*list)->expoente)
        return 0;
    //ponteiro para o primeiro no
    Lista aux = *list;
    //remove o elemento se este estiver no inicio da lista
    if (expo == (*list)->expoente) {
        *list = aux->prox;
        free(aux);
        return 1;
    }
    //percorrendo lista
    while (aux->prox != NULL && aux->prox->expoente < expo)
        aux = aux->prox; // avanca na lista
    //verifica se o elemento nao esta na lista
    if (aux->prox == NULL || aux->prox->expoente > expo)
        return 0;
    //remove no da lista
    Lista aux2 = aux->prox; //aponta o no a ser removido
    aux->prox = aux2->prox; //retira no da lista
    free(aux2);             // libera memoria alocada
    return 1;
}

//inefeciente para consultas, pois para cada posicao
//deve percorter a lista novamente
//o melhor seria retorna um ponteiro para o vetor com os dados da lista
//obtem o valor na posicao indice da lista
int obtem_posicao(Lista list, int indice, int *expo, int *coefic) {
    //verifica se a lista e valida
    if (lista_vazia(list) || indice < 0)
        return 0;
    //percorrendo lista
    while (list != NULL && indice--)
        list = list->prox; // avanca na lista
    //verifica se chegou fora da lista
    if (list == NULL)
        return 0;
    //retorna o valor do no
    *expo = list->expoente;
    *coefic = list->coeficiente;
    return 1;
}

//procura um elemento na lista pelo seu valor
int obtem_valor(Lista list, int expo, int *coefic) {
    if(lista_vazia(list) || expo < list->expoente)
        return 0;
    while(list != NULL && list->expoente < expo)
        list = list->prox;
    if(list == NULL || list->expoente > expo)
        return 0;
    *coefic = list->coeficiente;
    return 1;
}

//limpa a lista
int limpa_lista(Lista *list) {
    //inicializa aux com o inicio da lista
    Lista aux = *list, aux2;
    //libera os elementos conforme percorre a lista
    while (aux != NULL) {
        aux2 = aux->prox; //variavel auxiliar
        free(aux);        //libera o no na lista
        aux = aux2;       //passa para o proximo no
    }
    //a lista e limpada, entao ela aponta pra NULL
    *list = NULL;
    return 1;
}