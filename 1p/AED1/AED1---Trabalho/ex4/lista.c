#include "lista.h"
#include <stdlib.h>
struct lista
{
  char info;
  struct lista *prox;
};

Lista cria_lista()
{
  Lista cab = (Lista)malloc(sizeof(struct lista));
  if (!cab)
  {
    cab->prox = NULL;
    cab->info = 0;
  }
  return cab;
}
int lista_vazia(Lista *lst) { return ((*lst)->prox == NULL); }
int insere_ord(Lista *lst, char elem)
{
  Lista N = (Lista)malloc(sizeof(struct lista));
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
int remove_ord(Lista *lst, char elem)
{
  if (((*lst)->info == 0) /*|| elem < (*lst)->info*/)
    return 0;

  Lista aux = (*lst)->prox;
  while (aux->prox != NULL && aux->prox->info < elem)
    aux = aux->prox;
  if (aux->prox == NULL || aux->prox->info > elem)
    return 0;
  Lista aux2 = aux->prox;
  aux->prox = aux2->prox;
  free(aux2);
  return 1;
}
int remove_pos(Lista *lst, int pos, char *retorno)
{
  if (((*lst)->info == 0) || (pos > (*lst)->info))
    return 0;
  Lista aux = (*lst);
  while (pos--)
    aux = aux->prox;
  if (aux->prox == NULL)
    return 0;
  Lista aux2 = aux->prox;
  aux->prox = aux2->prox;
  *retorno = aux2->info;
  free(aux2);
  return 1;
}
int esvazia_lista(Lista *lst)
{
  if (lst == NULL)
    return 1;
  Lista aux = (*lst)->prox;
  Lista aux2;
  while (aux != NULL)
  {
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }
  (*lst)->info = 0;
  return 1;
}
int obtem_valor_elem(Lista *lst, int index, char *result)
{
  if (((*lst)->info == 0) || index < 0 || index > (*lst)->info)
    return 0;
  Lista aux = (*lst)->prox;
  while (aux != NULL && index--)
    aux = aux->prox;
  if (aux == NULL)
    return 0;
  *result = aux->info;
  return 1;
}

int obtem_tamanho(Lista *lst) { return ((*lst)->info); }

int listas_iguais(Lista *lst1, Lista *lst2)
{
  if ((*lst1)->info != (*lst2)->info)
    return 0;
  int tam = (*lst1)->info;

  Lista aux1 = (*lst1)->prox;
  Lista aux2 = (*lst2)->prox;
  while (tam--)
  {
    if (aux1->info != aux2->info)
      break;
    aux1 = aux1->prox;
    aux2 = aux2->prox;
  }
  if (tam > 0)
    return 0;
  return 1;
}
int maior_elem(Lista *lst, char *result)
{
  if ((*lst)->info == 0)
    return 0;
  int tam = (*lst)->info;
  Lista aux = (*lst)->prox;
  *result = aux->info;
  while (tam--)
  {
    if (aux->info > (*result))
      *result = aux->info;
    aux = aux->prox;
  }
  return 1;
}
int intercalar(Lista *lst1, Lista *lst2, Lista *lst3)
{
  if (((*lst1)->info == 0 || (*lst1)->prox == NULL) || ((*lst2)->info == 0 || (*lst2)->prox == NULL))
    return 0;

  Lista auxMaior;
  Lista auxMenor;
  if ((*lst1)->info > (*lst2)->info)
  {
    auxMenor = (*lst2)->prox;
    auxMaior = (*lst1)->prox;
  }
  else
  {
    auxMenor = (*lst1)->prox;
    auxMaior = (*lst2)->prox;
  }
  int flag = 1;
  while (auxMenor != NULL)
  {
    if (!insere_ord(lst3, auxMenor->info) || !insere_ord(lst3, auxMaior->info))
    {
      flag = 0;
      esvazia_lista(lst3);
      return flag;
    }

    auxMenor = auxMenor->prox;
    auxMaior = auxMaior->prox;
  }
  while (auxMaior != NULL)
  {
    if (insere_ord(lst3, auxMaior->info))
    {
      flag = 0;
      esvazia_lista(lst3);
      return flag;
    }
    auxMaior = auxMaior->prox;
  }
  return 1;
}