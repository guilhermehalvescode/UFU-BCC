#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "doador.h"

typedef struct doador
{
  char nome[30];
  char orgaos[5][30]; // matriz com cada orgao e o nome do beneficiado
} doador;

typedef struct no_doador
{
  struct doador info;
  struct no_doador * Prox;
} no_doador;

ListaDoadores cria_lista_doadores(){
  return NULL;
}

int vazia_doadores(ListaDoadores l){
  return l == NULL;
}

int tamanho_doadores(ListaDoadores l){
  /* 
  Retonar a quantidade de doadores na lista
  */
  // verifica se só tem 1 elemento
  if(l->Prox == l) return 1;
  int tam = 0;
  ListaDoadores aux = l;

  while (aux->Prox != l)
  {
    // percorre a lista aumentando o contador a cada iteração
    aux = aux->Prox;
    tam++;
  }
  
  return tam;
}

int inserir_doador(ListaDoadores *l, char nome[], int orgaos[]){
  /* 
  Recebe o nome do doador e um vetor de int do tamanho da quantidade de orgaos
  cada posicao deve vir com 0 ou 1, indicando se esta doando esse orgao ou nao
  */
  struct no_doador *N;
  N = (struct no_doador *) malloc(sizeof(struct no_doador));

  if(!N) return -1;
  strcpy(N->info.nome, nome);

  for (size_t i = 0; i < 5; i++)
  {
    if(orgaos[i]){
      // ta doando esse orgao
      N->info.orgaos[i][0] = '1';
    } else {
      // nao ta doando
      N->info.orgaos[i][0] = '0';
    }
  }
  // verifica se ta vazia
  if(vazia_doadores(*l)){
    // insere o primeiro elemento
    N->Prox = N;
    *l = N;

    return 1;
  }
  // insere no final
  N->Prox = (*l)->Prox;
  (*l)->Prox = N;
  *l = N;

  return 1;
}

int posicao_doador(ListaDoadores l, int pos, char nome[], char **orgaos){
  if (vazia_doadores(l) || pos < 0) return 0;

  ListaDoadores aux = l->Prox; // aponta para o primeiro

  while (pos > 0 && aux->Prox != l->Prox)
  { 
    aux = aux->Prox;
    pos--;
  }
  if(!pos){
    strcpy(nome, aux->info.nome);
    for (int i = 0; i < 5; i++)
    {
      strcpy(orgaos[i], aux->info.orgaos[i]);
    }

    return 1;
  }
  return 0;
}

int verifica_pacientes(ListaDoadores *l, char name[], int orgao){
  /* 
  Percorre a lista de pacientes verificando se existe algum
  doando o orgao necessario, se tiver, doa o orgao
  */
  if(vazia_doadores(*l)) return 0;

  ListaDoadores aux = (*l)->Prox; // aponta para o primeiro

  while (aux->Prox != (*l)->Prox)
  {   
    if(aux->info.orgaos[orgao][0] == '1'){    
      // tem o orgao disponivel
      // "doa" o orgao, e coloca o nome do paciente no lugar
      strcpy(aux->info.orgaos[orgao], name);

      return 1;
    }
    aux = aux->Prox;
  }

  if(aux->info.orgaos[orgao][0] == '1'){    
      // verifica o ultimo da lista
      strcpy(aux->info.orgaos[orgao], name);
    
      return 1;
    }
  return 0;
}