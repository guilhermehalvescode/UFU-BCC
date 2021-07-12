#include <stdlib.h>
#include "deque.h"

struct deque
{
  struct no *beg;
  struct no *end;
};
struct no
{
  float info;
  struct no *prox;
  struct no *ant;
};
Deque cria_deque()
{
  Deque queue;
  queue = (Deque)malloc(sizeof(struct deque));
  if (queue)
  {
    queue->end = NULL;
    queue->beg = NULL;
  }
  return queue;
}
int deque_vazio(Deque queue) { return (!(queue->beg)); }

int push(Deque queue, float elem)
{
  struct no *q;
  q = (struct no *)malloc(sizeof(struct no));
  if (!q)
    return 0;
  q->info = elem;
  q->prox = NULL;
  q->ant = queue->end;
  if (deque_vazio(queue))
  {
    queue->beg = q;
  }
  else
  {
    queue->end->prox = q;
  }
  queue->end = q;
  return 1;
}
int unshift(Deque queue, float elem)
{
  struct no *q;
  q = (struct no *)malloc(sizeof(struct no));
  if (!q)
    return 0;
  q->info = elem;
  q->prox = queue->beg;
  q->ant = NULL;
  if (deque_vazio(queue))
  {
    queue->end = q;
  }
  else
  {
    q->prox = queue->beg;
    queue->beg->ant = q;
  }
  queue->beg = q;
  return 1;
}
int shift(Deque queue, float *elem)
{
  if (deque_vazio(queue))
    return 0;
  struct no *aux = queue->beg;
  *elem = aux->info;
  if (queue->beg == queue->end)
  {
    queue->end = NULL;
  }
  queue->beg = aux->prox;
  free(aux);
  return 1;
}
int pop(Deque queue, float *elem)
{
  if (deque_vazio(queue))
    return 0;
  struct no *aux = queue->end;
  *elem = aux->info;
  if (queue->beg == queue->end)
  {
    queue->beg = NULL;
  }
  queue->end = aux->ant;
  free(aux);
  return 1;
}
int libera_deque(Deque *queue)
{
  struct no *aux = (*queue)->beg;
  struct no *aux2;
  while (aux != NULL && aux->prox != NULL)
  {
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }
  (*queue)->beg = NULL;
  (*queue)->end = NULL;
  free(*queue);
  return 1;
}
int get_size(Deque queue)
{
  int qnt = 0;
  if (queue->beg == 0)
    return qnt;
  struct no *aux = queue->beg;
  while (aux->prox != NULL)
    qnt++;
  return qnt;
}