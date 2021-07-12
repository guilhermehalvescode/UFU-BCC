#include <stdio.h>
#include <stdlib.h>

struct no {
    int item;
    struct no* Lista;
};

typedef struct no No;

int func (No *no) {
  if (no->prox == NULL) 
    return no->item;
  else if (no->item > func(no->prox)) 
            return no->item;
        else 
            return func(no->prox);             
}

