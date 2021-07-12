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

int cheia(Lista list)
{ 
  return list->fim == max;
}

int inserir(Lista list, int value)
{ 
  if(!cheia(list)){
    list->lista[list->fim] = value;
    list->fim++;

    return 1;
  } else {
    return 0;
  }
}

int remove_impares(Lista list)
{ 
  if (list->fim == 0)
    return 0;
    
  for (size_t i = list->fim-1; i > 0; i--)
  {
    if((list->lista[i] % 2) != 0.0){
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

int menor(Lista list)
{ 
  int menor = list->lista[0];

  for (size_t i = 0; i < list->fim; i++)
  {
    if(list->lista[i] < menor)
      menor = list->lista[i];
  }

  return menor;
}

Lista inverter(Lista list)
{ 
  Lista resultado = (Lista) malloc(sizeof(struct lista));

  if(resultado == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < list->fim; i++)
  {
    resultado->lista[i] = list->lista[list->fim-1-i];
  }
  resultado->fim = list->fim;

  return resultado;
}

Lista concatenar(Lista l1, Lista l2)
{ 
  // Lista resultado = (Lista) malloc(sizeof(struct lista));
  Lista resultado = cria();

  if(resultado == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < l1->fim; i++)
  {
    resultado->lista[i] = l1->lista[i];
    resultado->fim++;
  }

  for (size_t i = 0; i < l2->fim && (!cheia(resultado)); i++)
  {
    resultado->lista[resultado->fim] = l2->lista[i];
    resultado->fim++;
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
    //posicao fora do escopo[0, 19]
    return 0;
  }
  if(pos >= list->fim){
    // lixo da memória
    return 1;
  }

  return list->lista[pos];
}