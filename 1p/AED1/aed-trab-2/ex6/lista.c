#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
 
#define max 20

typedef struct paciente
{
  char nome[30];
  int idade, grau, orgao;
} paciente;

struct no
{ 
  paciente info;
  struct no *prox;
}; 

Fila cria()
{ 
  return NULL;
}

int vazia(Fila fil)
{ 
  return fil == NULL;
}

int esvaziar(Fila *fil)
{ 
  if(vazia(*fil)) return 1;

  Fila aux = *fil, aux2;

  do {
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
  } while (aux != *fil);
  *fil = NULL;

  return 1;
}

int inserir(Fila *fil, char nome[], int idade, int orgao, int grau)
{ 
  struct no *N;
  N = (struct no *) malloc(sizeof(struct no));

  if (N == NULL) return 0;

  strcpy(N->info.nome, nome);
  N->info.orgao = orgao;
  N->info.idade = idade;
  N->info.grau = grau;

  if(vazia(*fil)){
    // insere o primeiro elemento
    N->prox = N;
    *fil = N;
  } else {
    // verifica se é maior que o primeiro
    // se for, insere no inicio
    if((*fil)->prox->info.grau <= grau){
      N->prox = (*fil)->prox;
      (*fil)->prox = N;

      return 1;
    }
    // percorre a fila pra inserir descrescente com base no grau
    Fila aux = (*fil)->prox; // aponta para o começo

    while (aux != *fil && aux->prox->info.grau > grau)
      // enquanto for diferente do ultimo e o grau maior que o desejado
      aux = aux->prox;
    
    if (aux == *fil){
      // se chegou no final, e pq o novo registro é o 
      // menor de todos, inserir no final
      N->prox = (*fil)->prox;
      (*fil)->prox = N;
      *fil = N;

      return 1;
    }
    N->prox = aux->prox;
    aux->prox = N;
  }

  return 1;
}

int remover_inicio(Fila *fil, char nome[], int *idade, int *orgao, int *grau)
{ 
  if(vazia(*fil)) return 0;

  struct no *aux = (*fil)->prox; // aponta para o primeiro

  strcpy(nome, aux->info.nome);
  *orgao = aux->info.orgao;
  *idade = aux->info.idade;
  *grau = aux->info.grau;

  // verificar se so tem 1 elemento na lista
  if(aux == *fil){
    *fil = NULL;
  } else {
    (*fil)->prox = aux->prox; // ultimo aponta para o segundo, removendo o primeiro
  }
  
  free(aux);

  return 1;
}