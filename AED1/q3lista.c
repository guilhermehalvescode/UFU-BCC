#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
    int info;
    struct no* prox;
};

Lista cria_lista() {
    Lista no;
    no = (Lista) malloc(sizeof(struct no));
    if(no != NULL) {
        no->info = 0;
        no->prox = NULL;
    }
    return no;
}

int lista_vazia(Lista list) {
    return list->prox == NULL;
}

int libera_lista(Lista *lst) {
  if (lst == NULL)
    return 1;
  Lista aux = (*lst)->prox;
  Lista aux2;
  while (aux != NULL) {
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }
  (*lst)->info = 0;
  return 1;
}

int insere_ord(Lista *lst, int elem) {
  Lista N = (Lista)malloc(sizeof(struct no));
  if (N == NULL)
    return 0;
  N->info = elem;

  Lista aux = *lst;
  while (aux->prox != NULL && aux->prox->info < elem)
    aux = aux->prox;
  N->prox = aux->prox;
  aux->prox = N;
  (*lst)->info++;
  return 1;
}

int intercalar(Lista *lista1, Lista *lista2, Lista *lista3) {
  if (((*lista1)->info == 0 || (*lista1)->prox == NULL) || ((*lista2)->info == 0 || (*lista2)->prox == NULL))
    return 0;

  Lista maior;
  Lista menor;
  if ((*lista1)->info > (*lista2)->info) {
    menor = (*lista2)->prox;
    maior = (*lista1)->prox;
  } else {
    menor = (*lista1)->prox;
    maior = (*lista2)->prox;
  }
  int flag = 1;
  while (menor != NULL) {
    if (!insere_ord(lista3, menor->info) || !insere_ord(lista3, maior->info)) {
      flag = 0;
      libera_lista(lista3);
      return flag;
    }
    menor = menor->prox;
    maior = maior->prox;
  }
  while (maior != NULL) {
    if(!insere_ord(lista3, maior->info)) {
      flag = 0;
      libera_lista(lista3);
      return flag;
    }
    maior = maior->prox;
  }
  return 1;
}