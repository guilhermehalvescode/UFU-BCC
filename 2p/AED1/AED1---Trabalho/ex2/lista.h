#ifndef LISTA_H
#define LISTA_H

typedef struct lista *Lista; 

#define max 20

void libera (Lista list);

Lista cria();

int vazia(Lista list);

int cheia(Lista list);

int inserir(Lista list, int value);

int remove_pares(Lista list);

int esvaziar(Lista list);

int maior(Lista list);

int tamanho(Lista list);

int posicao(Lista list, int pos);

Lista inverter(Lista list);

Lista intercalar(Lista l1, Lista l2);

#endif