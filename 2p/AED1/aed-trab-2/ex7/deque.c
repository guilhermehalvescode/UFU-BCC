#include "deque.h"
#include <stdlib.h>
struct deque
{
  int no[max];
  int beg, count;
};
Deque cria_deque()
{
  Deque queue;
  queue = (Deque)malloc(sizeof(struct deque));
  if (queue)
  {
    queue->count = 0;
    queue->beg = 0;
  }
  return queue;
}

int deque_vazio(Deque queue)
{
  return (!queue->count);
}

int deque_cheio(Deque queue)
{
  return (queue->count == max);
}

int push(Deque queue, int elem)
{
  if (queue == NULL || queue->count == max)
    return 0;
  queue->no[(queue->beg + queue->count) % max] = elem;

  queue->count++;
  return 1;
}

int unshift(Deque queue, int elem)
{
  if (queue == NULL || queue->count == max)
    return 0;
  if (queue->beg != 0)
  {
    queue->no[queue->beg - 1] = elem;
    queue->beg--;
  }
  else
  {
    int aux[max] = {0}, j = 0;
    for (size_t i = queue->beg; i < queue->count; i++)
    {
      aux[j] = queue->no[i];
      j++;
    }
    queue->no[0] = elem;
    for (size_t i = 1; i < queue->count; i++)
      queue->no[i] = aux[i - 1];
    queue->beg = 0;
  }
  queue->count++;
  return 1;
}
int pop(Deque queue, int *elem)
{
  if (queue->count == 0 || !queue)
    return 0;
  *elem = queue->no[(queue->beg + queue->count) % max];
  queue->count--;
  return 1;
}
int shift(Deque queue, int *elem)
{
  if (queue == NULL || queue->count == 0)
    return 0;
  *elem = queue->no[queue->beg];
  queue->beg = (queue->beg + 1) % max;
  queue->count--;
  return 1;
}
int libera_deque(Deque *queue)
{
  for (size_t i = 0; i < max; i++)
    (*queue)->no[i] = 0;
  (*queue)->count = 0;
  (*queue)->beg = 0;
  free(*queue);
  return 1;
}
int get_size(Deque queue)
{
  return (queue->count);
}