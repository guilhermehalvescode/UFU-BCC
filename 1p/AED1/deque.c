#include <stdlib.h>
#include <stdio.h>
#include "deque.h"
#define MAX 20

struct deque
{
  int no[max];
  int beg, fim;
};

Deque cria_deque()
{
  Deque deque;
  deque = (Deque)malloc(sizeof(struct deque));
  if (deque)
  {
    deque->beg = 0;
    deque->fim = 0;
  }
  return deque;
}

int deque_vazia(Deque deq) {
    return deq->beg == deq->fim;
}

int deque_cheia(Deque deq) {
    return deq->beg == (deq->fim + 1) % MAX;
}