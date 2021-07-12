#include <stdlib.h>
#include <math.h>
#include "lista.h"
 
struct lista
{ 
  int lista[max];
  int fim;
}; 

void libera (Lista list)
{ 
  free(list); 
} 

Lista cria()
{ 
  Lista resultado = (Lista) malloc(sizeof(struct lista));

  if (!resultado){
    return NULL;
  }
  resultado->fim = 0;

  return resultado;
}

int vazia(Lista list)
{ 
  return (list->fim == 0);
}

int cheia(Lista list)
{ 
  return list->fim == max;
}

int inserir(Lista list, int value)
{ 
  if (vazia(list)){
    list->lista[0] = value;
    list->fim++;
    
    return 1;
  }

  if(!cheia(list)){
    for (size_t i = 0; i < list->fim; i++){
      if(value < list->lista[i]){
        for (size_t j = list->fim; j > i; j--)
        {
          list->lista[j] = list->lista[j-1];
        }
        list->lista[i] = value;
        list->fim++;

        return 1;
      }
    }
    // chegou aq, e pq e maior q qualquer um, adiciona no ultimo
    list->lista[list->fim] = value;
    list->fim++;

    return 1;
  } else {
    return 0;
  }
}

int remove_pares(Lista list)
{ 
  if (list->fim == 0)
    return 0;
  for (size_t i = list->fim-1; i > 0; i--)
  {
    if((list->lista[i] % 2) == 0.0){
      for (size_t j = i; j < list->fim; j++)
      {
        if(j + 1 != max){
          list->lista[j] = list->lista[j+1];
        }
      }
      list->fim--;
    }
  }
  return 1;
}

int maior(Lista list)
{ 
  int maior = list->lista[0];

  for (size_t i = 0; i < list->fim; i++)
  {
    if(list->lista[i] > maior)
      maior = list->lista[i];
  }

  return maior;
}

Lista intercalar(Lista l1, Lista l2)
{ 
  // Lista resultado = (Lista) malloc(sizeof(struct lista));
  Lista resultado = cria();

  if(resultado == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < l1->fim; i++)
  {
    inserir(resultado, l1->lista[i]);
  }

  for (size_t i = 0; i < l2->fim && (!cheia(resultado)); i++)
  {
    inserir(resultado, l2->lista[i]);
  }

  return resultado;
}

int tamanho(Lista list)
{ 
  return list->fim;
}

int esvaziar(Lista list)
{ 
  list->fim = 0;

  return 1;
}

int posicao(Lista list, int pos)
{ 
  if (pos < 0 || pos >= max){
    return 0;
  }
  if(pos >= list->fim){
    return 1;
  }

  return list->lista[pos];
}