#include <stdio.h>
#include <stdlib.h>

struct no {
   int valor;
   struct no* ant;
   struct no* prox;
};

typedef struct no No;
typedef struct no* Lista;
void insere_lista_duplamente_encadeada(Lista *li, int v){
    if(*li != NULL) {
        Lista q = *li;
        while(q->prox != NULL) {
            if(q->valor == v)
                return;
            q = q->prox;
        }
    }
  struct no* novo;
  novo = (No*) malloc (sizeof(No));
  novo->valor = v;
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

void imprime(Lista *li){
   if (li == NULL)
      printf("\nLista Vazia");
   else{
      No *aux;
      aux = *li;
      while(aux != NULL){
          printf("%d ",aux->valor);
          aux = aux->prox;
      }
   }
}

int main(void) {
  Lista* lista;
  lista = (Lista*) malloc (sizeof(Lista));
  *lista = NULL;
  insere_lista_duplamente_encadeada(lista,5);
  insere_lista_duplamente_encadeada(lista,6);
  insere_lista_duplamente_encadeada(lista,7);
  insere_lista_duplamente_encadeada(lista,6);
  insere_lista_duplamente_encadeada(lista,7);
  printf("\nImpressão: ");
  imprime(lista);
}