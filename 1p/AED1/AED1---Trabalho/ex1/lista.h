#ifndef LISTA_H
#define LISTA_H

typedef struct lista *Lista; 

#define max 20

void libera (Lista list);

Lista cria();

int cheia(Lista list);

int inserir(Lista list, int value);

int remove_impares(Lista list);

int esvaziar(Lista list);

int menor(Lista list);

int tamanho(Lista list);

int posicao(Lista list, int pos);

Lista inverter(Lista list);

Lista concatenar(Lista l1, Lista l2);

#endif