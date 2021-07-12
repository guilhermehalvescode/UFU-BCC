#include <stdlib.h>
#include "lista.h"
//Estrutura para posicao de cada elemento
struct no
{
  double info;
  struct no *prox;
};
//Cria a lista
Lista cria_lista() { return NULL; }
//Verifica se a lista esta vazia
int lista_vazia(Lista *lst) { return (*lst) == NULL; }
//Insere um elemento no final da lista
int insere_final(Lista *lst, double elem)
{
  Lista N = (Lista)malloc(sizeof(struct no));
  if (N == NULL)
    return 0;
  N->info = elem;
  if (lista_vazia(lst))
  {
    N->prox = N;
    *lst = N;
  }
  else
  {
    N->prox = (*lst)->prox;
    (*lst)->prox = N;
    *lst = N;
  }
  return 1;
}
//Insere um elemento no início de uma lista
int insere_inicio(Lista *lst, double elem)
{
  Lista N = (Lista)malloc(sizeof(struct no));
  if (N == NULL)
    return 0;
  N->info = elem;
  if (lista_vazia(lst))
  {
    N->prox = N;
    *lst = N;
  }
  else
  {
    N->prox = (*lst)->prox;
    (*lst)->prox = N;
  }
  return 1;
}
//Remove um elemento do início da lista
int remove_inicio(Lista *lst, double *elem)
{
  if (lista_vazia(lst))
    return 0;
  Lista aux = (*lst)->prox;
  *elem = aux->info;
  if (*lst == (*lst)->prox)
    *lst = NULL;
  else
    (*lst)->prox = aux->prox;
  free(aux);
  return 1;
}
//Remove um elemento do fim da lista
int remove_final(Lista *lst, double *elem)
{
  if (lista_vazia(lst))
    return 0;
  *elem = (*lst)->info;
  Lista aux = (*lst)->prox;
  if (*lst == (*lst)->prox)
  {
    *lst = NULL;
    free(aux);
  }
  else
  {
    while (aux->prox->prox != (*lst)->prox)
      aux = aux->prox;
    aux->prox = (*lst)->prox;
    free(*lst);
    *lst = aux;
  }
  return 1;
}
//Obtem o valor do elemento de uma lista no indice especificado
int obtem_valor_elem(Lista *lst, int indice, double *elem)
{
  if (indice < 0 || lista_vazia(lst))
    return 0;
  Lista aux = (*lst)->prox;
  while (indice > 0 && aux->prox != (*lst)->prox)
  {
    aux = aux->prox;
    indice--;
  }
  if (!indice)
  {
    *elem = aux->info;
    return 1;
  }
  return 0;
}
//Retorna o tamanho da lista
int lista_tam(Lista *lst)
{
  if (lista_vazia(lst))
    return 0;
  int cont = 1;
  Lista aux = (*lst)->prox;
  while (aux->prox != (*lst)->prox)
  {
    aux = aux->prox;
    cont++;
  }
  return cont;
}
//Insere em determinada posição
int insere_pos(Lista *lst, int index, double elem)
{
  if (index < 0 || lista_vazia(lst) || index >= lista_tam(lst))
    return 0;
  //Daqui pra frente existe a posição da lista que deseja-se colocar
  Lista N = (Lista)malloc(sizeof(struct no));
  if (N == NULL)
    return 0;
  N->info = elem;
  N->prox = NULL;
  Lista aux = (*lst)->prox;
  while (index--)
    aux = aux->prox;
  N->prox = aux->prox;
  aux->prox = N;
  return 1;
}
//Remove em determinda posição
int remove_pos(Lista *lst, int index, double *elem)
{
  if (lista_vazia(lst))
    return 0;
  //Percorro até a posição pos
  while (index > 0)
  {
    *lst = (*lst)->prox;
    index--;
  }
  //Retorna o nome removido
  *elem = (*lst)->prox->info;
  Lista aux2 = (*lst)->prox;
  (*lst)->prox = aux2->prox;
  free(aux2);
  return 1;
}
//Obtem o maior elemento da lista
int maior_elem(Lista *lst, double *elem)
{
  if (lista_vazia(lst))
    return 0;
  int maior = (*lst)->info;
  Lista aux = (*lst)->prox;
  while (aux->prox != (*lst)->prox)
  {
    if (aux->info > maior)
      maior = aux->info;

    aux = aux->prox;
  }
  *elem = maior;
  return 1;
}