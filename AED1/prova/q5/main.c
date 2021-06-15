#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct no {
   int vidas;
   char nome[10];
   float distancia;
   struct no* ant;
   struct no* prox;
};
typedef struct no No;
typedef struct no* Lista;
void insere_lista_de(Lista *li, int v, char *n, float a){
  struct no* novo;
  novo = (No*) malloc (sizeof(No));
  novo->vidas = v;
  novo->distancia = a;
  strcpy(novo->nome,n); 
  if(*li == NULL){
    novo->ant = NULL;
    novo->prox = NULL;
  } else{ 
    novo->prox = *li;
    novo->ant= NULL;
    (*li)->ant = novo;
  }
  *li = novo;    
}


int removeplayer(Lista *dEnc) {
  if ((*dEnc) == NULL)
    return 0;
  if ((*dEnc)->prox == NULL)
  {
    free(*dEnc);
    (*dEnc) = NULL;
    return 1;
  }
  Lista aux = (*dEnc);
  Lista menorRef = (*dEnc);
  while (aux->prox != NULL) {
    if(aux->distancia < menorRef->distancia) 
       menorRef = aux;
    aux = aux->prox; 
  }
  if(aux->distancia < menorRef->distancia) {
      menorRef = aux;
  }
  menorRef->ant->prox = menorRef->prox;
  menorRef->prox->ant = menorRef->ant;
  free(menorRef);
  return 1;
}

void imprime(Lista *li){
   if (li == NULL)
      printf("\nLista Vazia");
   else{
      No *aux;
      aux = *li;
      while(aux != NULL){
          printf("\n%3d \t%s \t%f",aux->vidas, aux->nome, aux->distancia);
          aux = aux->prox;
      }
   }
}
int main(void) {
  Lista* lista;
  lista = (Lista*) malloc (sizeof(Lista));
  *lista = NULL;
  insere_lista_de(lista,100,"hackr",6.33);
  insere_lista_de(lista,60,"gamr",7.2);
  insere_lista_de(lista,70,"strkid",10.7);
  insere_lista_de(lista,110, "jog1",9.65);
  removeplayer(lista);
  printf("\nLista de ataques: \nVidas \tJogador \tDistancia");
  imprime(lista);
}